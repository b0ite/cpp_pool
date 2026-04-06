/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:09:00 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:35:11 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

static void printSection(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main()
{
	srand(time(NULL));

	printSection("BUREAUCRAT BOUNDARIES");
	try {
		Bureaucrat invalidHigh("TooHigh", 0);
		std::cout << &invalidHigh << std::endl;
	} catch (std::exception &e) {
		std::cout << "Creation failed (grade 0): " << e.what() << std::endl;
	}
	try {
		Bureaucrat invalidLow("TooLow", 151);
		std::cout << &invalidLow << std::endl;
	} catch (std::exception &e) {
		std::cout << "Creation failed (grade 151): " << e.what() << std::endl;
	}

	Bureaucrat chief("Chief", 1);
	Bureaucrat mid("Mid", 40);
	Bureaucrat worker("Worker", 70);
	Bureaucrat gardener("Gardener", 140);
	Bureaucrat intern("Intern", 150);

	std::cout << &chief << std::endl;
	std::cout << &mid << std::endl;
	std::cout << &worker << std::endl;
	std::cout << &gardener << std::endl;
	std::cout << &intern << std::endl;

	printSection("SHRUBBERY TEST");
	ShrubberyCreationForm shrub("garden");
	std::cout << &shrub;
	intern.signForm(shrub);
	gardener.signForm(shrub);
	intern.executeForm(shrub);
	gardener.executeForm(shrub);
	chief.executeForm(shrub);

	printSection("ROBOTOMY TEST");
	RobotomyRequestForm robot("Bender");
	std::cout << &robot;
	worker.executeForm(robot);
	worker.signForm(robot);
	worker.executeForm(robot);
	mid.executeForm(robot);
	mid.executeForm(robot);

	printSection("PRESIDENTIAL PARDON TEST");
	PresidentialPardonForm pardon("Arthur Dent");
	std::cout << &pardon;
	mid.signForm(pardon);
	chief.signForm(pardon);
	mid.executeForm(pardon);
	chief.executeForm(pardon);

	printSection("GRADE INCREMENT/DECREMENT LIMITS");
	try {
		chief.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Chief increment failed: " << e.what() << std::endl;
	}
	try {
		intern.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "Intern decrement failed: " << e.what() << std::endl;
	}

	return (0);

}


