/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 12:47:40 by igilbert          #+#    #+#             */
/*   Updated: 2026/03/15 13:20:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		this->gradeToSign = other.gradeToSign;
		this->gradeToExecute = other.gradeToExecute;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getIsSigned() const {
	return this->isSigned;
}

int AForm::getGradeToSign() const {
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const {
	return this->gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->gradeToSign) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

std::ostream	&operator<<(std::ostream &o, AForm *a)
{
	o << "AForm " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeToSign() <<
	"\n\texec-grade:\t" << a->getGradeToExecute() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}