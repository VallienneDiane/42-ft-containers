/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:44:12 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/13 17:24:36 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
#define ITERATOR_VECTOR_HPP
#include <iterator>

namespace ft
{
	template< class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	class my_iterator: public std::iterator<std::random_access_iterator_tag, T, Distance, Pointer, Reference>
	{			
		public:
			typedef std::random_access_iterator_tag  																iterator_category;
			typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::value_type			value_type;
			typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::difference_type		difference_type;
			typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::pointer				pointer;
			typedef typename std::iterator<iterator_category, T, Distance, Pointer, Reference>::reference			reference;
			
		private:
			Pointer _current;
		
		public:
			my_iterator(): _current(NULL) {}
			explicit my_iterator(value_type *ptr): _current(ptr) {}
			my_iterator(const my_iterator &other) { _current = other._current;}
			~my_iterator() {}
		
			my_iterator& operator=(const my_iterator &other) { _current = other._current; return (*this); }
			// INCREMENT OR DECREMENT ITERATORS
				//pre increment : returns a reference to the incremented object 
				//post increment : returns a copy of the original, unincremented object
			my_iterator& operator++() { _current++; return (*this); }
			my_iterator operator++(int) { my_iterator tmp = *this; ++(*this); return tmp; }
			my_iterator operator+(difference_type n) const { my_iterator tmp = *this; tmp._current += n; return tmp;}
			my_iterator& operator+=(difference_type n) { _current += n; return (*this); }
			
			my_iterator& operator--() { _current--; return (*this); }
			my_iterator operator--(int){ my_iterator tmp = *this; --(*this); return tmp; }
			my_iterator operator-(difference_type n) const { return my_iterator(_current - n); }
			my_iterator& operator-=(difference_type n) { _current -= n; return (*this); }
			difference_type operator-(const my_iterator &rhs) 
			{
				return (this->_current - rhs._current); 
			}
			// INDEX OPERATORS
			reference operator[](int index) { return *(_current + index); }
			pointer operator->() const { return (_current); }
			reference operator*() const { return (*_current); }
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