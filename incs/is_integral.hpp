/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:04 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/06 17:22:09 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP
#include "vector.hpp"

namespace ft
{
	template <class T, T v>
	struct integral_constant 
	{
  		static const T 					value = v;
  		typedef T 						value_type;
  		typedef integral_constant<T,v> 	type;
		  
		operator value_type() const { return (value); }
	};
	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	//FUNDAMENTAL INTEGRAL TYPES
	template < typename >
		struct isIntegral : public false_type							{};
	template <>
		struct isIntegral<bool> : public true_type						{};
	template <>
		struct isIntegral<char> : public true_type						{};
	template <>
		struct isIntegral<wchar_t> : public true_type					{};
	template <>
		struct isIntegral<signed char> : public true_type				{};
	template <>
		struct isIntegral<short int> : public true_type					{};
	template <>
		struct isIntegral<int> : public true_type						{};
	template <>
		struct isIntegral<long int> : public true_type					{};
	template <>
		struct isIntegral<long long int> : public true_type				{};
	template <>
		struct isIntegral<unsigned char> : public true_type				{};
	template <>
		struct isIntegral<unsigned short int> : public true_type		{};
	template <>
		struct isIntegral<unsigned int> : public true_type				{};
	template <>
		struct isIntegral<unsigned long int> : public true_type			{};
	template <>
		struct isIntegral<unsigned long long int> : public true_type	{};
}

#endif