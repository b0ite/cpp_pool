/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:29:56 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:19:47 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class From;

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		std::string getTarget(void) const;
		void execute(const Bureaucrat &executor) const;
		
		class GradeTooLowException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);

#endif
