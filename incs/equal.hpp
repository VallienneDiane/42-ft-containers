/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:51:54 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/06 16:56:47 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP
#include <iterator>
#include "vector.hpp"

namespace ft
{
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!(*first1 == *first2)) 
			{
				return false;
			}
		}
		return true;
	}

	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!p(*first1, *first2)) 
			{
				return false;
			}
		}
		return true;
	}
}
#endif