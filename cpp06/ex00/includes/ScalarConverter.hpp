/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:14:06 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 18:18:12 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>


class ScalarConverter
{
	public:
	static void convert(const std::string& literal);
};

#endif
