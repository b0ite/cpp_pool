/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:20:55 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/29 16:01:09 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public Animal {
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other) {
			if (this != &other) {
				Animal::operator=(other);
				delete brain;
				brain = new Brain(*other.brain);
			}
			return (*this);
		}
		~Dog();

		void makeSound() const;
};

#endif