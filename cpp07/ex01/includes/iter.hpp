/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:28:51 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 19:44:33 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <limits>

template<typename T, typename F>
void iter(T* array, size_t const length, void (*function)(F))
{
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
