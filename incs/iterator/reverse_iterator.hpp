/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:50:04 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/04 17:02:54 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "iterator_traits.hpp"

namespace ft 
{
	template <class T, class Alloc = std::allocator<T> >

	class reverse_iterator
	{
		public:
			typedef Iter											iterator_type
			typedef ft::iterator_traits<Iter>::iterator_category	iterator_category
			typedef ft::iterator_traits<Iter>::value_type			value_type
			typedef ft::iterator_traits<Iter>::difference_type		difference_type
			typedef ft::iterator_traits<Iter>::pointer				pointer
			typedef ft::iterator_traits<Iter>::reference			reference
		
		private:
			T *data;

		public:
			reverse_iterator(T* ptr): data(ptr) {};
			reverse_iterator(const ReverseIterator &src) { data = src.data; };
			~reverse_iterator(){};

		// INCREMENT OR DECREMENT ITERATORS
		reverse_iterator& operator++() //pre increment : returns a reference to the incremented object
		{
			data--;
			return *this;
		}

		reverse_iterator operator++(int) //post increment : returns a copy of the original, unincremented object
		{
			reverse_iterator tmp = *this;
			--(*this);
			return tmp;
		}
		
		reverse_iterator& operator--() //pre decrement
		{
			data++;
			return *this;
		}

		reverse_iterator operator--(int) //post decrement
		{
			reverse_iterator tmp = *this;
			++(*this);
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
		bool operator==(const reverse_iterator& src) const
		{
			return (data == src->data);
		}
		
		bool operator!=(const reverse_iterator& src) const
		{
			return (data != src->data);
		}
		
		bool operator>=(const reverse_iterator &src) const
		{
			return (data >= src->data);
		}
		
		bool operator<=(const reverse_iterator &src) const
		{
			return (data <= src->data);
		}
		bool operator>(const reverse_iterator &src) const
		{
			return (data > src->data);
		}
		
		bool operator<(const reverse_iterator &src) const
		{
			return (data < src->data);
		}
	};
}
#endif
			