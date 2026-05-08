/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:56:57 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/08 13:09:03 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <exception>
# include <iostream>
# include <string>
# include <list>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadData(void);
		bool isValidDate(std::string date);
		double isValidValue(std::string value);
		void exec(std::string param);
		void printExchange(std::string date, double value);
		

		class FileException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Error: Could not open file.";
				}
		};

		class LineException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid file format.";
				}
		};

		class PriceException : public std::exception {
			public:
				virtual const char* what() const throw()
				{
					return "Error: Invalid price value.";
				}
		};
};

#endif
