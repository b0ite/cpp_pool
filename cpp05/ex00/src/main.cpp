/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:12:45 by igilbert          #+#    #+#             */
/*   Updated: 2026/03/15 12:43:32 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(void)
{
	std::cout << "===== VALID CONSTRUCTION =====" << std::endl;
	try
	{
		Bureaucrat a("Alice", 2);
		std::cout << &a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CONSTRUCTION (TOO HIGH) =====" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << &b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INVALID CONSTRUCTION (TOO LOW) =====" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
		std::cout << &c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== INCREMENT TEST =====" << std::endl;
	try
	{
		Bureaucrat d("Diana", 2);
		std::cout << &d << std::endl;
		d.incrementGrade();
		std::cout << "After increment: " << &d << std::endl;
		d.incrementGrade();
		std::cout << "After increment: " << &d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== DECREMENT TEST =====" << std::endl;
	try
	{
		Bureaucrat e("Evan", 149);
		std::cout << &e << std::endl;
		e.decrementGrade();
		std::cout << "After decrement: " << &e << std::endl;
		e.decrementGrade();
		std::cout << "After decrement: " << &e << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

