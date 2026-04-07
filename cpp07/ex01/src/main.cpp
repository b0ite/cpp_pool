/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:11:25 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 19:42:32 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
void randomMultiplier(T const &i)
{
	int randomPrefix = (rand() % 100) + 15; // Generate a random number between 15 and 114.
	std::cout << i << " * " << randomPrefix << " = " << i * randomPrefix << std::endl;
}

template <typename T>
void doubleInt(T &i)
{
	i = i * 2;
	std::cout << "Response value doubled: " << i << std::endl;
}

template <typename T>
void printInt(T const &toPrint)
{
	std::cout << toPrint << " ";
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    int array[] = {1, 2, 3, 4, 5};
    std::string words[] = {"hello", "from", "iter"};

    std::cout << "Original ints: ";
    iter(array, 5, printInt<int>);
    std::cout << std::endl;

    std::cout << "Random multiplications: " << std::endl;
    iter(array, 5, randomMultiplier<int>);

    std::cout << "Doubled ints: " << std::endl;
    iter(array, 5, doubleInt<int>);

    std::cout << "Strings: ";
    iter(words, 3, printInt<std::string>);
    std::cout << std::endl;

    return 0;
}