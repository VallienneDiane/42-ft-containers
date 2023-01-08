/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vallienne <vallienne@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:15:38 by dvallien          #+#    #+#             */
/*   Updated: 2023/01/08 18:34:14 by vallienne        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP


namespace ft
{
	//by default there is no type defined
	template<bool B, class T = void>
	class enable_if
	{
		
	};
 
	//if the first parameter is true a type is defined as T
	template<class T>
	class enable_if<true, T> 
	{ 
		public:
			typedef T type; 
	};
}

#endif