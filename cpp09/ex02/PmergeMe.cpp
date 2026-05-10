/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:05:55 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/10 17:38:35 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	_vector = other._vector;
	_deque = other._deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<int> PmergeMe::buildInsertOrder(int size) {
    std::vector<int> order;

    if (size <= 1) return order;
    std::vector<int> jacob;
    int prev = 1;
    int curr = 3;
    jacob.push_back(curr);
    while (curr < size + 2) {
        int next = curr + 2 * prev;
        jacob.push_back(next);
        prev = curr;
        curr = next;
    }
    int lastInserted = 0;

    for (size_t i = 0; i < jacob.size(); ++i) {
        int jIndex = jacob[i] - 1; 
        if (jIndex >= size) {
            jIndex = size - 1;
        }
        int currentToInsert = jIndex;
        while (currentToInsert > lastInserted) {
            order.push_back(currentToInsert);
            currentToInsert--;
        }
        lastInserted = jIndex;
        if (lastInserted == size - 1) {
            break;
        }
    }
    return order;
}

void PmergeMe::printVector() const
{
	std::cout << "Sorted Vector: ";
	for (size_t i = 0; i < _vector.size(); ++i)
	{
		std::cout << _vector[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
	std::cout << "Sorted Deque: ";
	for (size_t i = 0; i < _deque.size(); ++i)
	{
		std::cout << _deque[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTime(size_t size, double vectorTime, double dequeTime) const
{
	std::cout << "Time to process a range of " << size << " elements with std::vector : " 
	          << std::fixed << std::setprecision(1) << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque : " 
	          << std::fixed << std::setprecision(1) << dequeTime << " us" << std::endl;
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec)
{
	if (vec.size() <= 1)
		return;
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> winners;
	
	bool hasOdd = vec.size() % 2 != 0;
	int straggler = hasOdd ? vec.back() : -1;
	for (size_t i = 0; i < vec.size() / 2; ++i)
	{
		int a = vec[2 * i];
		int b = vec[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		winners.push_back(a);
	}
	mergeInsertSortVector(winners);
	std::vector<int> MainChain;
	std::vector<int> loosers;
	for (size_t i = 0; i < winners.size(); ++i)
	{
		MainChain.push_back(winners[i]);
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == winners[i]){
				loosers.push_back(pairs[j].second);
				break;
			}
		}
	}
	if (!loosers.empty())
	{
		MainChain.insert(MainChain.begin(), loosers[0]);
	}
	std::vector<int> inserteOrder = buildInsertOrder(loosers.size());
	if (hasOdd)
	{
		loosers.push_back(straggler);
		inserteOrder.push_back(loosers.size() - 1);
	}
	for (size_t i = 0; i < inserteOrder.size(); ++i)
	{
		int index = inserteOrder[i];
		int value = loosers[index];
		std::vector<int>::iterator it = std::lower_bound(MainChain.begin(), MainChain.end(), value);
		MainChain.insert(it, value);
	}
	vec = MainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& vec)
{
	if (vec.size() <= 1)
		return;
	std::deque<std::pair<int, int> > pairs;
	std::deque<int> winners;
	
	bool hasOdd = vec.size() % 2 != 0;
	int straggler = hasOdd ? vec.back() : -1;
	for (size_t i = 0; i < vec.size() / 2; ++i)
	{
		int a = vec[2 * i];
		int b = vec[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
		winners.push_back(a);
	}
	mergeInsertSortDeque(winners);
	std::deque<int> MainChain;
	std::deque<int> loosers;
	for (size_t i = 0; i < winners.size(); ++i)
	{
		MainChain.push_back(winners[i]);
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == winners[i]){
				loosers.push_back(pairs[j].second);
				break;
			}
		}
	}
	if (!loosers.empty())
	{
		MainChain.insert(MainChain.begin(), loosers[0]);
	}
	std::vector<int> inserteOrder = buildInsertOrder(loosers.size());
	if (hasOdd)
	{
		loosers.push_back(straggler);
		inserteOrder.push_back(loosers.size() - 1);
	}
	for (size_t i = 0; i < inserteOrder.size(); ++i)
	{
		int index = inserteOrder[i];
		int value = loosers[index];
		std::deque<int>::iterator it = std::lower_bound(MainChain.begin(), MainChain.end(), value);
		MainChain.insert(it, value);
	}
	vec = MainChain;
}

PmergeMe::PmergeMe(char** argv)
{
	for (int i = 1; argv[i] != NULL; ++i)
	{
		int num = std::atoi(argv[i]);
		if (num < 0)
			throw std::invalid_argument("Negative numbers are not allowed");
		_vector.push_back(num);
		_deque.push_back(num);
	}
	std::cout << "Before sorting: ";
	printVector();
	std::cout << std::endl;
	struct timeval start, end;
	gettimeofday(&start, NULL);
	mergeInsertSortVector(_vector);
	gettimeofday(&end, NULL);
	double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	mergeInsertSortDeque(_deque);
	gettimeofday(&end, NULL);
	double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
	std::cout << "After sorting: ";
	printVector();
	std::cout << std::endl;
	printTime(_vector.size(), vectorTime, dequeTime);
}