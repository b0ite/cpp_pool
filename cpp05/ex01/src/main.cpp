/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:12:45 by igilbert          #+#    #+#             */
/*   Updated: 2026/03/15 13:16:48 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	std::cout << "===== VALID FORM CONSTRUCTION =====" << std::endl;
	try
	{
		Form f("TaxForm", 50, 25);
		std::cout << &f;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "===== INVALID FORM CONSTRUCTION (GRADE TOO HIGH) =====" << std::endl;
	try
	{
		Form f("BadForm", 0, 25);
		std::cout << &f;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID FORM CONSTRUCTION (GRADE TOO LOW) =====" << std::endl;
	try
	{
		Form f("BadForm", 151, 25);
		std::cout << &f;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== BUREAUCRAT GRADE TOO LOW TO SIGN =====" << std::endl;
	try
	{
		Bureaucrat b("Bob", 100);
		Form f("TaxForm", 50, 25);
		std::cout << &b << std::endl;
		std::cout << &f;
		b.signForm(f);
		std::cout << &f;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== BUREAUCRAT GRADE HIGH ENOUGH TO SIGN =====" << std::endl;
	try
	{
		Bureaucrat b("Alice", 42);
		Form f("TaxForm", 50, 25);
		std::cout << &b << std::endl;
		std::cout << &f;
		b.signForm(f);
		std::cout << &f;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}