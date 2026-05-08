/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 11:57:01 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/08 13:20:59 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	loadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->data = other.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadData(void) {
	std::ifstream file("./data/data.csv");
	if (!file.is_open()) {
		throw FileException();
	}
	std::string line;
	std::getline(file, line);
	if (line != "date,exchange_rate") {
		throw LineException();
	}
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string value;
		double price;
		if (std::getline(iss, date, ',') && std::getline(iss, value)) {
			double price;
			std::istringstream valueStream(value);
			if (!(valueStream >> price))
			{
				throw PriceException();
			}
			data[date] = price;
		}
	}
	file.close();
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ') {
		std::cout << "Error: Invalid date format => " << date << std::endl;
		return false;
	}
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	int year, month, day;
	std::istringstream yearStream(yearStr);
	std::istringstream monthStream(monthStr);
	std::istringstream dayStream(dayStr);
	if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)) {
		std::cout << "Error: Invalid date format => " << date << std::endl;
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error: Invalid date => " << date << std::endl;
		return false;
	}
	if ((month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)) {
		std::cout << "Error: Invalid date => " << date << std::endl;
		return false;
	}
	return true;
}

double BitcoinExchange::isValidValue(std::string value) {
	double price;
	std::istringstream valueStream(value);
	if (!(valueStream >> price) || price < 0 || price > 1000) {
		std::cout << "Error: Invalid value => " << value << std::endl;
		return -1;
	}
	return price;
}

void BitcoinExchange::printExchange(std::string date, double value) {
	std::map<std::string, double>::iterator it = data.lower_bound(date);
	if (it == data.end()) {
		--it;
	}
	if (it->first > date && it != data.begin()) {
		if (it == data.begin()) {
			std::cout << "Error: No exchange rate available for date => " << date << std::endl;
			return;
		}
		--it;
	}
	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::exec(std::string param) {
	std::ifstream file(param.c_str());
	if (!file.is_open()) {
		throw FileException();
	}
	std::string line;
	std::getline(file, line);
	if (line != "date | value") {
		throw LineException();
	}
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date, value;
		if (std::getline(iss, date, '|') && std::getline(iss, value)) {
			if (!isValidDate(date) || isValidValue(value) == -1) {
				continue;
			}
			printExchange(date, isValidValue(value));
		}
		if (date.empty() || value.empty()) {
			std::cout << "Error: Invalid line format => " << line << std::endl;
			continue;
		}
	}
	file.close();
}
