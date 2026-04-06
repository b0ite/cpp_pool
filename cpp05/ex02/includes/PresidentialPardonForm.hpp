/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:29:38 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:19:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

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

#endif
