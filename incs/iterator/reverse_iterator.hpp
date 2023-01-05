/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:50:04 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/05 17:42:22 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include "iterator_traits.hpp"
#include "../vector/Vector.hpp"


namespace ft 
{
	template <class Iterator, class T >
	
	class reverse_iterator
	{
		public:
			typedef Iterator													iterator_type;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
		
		private:
			T *_data;

		public:
			reverse_iterator(T* ptr): _data(ptr) {};
			reverse_iterator(const reverse_iterator &src) { *this = src; };
			~reverse_iterator(){};

			reverse_iterator & operator=(const reverse_iterator &src)
			{
				_data = src._data;
				return (*this);
			}
			
			// INCREMENT OR DECREMENT ITERATORS
			reverse_iterator& operator++() //pre increment : returns a reference to the incremented object
			{
				_data--;
				return *this;
			}

			reverse_iterator& operator++(int) //post increment : returns a copy of the original, unincremented object
			{
				reverse_iterator tmp = *this;
				--(*this);
				return tmp;
			}
			
			reverse_iterator& operator+=(difference_type n)
			{
				return (_data - n);
			}
			
			reverse_iterator& operator--() //pre decrement
			{
				_data++;
				return *this;
			}

			reverse_iterator& operator--(int) //post decrement
			{
				reverse_iterator tmp = *this;
				++(*this);
				return tmp;
			}
			
			reverse_iterator& operator-=( difference_type n )
			{
				return (_data + n);
			}
			
			// INDEX OPERATORS
			reference operator[](int index)
			{
				return *(_data + index); // or return *(_data[index]);
			}

			pointer operator->()
			{
				return (_data);
			}

			reference operator*()
			{
				return (*_data);
			}
			// COMPARISON OPERATORS
			bool operator==(const reverse_iterator& src) const
			{
				return (_data == src->_data);
			}
			
			bool operator!=(const reverse_iterator& src) const
			{
				return (_data != src->_data);
			}
			
			bool operator>=(const reverse_iterator &src) const
			{
				return (_data >= src->_data);
			}
			
			bool operator<=(const reverse_iterator &src) const
			{
				return (_data <= src->_data);
			}
			bool operator>(const reverse_iterator &src) const
			{
				return (_data > src->_data);
			}
			
			bool operator<(const reverse_iterator &src) const
			{
				return (_data < src->_data);
			}
			

		reverse_iterator operator+(reverse_iterator::difference_type n, const reverse_iterator& rev_it)
		{
			return (rev_it + n);
		}
				

		typename reverse_iterator::difference_type operator-(const reverse_iterator& lhs, const reverse_iterator& rhs)
		{
			return (lhs - rhs);
		}
	};
}
#endif
			