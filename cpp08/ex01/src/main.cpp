/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:17:24 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/08 19:31:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../includes/Span.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

int main()
{
	std::cout << CYAN << "--- TEST 1: Test basique du sujet ---" << RESET << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span : " << GREEN << sp.shortestSpan() << RESET << " (Attendu: 2)" << std::endl;
		std::cout << "Longest span  : " << GREEN << sp.longestSpan() << RESET << " (Attendu: 14)" << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Erreur inattendue: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << CYAN << "--- TEST 2: Tests des exceptions ---" << RESET << std::endl;
	try {
		std::cout << YELLOW << "[1] Création d'un Span de taille 1 et tentative de shortestSpan()..." << RESET << std::endl;
		Span sp2(1);
		sp2.addNumber(42);
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << GREEN << "Exception attrapée avec succès : " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << YELLOW << "\n[2] Ajout d'un nombre dans un Span déjà plein..." << RESET << std::endl;
		Span sp3(2);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3); // Ceci devrait planter
	} catch (std::exception &e) {
		std::cout << GREEN << "Exception attrapée avec succès : " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << CYAN << "--- TEST 3: Test massif avec 15 000 nombres ---" << RESET << std::endl;
	try {
		Span spHuge(15000);
		std::vector<int> randomNumbers;
		
		// Initialisation du générateur de nombres aléatoires
		std::srand(std::time(NULL));
		for (int i = 0; i < 15000; i++) {
			randomNumbers.push_back(std::rand()); // Nombres vraiment aléatoires
		}

		std::cout << YELLOW << "Ajout de 15 000 nombres d'un coup (addNumbers)..." << RESET << std::endl;
		spHuge.addNumbers(randomNumbers.begin(), randomNumbers.end());
		
		std::cout << GREEN << "Succès de l'ajout ! Calcul des spans..." << RESET << std::endl;
		std::cout << "Shortest span : " << spHuge.shortestSpan() << std::endl;
		std::cout << "Longest span  : " << spHuge.longestSpan() << std::endl;

	} catch (std::exception &e) {
		std::cout << RED << "Erreur: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << CYAN << "--- FIN DES TESTS ---" << RESET << std::endl;

	return 0;
}
