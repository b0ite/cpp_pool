/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:32 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:35:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain( Brain const & copy ) {
	*this = copy;
	std::cout << "Brain copied" <<  std::endl;
}

Brain & Brain::operator=( Brain const & instance ) {
	if (this != &instance) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = instance.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}
