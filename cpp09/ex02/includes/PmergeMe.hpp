/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:05:47 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/10 17:22:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>	_deque;
		void mergeInsertSortVector(std::vector<int>& vec);
		void mergeInsertSortDeque(std::deque<int>& deq);
		
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		PmergeMe(char** argv);
		void printVector() const;
		void printDeque() const;
		void printTime(size_t size, double vectorTime, double dequeTime) const;
		std::vector<int> buildInsertOrder(int size);
};

#endif
