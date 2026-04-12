/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:30 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/08 19:29:34 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span()
{
	_maxSize = 0;
}

Span::Span(unsigned int N)
{
	_maxSize = N;
}

Span::~Span(){}

Span::Span(const Span& other)
{
	_maxSize = other._maxSize;
	_numbers = other._numbers;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Cannot add more numbers");
	_numbers.push_back(number);
}

int Span::longestSpan()
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough elements to compare");
	return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

int Span::shortestSpan()
{
	uint greg = 2;
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough elements to compare");
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(), copy.end());
	int minSpan = copy[1] - copy[0];
	while (greg < copy.size())
	{
		if (copy[greg] - copy[greg - 1] <= minSpan)
			minSpan = copy[greg] - copy[greg - 1];
		greg++;
	}
	return minSpan;
}
