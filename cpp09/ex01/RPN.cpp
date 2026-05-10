/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:11:53 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/10 15:59:16 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::_performOperation(const std::string& op)
{
	if (op == "+" || op == "-" || op == "*" || op == "/")
	{
		if (_stack.size() < 2)
			throw std::runtime_error("Error: Not enough operands for operation '" + op + "'.");
		int b = _stack.top(); _stack.pop();
		int a = _stack.top(); _stack.pop();
		int result;
		if (op == "+")
			result = a + b;
		else if (op == "-")
			result = a - b;
		else if (op == "*")
			result = a * b;
		else
		{
			if (b == 0)
				throw std::runtime_error("Error: Division by zero.");
			result = a / b;
		}
		_stack.push(result);
	}
	else
		throw std::runtime_error("Error: Invalid operator '" + op + "'.");
}

bool RPN::_isOperator(const std::string& token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::_parseNumber(const std::string& token)
{	try
	{
		size_t pos;
		int num = std::stoi(token, &pos);
		if (pos != token.length())
			throw std::runtime_error("Error: Invalid token '" + token + "'.");
		return num;
	}
	catch (const std::invalid_argument&)
	{
		throw std::runtime_error("Error: Invalid token '" + token + "'.");
	}
	catch (const std::out_of_range&)
	{
		throw std::runtime_error("Error: Number out of range in token '" + token + "'.");
	}
}

void RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token)
	{
		if (_isOperator(token))
			_performOperation(token);
		else
			_stack.push(_parseNumber(token));
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error: Invalid RPN expression.");
	std::cout << "Result: " << _stack.top() << std::endl;
}