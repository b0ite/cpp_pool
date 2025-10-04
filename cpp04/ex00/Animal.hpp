/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:20:24 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/04 13:57:16 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other) {
			if (this != &other) {
				type = other.type;
			}
			return (*this);
		}
		virtual ~Animal();

		virtual void makeSound() const;
		void setType(std::string type);
		std::string getType() const;
};

#endif