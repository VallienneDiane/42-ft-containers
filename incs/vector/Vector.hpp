/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/12/19 17:06:50 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////////////////////////////////////////////////////////////////////////////////////////
////// VECTOR IS A SEQUENCE CONTAINER AND KNOWN AS A DYNAMIC ARRAY OR ARRAY LIST ////////
////////////////////////////////////////////////////////////////////////////////////////

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>

namespace ft 
{
	template <typename T, class Allocator = std::allocator<T> >
	
	class vector
	{
		private:
			typedef T			value_type;
			typedef	T&			reference;
			typedef	T const &	const_reference;
			typedef	size_t		size_type;
			Allocator 			alloc;
			value_type			*_arr;
			size_type			_size; 		// number of elements
			size_type			_capacity;	//size of allocated storage 
			
		public:
			vector(void): _size(0), _capacity(1) {};
			~vector(void) {};
			
			void	push_back(const value_type& value)
			{
				if (_size == 0)
				{
					_arr = alloc.allocate(_capacity);
					alloc.construct(_arr + _size, value);
					_size++;
				}
				else if(_size < _capacity)
				{
					alloc.construct(_arr + _size, value);
					_size++;
				}
				else if (_size == _capacity)
				{
					_capacity = _capacity * 2;
					move_arr(_capacity); // move array to deallocate old arr
					alloc.construct(_arr + _size, value);
					_size++;
				}
			}

			void	move_arr(size_type new_capacity)
			{
				value_type	*new_arr;

				new_arr = alloc.allocate(new_capacity);
				for(int i = 0; i < _size; i++)
				{
					alloc.construct(new_arr + i, _arr[i]);
					alloc.destroy(_arr + i);
				}
				alloc.destroy(_arr);
				alloc.deallocate(_arr, _capacity);
				_arr = new_arr;
				_capacity = new_capacity;
			}

			size_type capacity() const { return (_capacity); }

			size_type size() const { return (_size); }

			size_type max_size() const { return (alloc.max_size()); }

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
						new_arr = alloc.allocate(new_capacity);
						for(int i = 0; i < n; i++)
						{
							alloc.construct(new_arr + i, _arr[i]);						
							alloc.destroy(_arr + i);
						}
						alloc.destroy(_arr);
						alloc.deallocate(_arr, _capacity);
						_arr = new_arr;
						_size = n;
					}
					else if (n > _size)
					{
						new_capacity = n;
						new_arr = alloc.allocate(new_capacity);
						for(int i = 0; i < _size; i++)
							alloc.construct(new_arr + i, _arr[i]);
						for(int i = _size; i < n; i++)
						{
							alloc.construct(new_arr + i, val);
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

			// reference front()
			// {
			// 	return (_arr[0]);
			// }

			// const_reference front() const
			// {
			// 	return (_arr[0]);
			// }
			
			// reference back()
			// {
			// 	for(int i = 0; i < _size; i++)
			// 	{}
			// 	return (_arr[i]);
			// }

			// const_reference back() const
			// {
			// 	for(int i = 0; i < _size; i++)
			// 	{}
			// 	return (_arr[i]);
			// }
			
			bool empty() const
			{
				if(_size == 0)
					return (true);
				return (false);
			}

			void clear()
			{
				alloc.destroy(_arr);
				alloc.deallocate(_arr, _capacity);
				_size = 0;
			}
			//////////////////////// OPERATORS /////////////////////////////
			T const & operator[](size_type n) const { return (_arr[n]); }
			T & operator[](size_type n) { return (_arr[n]); }
			
			//////////////////////// ITERATORS /////////////////////////////
	};
}

#endif