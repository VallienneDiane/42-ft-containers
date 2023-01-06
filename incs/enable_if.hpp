/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:15:38 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/06 16:23:12 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
	template<bool B, class T = void>
	class enable_if
	{};
 
	template<class T>
	class enable_if<true, T> 
	{ 
		typedef T type; 
	};
}

#endif