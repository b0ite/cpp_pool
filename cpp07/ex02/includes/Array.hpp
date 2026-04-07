/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:47:45 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 20:32:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <limits>

template<typename T>
class Array
{
	private:
		T* elements;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		unsigned int size() const;
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		class OutOfBoundsException;
};

#include "Array.tpp"

#endif
