/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/19 11:34:37 by dvallien         ###   ########.fr       */
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
					_alloc.construct(_arr + i, val);
			}
			//Range constructor : if during compilation type is not defined by enable_if, this function will be ignored without sending error back
			template <class InputIterator> 
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
			{
				std::ptrdiff_t	size = std::distance(first, last);

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
					_alloc.destroy(_arr + i);
				_alloc.deallocate(_arr, _capacity);
			}
			//operator =
			vector & operator=(const vector &other) 
			{
				// if(this == &other)
				// 	return (*this);
				clear();
				reserve(other._size);
				_size = other._size;
				for(size_type i = 0; i < other._size; i++)
					_alloc.construct((_arr + i), (other._arr[i]));
				return (*this);
			}
			reference operator[](size_type n) { return (_arr[n]); }
			const_reference operator[](size_type n) const { return (_arr[n]); }
			////////////////////////////////////    VECTOR MEMBER FUNCTIONS   ////////////////////////////////////////////
			////////   ASSIGN    //////////
			template <class InputIterator>
			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				std::ptrdiff_t	size_it = std::distance(first, last);
				
				clear();
				reserve(size_it);
				for (ptrdiff_t i = 0; i < size_it; i++)
					_alloc.construct(_arr + i, *(first + i));
				_size = size_it;
			}
			void assign(size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				for(size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, val);
				_size = n;
			}
			////////   AT    //////////
			reference at(size_type n)
			{
				if (n < 0 || n >= _size)
					throw;
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
				for(size_type i = 0; i < _size; i++)
					_alloc.destroy(_arr + i);
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
			iterator erase (iterator first, iterator last)
			{
				ptrdiff_t		size_it = std::distance(first, last);
				size_type index = first - this->begin();
				size_type new_size;
				
				new_size = _size - size_it;
				if(_size == 0)
					return (last);
				_alloc.destroy(_arr + index);
				for(size_type i = index; i < new_size; i++)
				{
					_alloc.construct(_arr + i, *(_arr + i + size_it));
					_alloc.destroy(_arr + index + 1);
				}
				for(int i = new_size; i < *(_arr + _size); i++)
					_alloc.destroy(_arr + i);
				_size = new_size;
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
				size_type	index = position - this->begin();
				size_type	end = _size;
				
				if (index > end || index < 0)
					throw std::out_of_range("Can't insert outside vector");
				if(_size == 0)
				{
					this->push_back(val);
					return (iterator(_arr + index));				
				}
				_size++;
				reserve(_size);
				while(end >= index)
				{
					_alloc.construct(_arr + end + 1, _arr[end]);
					_alloc.destroy(_arr + end);
					if(end == 0)
						break;
					end--;
				}
				_alloc.construct(_arr + index, val);
				return (iterator(_arr + index));
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type	new_size = _size + n;
				size_type	index = position - this->begin();
				
				if (position < begin()|| position > end())
					throw std::out_of_range("Invalid iterator position");
				if(_size == 0)
				{
					reserve(n);
					for(size_type i = 0; i < n; i++)
						this->push_back(val);
					return;				
				}
				reserve(new_size);
				for(size_type i = _size; i > index + n; i--)
				{
					_alloc.construct(_arr + i, *(_arr + i - n));
					_alloc.destroy(_arr + i - n);
				}
				for(size_type i = 0; i < n; i++)
				{
					_alloc.construct(_arr + index + i, val);
				}
				_size += n;
			}
			template<class InputIterator>
			void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				if (position < begin() || position > end())
					throw std::out_of_range("Invalid iterator position");
				if (first > last)
					throw std::out_of_range("Invalid range");
					
				ft::vector<typename ft::iterator_traits<InputIterator>::value_type> tmp;
				while (first != last)
					tmp.push_back(*first++);

				difference_type index = &(*position) - _arr;
				size_type       n = tmp.size();
				size_type       new_size = size() + n;
				size_type		diff = std::distance(first, last);

				reserve(new_size);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, *(_arr + i - diff));
				for (size_type i = size() + n - 1; i >= index + n; i--)
					_arr[i] = _arr[i - n];
				try
				{
					for (size_type i = 0; i < n; i++)
						_arr[index + i] = tmp[i];
				}
				catch (...)
				{
					_capacity = 0;
					throw;
				}
				_size += n;
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
				reserve(size() + 1);
				_alloc.construct(_arr + _size, value);
				_size++;
			}
			////////   RBEGIN   //////////
			reverse_iterator rbegin() { return reverse_iterator(end()); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); };
			////////   REND   //////////
			reverse_iterator rend() { return reverse_iterator(begin()); };
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); };
			////////   RESERVE   //////////
			void reserve (size_type new_capacity)
			{
				pointer new_arr;
				size_type	old_cap;

				old_cap = _capacity;
				if(new_capacity > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");

				if(new_capacity > (_capacity * 2))
					_capacity = new_capacity;
				else if(new_capacity > _capacity)
					_capacity = _capacity * 2;
				else if(new_capacity <= _capacity)
					return;

				new_arr = _alloc.allocate(_capacity);
				for(size_type i = 0; i < _size; i++)
				{
					_alloc.construct(new_arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, old_cap);
				_arr = new_arr;
			}
			////////   RESIZE   //////////
			void resize(size_type count, T value = T())
			{
				if(count == _size)
					return;
				if(count > _capacity)
				{
					reserve(count);
				}
				for(size_type i = _size; i < count; i++)
					_alloc.construct(_arr + i, value);
				_size = count;
			}
			////////   SIZE   //////////
			size_type size() const { return (_size); }
			////////   SWAP   //////////
			void swap(vector& other)
			{
            	T* arr = other._arr;
            	other._arr = _arr;
            	_arr = arr;

				size_type size = other._size;
            	other._size = _size;
            	_size = size;
				
				size_type capacity = other._capacity;
				other._capacity = _capacity;
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

namespace std
{
	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs); 
	}
}

#endif