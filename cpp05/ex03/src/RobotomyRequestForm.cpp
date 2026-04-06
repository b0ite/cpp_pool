/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:29:46 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/06 16:26:47 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Kenny") {};

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

std::string RobotomyRequestForm::getTarget(void) const {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned()){
		throw RobotomyRequestForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw RobotomyRequestForm::GradeTooLowException();
	}
	std::cout << "Bzzzzzz... Drilling noises..." << std::endl;
	if (rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Failed to robotomize " << this->getTarget() << "." << std::endl;
	}
}

const char *RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return "Grade too low to execute the form. must be at least 45.";
}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw() {
	return "Grade must be between 1 and 150.";
}

const char *RobotomyRequestForm::FormNotSignedException::what() const throw() {
	return "Form not signed.";
}
