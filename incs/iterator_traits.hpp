/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallienne <vallienne@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:02:17 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/08 18:40:48 by vallienne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
#include <iterator>

namespace ft 
{
	template<class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type 		difference_type;
			typedef typename Iterator::value_type 			value_type;
			typedef typename Iterator::pointer 				pointer;
			typedef typename Iterator::reference 			reference;
			typedef typename Iterator::iterator_category 	iterator_category;
	};

	template<class T>
	class iterator_traits<T*>
	{
		public:
			typedef	T										value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T*										pointer;
			typedef	T&										reference;
			typedef std::random_access_iterator_tag			iterator_category;
	};
	
	template<class T>
	class iterator_traits<const T*>
	{
		public:
			typedef	T										value_type;
			typedef std::ptrdiff_t							difference_type;
			typedef const T*								pointer;
			typedef	const T&								reference;
			typedef std::random_access_iterator_tag			iterator_category;
	};
}

#endif