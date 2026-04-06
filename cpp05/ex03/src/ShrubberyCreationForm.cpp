/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:29:48 by igilbert          #+#    #+#             */
/*   Updated: 2026/03/16 14:23:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned()) {
		throw AForm::GradeTooLowException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "Error: Could not create file." << std::endl;
		return;
	}
	file << "                                              .      \n";
	file << "                                   .         ;       \n";
	file << "      .              .              ;%     ;;        \n";
	file << "        ,           ,                :;%  %;         \n";
	file << "         :         ;                   :;%;'     .,  \n";
	file << "          %;     %;            ;        %;'    ,;    \n";
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'     \n";
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'      \n";
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'        \n";
	file << "     `%;.     ;%;     %;'         `;%%;.%;'          \n";
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'             \n";
	file << "         `:%;.  :;bd%;          %;@%;'               \n";
	file << "           `@%:.  :;%.         ;@@%;'                \n";
	file << "             `@%.  `;@%.      ;@@%;                  \n";
	file << "               `@%%. `@%%    ;@@%;                   \n";
	file << "                 ;@%. :@%%  %@@%;                    \n";
	file << "                   %@bd%%%bd%%:;                     \n";
	file << "                     #@%%%%%:;;                      \n";
	file << "                     %@@%%%::;                       \n";
	file << "                     %@@@%(o);  . '                  \n";
	file << "                     %@@@o%;:(.,'                    \n";
	file << "                 `.. %@@@o%::;                       \n";
	file << "                    `)@@@o%::;                       \n";
	file << "                     %@@(o)::;                       \n";
	file << "                    .%@@@@%::;                       \n";
	file << "                    ;%@@@@%::;.                      \n";
	file << "                   ;%@@@@%%:;;;.                     \n";
	file << "               ...;%@@@@@%%:;;;;,..                  \n";
	file.close();
}

std::string	ShrubberyCreationForm::getTarget(void)const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "Form " << a->getName() <<
	":\n\tsign-grade:\t" << a->getGradeToSign() <<
	"\n\texec-grade:\t" << a->getGradeToExecute() <<
	"\n\tis signed:\t" << a->getIsSigned() <<
	std::endl;
	return (o);
}