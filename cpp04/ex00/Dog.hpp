/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:20:55 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/04 13:26:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other) {
			if (this != &other) {
				Animal::operator=(other);
			}
			return (*this);
		}
		~Dog();

		void makeSound() const;
};

#endif