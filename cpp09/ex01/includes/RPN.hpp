/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:11:55 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/10 15:54:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPM_HPP
#define RPM_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN (const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void evaluate(const std::string& expression);

	private:
		std::stack<int> _stack;
		void _performOperation(const std::string& op);
		bool _isOperator(const std::string& token);
		int _parseNumber(const std::string& token);
};

#endif
