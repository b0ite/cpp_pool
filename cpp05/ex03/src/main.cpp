/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:09:00 by igilbert          #+#    #+#             */
/*   Updated: 2026/03/16 14:24:18 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("home");

		std::cout << &boss;
		std::cout << &form;

		form.beSigned(boss);
		form.execute(boss);

		std::cout << "Shrubbery file created successfully." << std::endl;
	} catch (const std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}

