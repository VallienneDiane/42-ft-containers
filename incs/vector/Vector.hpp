/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/04 17:23:16 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "../iterator/reverse_iterator.hpp"

////// VECTOR IS A SEQUENCE CONTAINER AND KNOWN AS A DYNAMIC ARRAY OR ARRAY LIST ////////
namespace ft 
{
	template <class T, class Alloc = std::allocator<T> >

	class vector
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef value_type*                   				iterator; // template < class Iterator >
    		typedef const value_type*                   		const_iterator;
    		typedef typename allocator_type::size_type       	size_type;
    		typedef typename allocator_type::difference_type 	difference_type;
    		typedef typename allocator_type::pointer         	pointer;
    		typedef typename allocator_type::const_pointer   	const_pointer;
    		typedef	ft::reverse_iterator<iterator>          	reverse_iterator;
    		typedef ft::reverse_iterator<const_iterator>    	const_reverse_iterator;

		private:
			Alloc				_alloc;
			value_type			*_arr;
			size_type			_size; 		//number of elements
			size_type			_capacity;	//size of allocated storage
			
		public:
			//default constructor
			explicit vector(const allocator_type& alloc = allocator_type()): _size(0), _capacity(1), _alloc(alloc) {};
			//fill constructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _size(n), _capacity(n), _alloc(alloc)
			{
				_arr = _alloc.allocate(_capacity);
				for(int i = 0; i < n; i++)
				{
					_alloc.construct(_arr + i, val);
				}
			};
			//range constructor
			template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) 
			{
//TO DO
			};
			//copy constructor
			vector(const vector &x) { *this = x; };
			//destructor
			~vector(void) {};
			
			////////   OPERATOR =    //////////
			vector & operator=(const vector &src) 
			{ 
				_size = src._size; 
				_capacity = src._capacity; 
				return (*this); 
			};
			////////   OPERATOR []    //////////
			reference operator[](size_type n) 
			{ 
				return (_arr[n]); 
			}
			const_reference operator[](size_type n) const 
			{ 
				return (_arr[n]); 
			}
			////////////////////////    ITERATORS    //////////////////////////////
			class Iterator
			{
				private:
					T *data;
				public:
					Iterator(T *ptr): data(ptr) {};
					Iterator(const Iterator &src) { data = src.data; };
					~Iterator() {};
				
				// INCREMENT OR DECREMENT ITERATORS
				iterator& operator++() //pre increment : returns a reference to the incremented object
				{
					data++;
					return *this;
				}

				iterator operator++(int) //post increment : returns a copy of the original, unincremented object
				{
					iterator tmp = *this;
					++(*this);
					return tmp;
				}
				
				iterator& operator--() //pre decrement
				{
					data--;
					return *this;
				}

				iterator operator--(int) //post decrement
				{
					iterator tmp = *this;
					--(*this);
					return tmp;
				}
				// INDEX OPERATORS
				reference operator[](int index)
				{
					return *(data + index); // or return *(data[index]);
				}

				pointer operator->()
				{
					return (data);
				}

				reference operator*()
				{
					return (*data);
				}
				// COMPARISON OPERATORS
				bool operator==(const iterator& src) const
				{
					return (data == src->data);
				}
				
				bool operator!=(const iterator& src) const
				{
					return (data != src->data);
				}
				
				bool operator>=(const iterator &src) const
				{
					return (data >= src->data);
				}
				
				bool operator<=(const iterator &src) const
				{
					return (data <= src->data);
				}
				bool operator>(const iterator &src) const
				{
					return (data > src->data);
				}
				
				bool operator<(const iterator &src) const
				{
					return (data < src->data);
				}
			};

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////    VECTOR MEMBER FUNCTIONS   ////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
			////////   ASSIGN    //////////
// void assign (iterator first, iterator last);	
void assign (size_type n, const value_type& val)
{
	// si taille plus petite supprime le surplus
	if(n < _size)
	{
		int i = 0
		for(i; i < n; i++)
		{
			_arr[i] = val;
		}
		std::cout << "i : " << std::endl;
		for(int j = i; j < _size; j++)
		{
			_alloc.destroy(_arr + j)
		}
	}
	// si capacity trop petite clear et realloue
	else if(n > _capacity)
	{
		
	}
}

			////////   AT    //////////
			reference at(size_type n)
			{
				if (n < 0 || n > _size)
					throw  std::out_of_range("vector");
				return (_arr[n]);
			}

			const_reference at (size_type n) const
			{
				if (n < 0 || n > _size)
					throw  std::out_of_range("vector");
				return (_arr[n]);
			}
			////////   BACK    //////////
			reference back()
			{
				return (_arr[_size - 1]);
			}

			const_reference back() const
			{
				return (_arr[_size - 1]);
			}
			////////   BEGIN    //////////
			iterator begin() //begin of vector
			{
				return iterator(_arr);
			}

			const_iterator begin() const
			{
				return iterator(_arr);
			}
			
			////////   CAPACITY    //////////
			size_type capacity() const { return (_capacity); }

			////////   CLEAR    //////////
			void clear()
			{
				_alloc.destroy(_arr);
				_alloc.deallocate(_arr, _capacity);
				_size = 0;
			}
			////////   EMPTY    //////////
			bool empty() const
			{
				if(_size == 0)
					return (true);
				return (false);
			}
			////////   END    //////////
			iterator end() //after end of vector
			{
				return iterator(_arr + _size);
			}
			
			const_iterator end() const
			{
				return iterator(_arr + _size);
			}
			
			////////   ERASE    //////////
			
// iterator erase (iterator position);
// iterator erase (iterator first, iterator last);
			
			////////   FRONT    //////////
			reference front()
			{
				return (_arr[0]);
			}

			const_reference front() const
			{
				return (_arr[0]);
			}
			////////   GET ALLOCATOR    //////////
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}
			////////   INSERT    //////////
// iterator insert(iterator position, const value_type& val);

// void insert(iterator position, size_type n, const value_type& val);
	
// void insert(iterator position, InputIterator first, InputIterator last);

			////////   MAX SIZE    //////////
			size_type max_size() const { return (_alloc.max_size()); }

			////////   POP BACK    //////////
			void pop_back()
			{
				if (_size > 0)
				{
					_size--;
					_alloc.destroy(_arr[_size - 1]);
				}
			}
			////////   PUSH BACK    //////////
			void	push_back(const value_type& value)
			{
				if (_size == 0)
				{
					_arr = _alloc.allocate(_capacity);
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
				for(int i = 0; i < _size; i++)
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
// reverse_iterator rbegin();
// const_reverse_iterator rbegin() const;

			////////   REND   //////////
// reverse_iterator rend();
// const_reverse_iterator rend() const
			
			////////   RESERVE   //////////
// void reserve (size_type n);

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
						for(int i = 0; i < n; i++)
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
						for(int i = 0; i < _size; i++)
							_alloc.construct(new_arr + i, _arr[i]);
						for(int i = _size; i < n; i++)
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
			void swap (vector& x)
			{
				vector tmp;

				tmp = *this;
				*this = x;
				x = tmp;
			}				
	};
}

#endif