/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:13:38 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 19:23:59 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T& a, T&b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const& a, T const& b)
{
	if (a < b)
		return a;
	return b;
}

template<typename T>
T const& max(T const& a, T const& b)
{
	if (a > b)
		return a;
	return b;
}


#endif
