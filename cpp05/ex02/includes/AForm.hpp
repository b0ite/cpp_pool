/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:47:28 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:37:48 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		std::string name;
		bool isSigned;
		int gradeToSign;
		int gradeToExecute;
	public:
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) const = 0;

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
};

std::ostream	&operator<<(std::ostream &o, AForm *a);

#endif
