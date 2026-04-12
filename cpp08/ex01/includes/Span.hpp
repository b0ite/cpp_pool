/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:18:33 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/08 19:28:44 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);
		
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		template<typename Iter>
		void addNumbers(Iter begin, Iter end)
		{
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw std::runtime_error("Cannot add all the numbers");
			_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif
