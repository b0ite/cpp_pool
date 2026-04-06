/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:19:00 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:30:24 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->grade = other.grade;
		this->name = other.name;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade <= 1) {
		throw GradeTooHighException();
	}
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade >= 150) {
		throw GradeTooLowException();
	}
	this->grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low: grade must be between 1 and 150.";
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high: grade must be between 1 and 150.";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{	o << a->getName() << ", bureaucrat grade " << a->getGrade() << ".";
	return o;
}
