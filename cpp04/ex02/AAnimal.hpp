/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:20:24 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:16:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "Brain.hpp"
#include <string>
#include <iostream>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		void setType(const std::string& type);
		std::string getType() const;
};

#endif
