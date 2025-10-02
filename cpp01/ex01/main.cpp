/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:49:28 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 15:44:51 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <array>
#include <random>

int rand_int(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

void message(std::string message){
	std::cout << message << std::endl;
}

int main() {
	std::array<std::string, 5> names = {
		"Tristan",
		"Faustine",
		"Marie",
		"Ivan",
		"IBG"
	};

	int size = rand_int(5, 20);
	int i = 0;
	message("Il est 22h, apparition de la horde... Good night, good luck...");
	Zombie* horde = zombieHorde(size, names[rand_int(0, 4)]);
	while (i < size)
	{
		std::cout << i+1 << "/" << size << std::endl;
		horde[i].announce();
		i++;
	}
	message("Il est temps de s'en debarasser...");
	delete[] horde;
	horde = nullptr;
	return (0);
}