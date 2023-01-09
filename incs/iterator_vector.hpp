/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:44:12 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/09 16:29:51 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
#define ITERATOR_VECTOR_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <iterator>

namespace ft
{
	template< class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	class my_iterator: public std::iterator<std::random_access_iterator_tag, T, Distance, Pointer, Reference>
	{			
		public:
			typedef T         							value_type;
			typedef Distance							difference_type;
			typedef Pointer								pointer;
			typedef Reference							reference;
			typedef std::random_access_iterator_tag  	iterator_category;
			
		private:
			Pointer _current;
		
		public:
			my_iterator(): _current(NULL) {}
			explicit my_iterator(value_type *ptr): _current(ptr) {}
			my_iterator(const my_iterator &other) { *this = other; }
			my_iterator& operator=(const my_iterator &other) { _current = other._current; return (*this); }
			~my_iterator() {}
		
		// INCREMENT OR DECREMENT ITERATORS
			//pre increment : returns a reference to the incremented object 
			//post increment : returns a copy of the original, unincremented object
		my_iterator& operator++() { _current++; return (*this); }
		my_iterator operator++(int) { my_iterator tmp = *this; ++(*this); return tmp; }
		my_iterator operator+(difference_type n) const { return my_iterator(_current + n); }
		//my_iterator& operator+=(difference_type n) { return my_iterator(_current + n); }
		
		my_iterator& operator--() { _current--; return (*this); }
		my_iterator operator--(int){ my_iterator tmp = *this; --(*this); return tmp; }
		my_iterator operator-(difference_type n) const { return my_iterator(_current - n); }
		// INDEX OPERATORS
		reference operator[](int index) { return *(_current + index); }
		pointer operator->() { return (_current); }
		reference operator*() { return (*_current); }
		// COMPARISON OPERATORS
		bool operator==(const my_iterator& rhs) const { return (_current == rhs._current); }
		bool operator!=(const my_iterator& rhs) const { return (_current != rhs._current); }
		bool operator>=(const my_iterator &rhs) const { return (_current >= rhs._current); }
		bool operator<=(const my_iterator &rhs) const { return (_current <= rhs._current); }
		bool operator>(const my_iterator &rhs) const { return (_current > rhs._current); }
		bool operator<(const my_iterator &rhs) const { return (_current < rhs._current); }
	};
}

#endif