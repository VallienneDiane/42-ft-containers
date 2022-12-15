/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/12/15 17:04:50 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////// VECTOR IS A SEQUENCE CONTAINER AND KNOWN AS A DYNAMIC ARRAY OR ARRAY LIST //////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ALLOC
// An allocator is used to acquire/release memory and to construct/destroy the elements in that memory
// n : Initial container size 
// val : Value to fill the container with.
// first,last : Input iterators to the initial and final positions in a range.
// x : Another vector object of the same type
// il : An initializer_list object.

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <string>

namespace ft 
{
	template <typename T, class Allocator = std::allocator<T> >
	
	class vector
	{
		private:
			typedef T value_type;
			Allocator alloc;
			value_type	*_arr;
			size_t		_size; 	// number of elements
			size_t		_capacity;	//size of allocated storage 
			
		public:
			// // default constructor : Constructs an empty container, with no elements.
			// explicit vector(const alloc& alloc = alloc()) {}
			// // fill constructor : Constructs a container with n elements. Each element is a copy of val.
			// explicit vector(size_type n, const value_type& val = value_type(), const alloc& alloc = alloc());
			// // range constructor : Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range
			// template <class InputIterator> 
			// 	vector(InputIterator first, InputIterator last, const alloc& alloc = alloc());
			// // copy constructor : Constructs a container with a copy of each of the elements in x, in the same order.
			// vector(const vector& x);
			vector(void): _size(0), _capacity(1) {};
			~vector(void) {};
			
			void	push_back(const value_type& value)
			{
				if (_size == 0)
				{
					_arr = alloc.allocate(_capacity);
					_arr[_size] = value;
					_size++;
				}
				if(_size < _capacity)
				{
					_arr = alloc.allocate(_capacity);
					_arr[_size] = value;
					_size++;
				}
				if (_size == _capacity)
					_capacity = _capacity * 2;
			}

			//EN COURS
			void	pop_back(void)
			{
				// std::cout << _size << std::endl;
				// alloc.deallocate(_arr, _size - 1);
			}

			T & operator[](size_t n)
			{
				if (n >= _size)
					std::cout << "Error" << std::endl; //throw exception
				return (_arr[n]);
			}

		
	
	};
}



#endif