/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:19 by dvallien          #+#    #+#             */
/*   Updated: 2022/12/08 16:28:35 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////// VECTOR IS A SEQUENCE CONTAINER AND KNOWN AS A DYNAMIC ARRAY OR ARRAY LIST //////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Alloc
// Member type allocator_type is the internal allocator type used by the container
// An allocator is used to acquire/release memory and to construct/destroy the elements in that memory

// n : Initial container size 

// val : Value to fill the container with.

// first,last : Input iterators to the initial and final positions in a range.

// x : Another vector object of the same type

// il : An initializer_list object.

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector>
#include <iostream>

template <class T, class Allocator = std::allocator<T> >

class Vector
{
	public:
		typedef T			value_type;
    	typedef Allocator	allocator_type;
		
		//////////////////////////////////// CONSTRUCTORS /////////////////////////////////////////////
		// default constructor : Constructs an empty container, with no elements.
		explicit vector(const allocator_type& alloc = allocator_type()) {}
		// fill constructor : Constructs a container with n elements. Each element is a copy of val.
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		// range constructor : Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range
		template <class InputIterator>	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		// copy constructor : Constructs a container with a copy of each of the elements in x, in the same order.
		vector(const vector& x);
		
		//////////////////////////////////// FUNCTIONS /////////////////////////////////////////////
		//ASSIGN //
		template <class InputIterator>  void assign (InputIterator first, InputIterator last);
		void assign (size_type n, const value_type& val);
	
};

#endif