/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:47:43 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 20:32:32 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : elements(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array& other) : elements(new T[other._size]), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		elements[i] = other.elements[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* new_elements = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i)
			new_elements[i] = other.elements[i];
		delete[] elements;
		elements = new_elements;
		_size = other._size;
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return elements[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return elements[index];
}

template<typename T>
class Array<T>::OutOfBoundsException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
};
