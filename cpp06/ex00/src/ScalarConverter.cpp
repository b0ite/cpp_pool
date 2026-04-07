/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:14:02 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 16:48:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void parseLiteral(const std::string& literal)
{
	bool isSpecial = (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff");
	bool sign;
	int hasDecimal = 0;
	bool isSingleChar;
	int i = 0;
	
	
	while (std::isspace(literal[i]))
		i++;
	isSingleChar = (literal[i + 1] == '\0' || literal[i + 1] == 'f') && std::isprint(literal[i]) && !std::isdigit(literal[i]);
	if (isSingleChar || isSpecial)
		return;
	sign = (literal[i] == '+' || literal[i] == '-');
	if (sign)
		i++;
	while (std::isdigit(literal[i]) || literal[i] == '.' || literal[i] == 'f')
	{
		if (literal[i] == '.')
		{
			hasDecimal++;
			if (hasDecimal > 1)
				throw std::invalid_argument("Invalid literal");
		}
		i++;
	}
	if (literal[i] != '\0')
		throw std::invalid_argument("Invalid literal");
	if (literal.empty())
		throw std::invalid_argument("Empty literal");
}

bool isUint(const std::string& literal)
{
	int i = 0;
	while (std::isspace(literal[i]))
		i++;
	if (literal[i] == '+')
		i++;
	while (std::isdigit(literal[i]))
		i++;
	if (literal[i] == '\0' || literal[i] == 'f')
		return true;
	return false;
}

bool displayableChar(const std::string& literal)
{
	int i = 0;
	while (std::isspace(literal[i]))
		i++;
	if (literal[i] == '+')
		i++;
	if ((literal[i + 1] == '\0' || literal[i + 1] == 'f') && std::isprint(literal[i]) && isUint(literal))
		return true;
	return false;
}

void printChar(const std::string& literal)
{
	if (displayableChar(literal))
	{
		if (isUint(literal))
			std::cout << "char: '" << static_cast<char>(std::strtol(literal.c_str(), NULL, 10)) << "'" << std::endl;
		else
			std::cout << "char: '" << literal[0] << "'" << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printFloat(const std::string& literal)
{
	try
	{
		float f = std::strtod(literal.c_str(), NULL);
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
}

void printDouble(const std::string& literal)
{
	try
	{
		double d = std::strtod(literal.c_str(), NULL);
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

void printInt(const std::string& literal)
{
	try
	{
		int i = std::strtol(literal.c_str(), NULL, 10);
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	try
	{
		parseLiteral(literal);
		printChar(literal);
		printInt(literal);
		printFloat(literal);
		printDouble(literal);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
}