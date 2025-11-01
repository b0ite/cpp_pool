/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:20:43 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/29 15:55:32 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other) {
			if (this != &other) {
				Animal::operator=(other);
				delete brain;
				brain = new Brain(*other.brain);
			}
			return (*this);
		}
		~Cat();

		void makeSound() const;
};

#endif