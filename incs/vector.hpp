/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/13 17:31:11 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "./reverse_iterator.hpp"
#include "./iterator_vector.hpp"
#include "./iterator_traits.hpp"
#include "./is_integral.hpp"
#include "./equal.hpp"
#include "./enable_if.hpp"
#include "./lexicographical_compare.hpp"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////---------------------------- VECTOR IS A SEQUENCE CONTAINER AND KNOWN AS A DYNAMIC ARRAY ------------------------------------- /////////
////// sequence containers refer to a group of container class templates in STL of C++ that implement storage of _current elements	 /////////
////// deque and list are also sequence container																					/////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace ft 
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T																							value_type;
			typedef Allocator																					allocator_type;
    		typedef typename Allocator::size_type       														size_type;
    		typedef typename Allocator::difference_type 														difference_type;
			typedef	typename Allocator::reference																reference;
			typedef	typename Allocator::const_reference															const_reference;
    		typedef typename Allocator::pointer         														pointer;
    		typedef typename Allocator::const_pointer   														const_pointer;
			typedef ft::my_iterator<value_type, difference_type, pointer, reference>							iterator;
			typedef ft::my_iterator<value_type, difference_type, const_pointer, const_reference>				const_iterator;
			typedef ft::reverse_iterator<iterator>																reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>														const_reverse_iterator;

		private:
			Allocator			_alloc;
			pointer				_arr;   //begin, pointer on array
			size_type			_size; 	//end = number of elements
			size_type			_capacity;	//size of allocated storage
			
		public:
			//default constructor
			explicit vector(const Allocator& alloc = allocator_type()): _alloc(alloc)
			{
				_arr = NULL;
				_size = 0;
				_capacity = 0;
			}
			//fill constructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				_size = n;
				_capacity = n;
				_arr = _alloc.allocate(_capacity);
				for(size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, val);
				}
			}
			//Range constructor : if during compilation type is not defined by enable_if, this function will be ignored without sending error back
			template <class InputIterator> 
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				std::ptrdiff_t	size = std::distance(first, last);

				_arr = NULL;
				_size = 0;
				_capacity = size;
				
				_arr = _alloc.allocate(size);
				for(std::ptrdiff_t i = 0; i < size; i++)
				{
					_alloc.construct(_arr + i, *(first++));
					_size++;
				}
			}
			//copy constructor
			vector(const vector &other): _alloc(other._alloc)
			{
				_size = other.size();
				_capacity = other._size;
				_arr = _alloc.allocate(_capacity);
				for(size_type i = 0; i < _size; i++)
				{
					_alloc.construct(_arr + i, other._arr[i]);
				}
			}	
			//destructor
			~vector(void)
			{
				for(size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _capacity);
			}

			vector & operator=(const vector &other) 
			{
				if(this == &other)
					return (*this);
					
				clear();
				if(_alloc != other._alloc)
				{
					_alloc.deallocate(_arr, _capacity);
					_capacity = 0;
					_arr = NULL;
					_alloc = other._alloc;
				}
				_capacity = other._capacity;
				_arr = _alloc.allocate(_capacity);
				for(size_type i = 0; i < _capacity; i++)
				{
					_alloc.construct(_arr + i, other._arr[i]);
					_size++;
				}
				return (*this);
			}
			reference operator[](size_type n) { return (_arr[n]); }
			const_reference operator[](size_type n) const { return (_arr[n]); }
			////////////////////////////////////    VECTOR MEMBER FUNCTIONS   ////////////////////////////////////////////
			////////   ASSIGN    //////////
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value::type>)
			{
				std::ptrdiff_t	size_btw_it = std::distance(first, last);

				for(size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_arr + i);
				}
				_capacity = size_btw_it;
				if (_size < _capacity)
				{
					reserve(size_btw_it);
					_size = size_btw_it;
				}
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(_arr + i, (first + i));
			}
			void assign(size_type n, const value_type& val)
			{
				try
				{
					if(n < _size)//if size smaller than n, suppr the extra
					{
						for(size_type i = 0; i < n; i++)
							_alloc.construct(_arr + i, val);
						for(size_type j = n; j < _size; j++)
							_alloc.destroy(_arr + j);
						_size = n;
					}
					else if(n > _capacity)//if capacity too low reallocate
					{
						reserve(n);
						_size = _capacity;
					}
				}
				catch(const std::length_error& e)
				{
					throw std::length_error("vector");
				}
			}
			////////   AT    //////////
			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw  std::out_of_range("Out of range");
				else
					return (_arr[n]);
			}
			const_reference at(size_type n) const
			{
				if (n < 0 || n >= _size)
					throw  std::out_of_range("Out of range");
				else
					return (_arr[n]);
			}
			////////   BACK    //////////
			reference back() { return (_arr[_size - 1]); }
			const_reference back() const { return (_arr[_size - 1]); }
			////////   BEGIN    //////////
			// iterator begin() { return (_arr); }
			iterator begin() { return (iterator(_arr)); }
			const_iterator begin() const { return (const_iterator(_arr)); }
			////////   CAPACITY    //////////
			size_type capacity() const { return (_capacity); }
			////////   CLEAR    //////////
			void clear()
			{
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, _capacity);
				_size = 0;
			}
			////////   EMPTY   //////////
			bool empty() const
			{
				if(_size == 0)
					return (true);
				return (false);
			}
			////////   END   //////////
			iterator end() { return (iterator(_arr + _size)); }
			const_iterator end() const { return (const_iterator(_arr + _size)); }
			////////   ERASE    //////////
			iterator erase (iterator position)
			{
				size_type index = position - this->begin();
				
				_alloc.destroy(_arr + index);
				_size--;
				for(size_type i = index; i < _size; i++)
				{
					_alloc.construct(_arr + i, *(_arr + i + 1));
					_alloc.destroy(_arr + index + 1);	
				}
				return (position);
			}
			// begin at index and destroy then construct one by one
			iterator erase (iterator first, iterator last)
			{
				size_type diff = last - first;
				size_type index = first - this->begin();
				size_type new_size;
				
				new_size = *(_arr + index + diff);
				if(_size == 0)
					return (last);
				_alloc.destroy(_arr + index);
				for(size_type i = index; i < new_size; i++)
				{
					_alloc.construct(_arr + i, *(_arr + i + diff));
					_alloc.destroy(_arr + index + 1);
				}
				_size -= diff;
				for(int i = new_size; i < *(_arr + _size); i++)
				{
					_alloc.destroy(_arr + i);
				}
				return (first);
			}
			////////   FRONT   //////////
			reference front(){ return (_arr[0]); }
			const_reference front() const { return (_arr[0]); }
			////////   GET ALLOCATOR    //////////
			allocator_type get_allocator() const { return (this->_alloc); }
			////////   INSERT    //////////
			iterator insert(iterator position, const value_type& val)
			{
				return (insert(position, 1, val));
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				(void)position;
				(void)n;
				(void)val;
			}
			template<class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				(void)position;
				(void)first;
				(void)last;
			}
			////////   MAX SIZE    //////////
			size_type max_size() const { return (_alloc.max_size()); }
			////////   POP BACK    //////////
			void pop_back()
			{
				_alloc.destroy(_arr + (_size - 1));
				_size--;
			}
			////////   PUSH BACK    //////////
			void	push_back(const value_type& value)
			{
				if (_size == 0)
				{
					reserve(size() + 1);
					_alloc.construct(_arr + _size, value);
					_size++;
				}
				else if(_size < _capacity)
				{
					_alloc.construct(_arr + _size, value);
					_size++;
				}
				else if (_size == _capacity)
				{
					_capacity = _capacity * 2;
					move_arr(_capacity); // move array to deallocate old arr
					_alloc.construct(_arr + _size, value);
					_size++;
				}
			}

			void	move_arr(size_type new_capacity)
			{
				value_type	*new_arr;

				new_arr = _alloc.allocate(new_capacity);
				for(size_type i = 0; i < _size; i++)
				{
					_alloc.construct(new_arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, _capacity);
				_arr = new_arr;
				_capacity = new_capacity;
			}
			////////   RBEGIN   //////////
			reverse_iterator rbegin() { return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
			////////   REND   //////////
			reverse_iterator rend() { return reverse_iterator(begin()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };
			
			////////   RESERVE   //////////
			void reserve (size_type new_cap)
			{
				if(new_cap > _capacity)
				{
					if(new_cap > max_size())
						throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
					_capacity = new_cap;
					_arr = _alloc.allocate(_capacity);
				}
				else
					return;
			}
			////////   RESIZE   //////////
			void resize (size_type n, value_type val = value_type())
			{
				value_type	*new_arr;
				size_type	new_capacity;
				
				try
				{
					if (n == _size)
						return ;
					else if(n < _size)
					{
						new_capacity = _capacity;
						new_arr = _alloc.allocate(new_capacity);
						for(size_type i = 0; i < n; i++)
						{
							_alloc.construct(new_arr + i, _arr[i]);						
							_alloc.destroy(_arr + i);
						}
						_alloc.destroy(_arr);
						_alloc.deallocate(_arr, _capacity);
						_arr = new_arr;
						_size = n;
					}
					else if (n > _size)
					{
						if (n > _capacity)
							new_capacity = n;
						else
							new_capacity = _capacity;
						new_arr = _alloc.allocate(new_capacity);
						for(size_type i = 0; i < _size; i++)
							_alloc.construct(new_arr + i, _arr[i]);
						for(size_type i = _size; i < n; i++)
						{
							_alloc.construct(new_arr + i, val);
							_size++;
						}
					}
					_capacity = new_capacity;
				}
				catch(const std::bad_alloc& e)
				{
					throw ;
				}
				catch(const std::length_error& e)
				{
					throw std::length_error("vector");
				}
			}	
			////////   SIZE   //////////
			size_type size() const { return (_size); }
			////////   SWAP   //////////
			void swap(vector& other)
			{
            	allocator_type	alloc;
            	pointer			arr;
				size_type		size;
				size_type		capacity;
				
				if (this == &other)
                	return;
				
            	alloc = other._alloc;
            	arr = other._arr;
				size = other._size;
				capacity = other._capacity;
	
				other._alloc = _alloc;
            	other._arr = _arr;
            	other._size = _size;
				other._capacity = _capacity;

				_alloc = alloc;
            	_arr = arr;
            	_size = size;
				_capacity = capacity;
			}				
	};
	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		size_t size;
		
		size = lhs.size();
		if(lhs.size() != rhs.size())
			return (false);
		else
		{
			for(size_t i = 0; i < size; i++)
			{
				if(*(lhs.begin() + i) != *(rhs.begin() + i))
					return (false);
			}
		}
		return (true);
	}
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}
	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
}

#endif