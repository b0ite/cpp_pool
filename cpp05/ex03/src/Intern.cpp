/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:51:12 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:45:51 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return forms[i];
		}
		delete forms[i];
	}
	throw UnknownFormException();
	return nullptr;
}

const char *Intern::UnknownFormException::what() const throw() {
	return "Unknown form name.";
}