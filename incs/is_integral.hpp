/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:04 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/11 15:31:04 by dvallien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

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
	template <class T>
	struct is_integral : public false_type							{};
	template <>
	struct is_integral<bool> : public true_type						{};
	template <>
	struct is_integral<char> : public true_type						{};
	template <>
	struct is_integral<wchar_t> : public true_type					{};
	template <>
	struct is_integral<signed char> : public true_type				{};
	template <>
	struct is_integral<short int> : public true_type				{};
	template <>
	struct is_integral<int> : public true_type						{};
	template <>
	struct is_integral<long int> : public true_type					{};
	template <>
	struct is_integral<long long int> : public true_type			{};
	template <>
	struct is_integral<unsigned char> : public true_type			{};
	template <>
	struct is_integral<unsigned short int> : public true_type		{};
	template <>
	struct is_integral<unsigned int> : public true_type				{};
	template <>
	struct is_integral<unsigned long int> : public true_type		{};
	template <>
	struct is_integral<unsigned long long int> : public true_type	{};
}

#endif