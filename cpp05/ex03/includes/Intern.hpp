/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 15:50:54 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:45:28 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &formName, const std::string &target);

		class UnknownFormException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};


#endif
