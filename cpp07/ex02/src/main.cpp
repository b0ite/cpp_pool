/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:11:25 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 20:31:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/Array.hpp"

int main()
{
	std::cout << "--- TEST 1 : Tableau vide ---" << std::endl;
	Array<int> emptyArr;
	std::cout << "Taille de emptyArr : " << emptyArr.size() << std::endl;
	try {
		std::cout << "Tentative d'acces a emptyArr[0]..." << std::endl;
		emptyArr[0] = 42;
	} catch (const std::exception& e) {
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 2 : Tableau parametre et initialisation par defaut ---" << std::endl;
	Array<int> arr(5);
	std::cout << "Taille de arr : " << arr.size() << std::endl;
	std::cout << "Valeur de arr[0] (devrait etre 0) : " << arr[0] << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	
	std::cout << "Contenu de arr : ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n--- TEST 3 : Depassement de limite ---" << std::endl;
	try {
		std::cout << "Tentative d'acces a arr[5] (hors limites)..." << std::endl;
		arr[5] = 100;
	} catch (const std::exception& e) {
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	try {
		std::cout << "Tentative d'acces avec un index negatif (arr[-1])..." << std::endl;
		arr[-1] = 100; // -1 va wrap-around en un tres grand nombre positif (hors-limite)
	} catch (const std::exception& e) {
		std::cerr << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\n--- TEST 4 : Constructeur de copie (Deep Copy) ---" << std::endl;
	Array<int> copyArr(arr);
	copyArr[0] = 999; // On modifie la copie
	std::cout << "arr[0] : " << arr[0] << " (ne doit pas etre 999)" << std::endl;
	std::cout << "copyArr[0] : " << copyArr[0] << " (doit etre 999)" << std::endl;

	std::cout << "\n--- TEST 5 : Operateur d'assignation (Deep Copy) ---" << std::endl;
	Array<int> assignArr(2); // On cree un petit tableau au depart
	assignArr = arr; // On ecrase avec le tableau de taille 5
	assignArr[1] = 888; // On modifie l'assignation
	std::cout << "Taille de assignArr : " << assignArr.size() << " (doit etre 5)" << std::endl;
	std::cout << "arr[1] : " << arr[1] << " (ne doit pas etre 888)" << std::endl;
	std::cout << "assignArr[1] : " << assignArr[1] << " (doit etre 888)" << std::endl;

	std::cout << "\n--- TEST 6 : Tableau de types complexes (std::string) ---" << std::endl;
	Array<std::string> strArr(3);
	std::cout << "Taille de strArr : " << strArr.size() << std::endl;
	std::cout << "Valeur de strArr[0] par defaut (devrait etre vide) : '" << strArr[0] << "'" << std::endl;
	
	strArr[0] = "Bonjour";
	strArr[1] = "le";
	strArr[2] = "monde";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	return 0;
}
