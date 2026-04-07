/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:14:02 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 18:17:57 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static std::string trimLeft(const std::string& literal)
{
	size_t i = 0;
	while (i < literal.length() && std::isspace(static_cast<unsigned char>(literal[i])))
		i++;
	return literal.substr(i);
}

static bool isSpecialLiteral(const std::string& literal)
{
	return (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf"
		|| literal == "+inff" || literal == "-inff");
}

static bool isCharLiteral(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	return (trimmed.length() == 1
		&& std::isprint(static_cast<unsigned char>(trimmed[0]))
		&& !std::isdigit(static_cast<unsigned char>(trimmed[0])));
}

static bool isIntegerLiteral(const std::string& literal)
{
	char* end = NULL;
	std::string trimmed = trimLeft(literal);
	long value;

	if (trimmed.empty())
		return false;

	errno = 0;
	value = std::strtol(trimmed.c_str(), &end, 10);

	if (end != trimmed.c_str() && errno != ERANGE)
	{
		while (*end && std::isspace(static_cast<unsigned char>(*end)))
			end++;
		if (*end == '\0' && value >= INT_MIN && value <= INT_MAX)
			return true;
	}

	double dvalue = std::strtod(trimmed.c_str(), &end);
	if (end != trimmed.c_str())
	{
		if (dvalue == static_cast<double>(static_cast<int>(dvalue)))
		{
			while (*end && std::isspace(static_cast<unsigned char>(*end)))
				end++;
			if (*end == '\0' || (*end == 'f' && end[1] == '\0'))
				return true;
		}
	}
	return false;
}

void parseLiteral(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	if (trimmed.empty())
		throw std::invalid_argument("Empty literal");
	if (isSpecialLiteral(trimmed) || isCharLiteral(trimmed) || isIntegerLiteral(trimmed))
		return;
	if (trimmed[0] == '+' || trimmed[0] == '-' || std::isdigit(static_cast<unsigned char>(trimmed[0])))
	{
		char* end = NULL;
		std::strtod(trimmed.c_str(), &end);
		if (end == trimmed.c_str())
			throw std::invalid_argument("Invalid literal");
		while (*end && std::isspace(static_cast<unsigned char>(*end)))
			end++;
		if (*end == '\0' || (*end == 'f' && end[1] == '\0'))
			return;
	}
	throw std::invalid_argument("Invalid literal");
}

bool displayableChar(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);
	if (isCharLiteral(trimmed))
		return true;
	if (!isIntegerLiteral(trimmed))
		return false;
	char* end = NULL;
	long value = std::strtol(trimmed.c_str(), &end, 10);
	return (value >= 0 && value <= 127 && std::isprint(static_cast<unsigned char>(value)));
}

void printChar(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	if (isSpecialLiteral(trimmed))
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	if (isCharLiteral(trimmed))
	{
		std::cout << "char: '" << trimmed[0] << "'" << std::endl;
		return;
	}
	if (isIntegerLiteral(trimmed))
	{
		char* end = NULL;
		long value = std::strtol(trimmed.c_str(), &end, 10);

		if (value < 0 || value > 127)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(static_cast<unsigned char>(value)))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		return;
	}
	std::cout << "char: impossible" << std::endl;
}

void printFloat(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	if (trimmed == "nan" || trimmed == "nanf" || trimmed == "+inf" || trimmed == "+inff"
		|| trimmed == "-inf" || trimmed == "-inff")
	{
		if (trimmed[trimmed.length() - 1] == 'f')
			std::cout << "float: " << trimmed << std::endl;
		else
			std::cout << "float: " << trimmed << "f" << std::endl;
		return;
	}
	if (isCharLiteral(trimmed))
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(trimmed[0]) << "f" << std::endl;
		return;
	}
	{
		double value = std::strtod(trimmed.c_str(), NULL);
		float fvalue = static_cast<float>(value);
		if (fvalue == static_cast<float>(static_cast<int>(fvalue)))
			std::cout << "float: " << std::fixed << std::setprecision(1) << fvalue << "f" << std::endl;
		else
			std::cout << "float: " << fvalue << "f" << std::endl;
	}
}

void printDouble(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	if (trimmed == "nan" || trimmed == "+inf" || trimmed == "-inf")
	{
		std::cout << "double: " << trimmed << std::endl;
		return;
	}
	if (trimmed == "nanf" || trimmed == "+inff" || trimmed == "-inff")
	{
		std::cout << "double: " << trimmed.substr(0, trimmed.length() - 1) << std::endl;
		return;
	}
	if (isCharLiteral(trimmed))
	{
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(trimmed[0]) << std::endl;
		return;
	}
	{
		double value = std::strtod(trimmed.c_str(), NULL);
		if (value == static_cast<double>(static_cast<int>(value)))
			std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		else
			std::cout << "double: " << value << std::endl;
	}
}

void printInt(const std::string& literal)
{
	std::string trimmed = trimLeft(literal);

	if (isSpecialLiteral(trimmed))
	{
		std::cout << "int: impossible" << std::endl;
		return;
	}
	if (isCharLiteral(trimmed))
	{
		std::cout << "int: " << static_cast<int>(static_cast<unsigned char>(trimmed[0])) << std::endl;
		return;
	}
	{
		double dvalue = std::strtod(trimmed.c_str(), NULL);
		if (dvalue < static_cast<double>(INT_MIN) || dvalue > static_cast<double>(INT_MAX))
		{
			std::cout << "int: impossible" << std::endl;
			return;
		}
		std::cout << "int: " << static_cast<int>(dvalue) << std::endl;
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