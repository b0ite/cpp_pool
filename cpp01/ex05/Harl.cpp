/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:29:34 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 00:51:02 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
	std::cout << "Mais ils ont pris de la drogue les developpeurs ?!?!?\n";
}

void Harl::info() {
	std::cout << "Il est très salé le serrano Joan !\n";
}

void Harl::warning() {
	std::cout << "je vous l'avais bien dit que Laink et Terracid ils étaient de droite\n";
}

void Harl::error() {
	std::cout << "mais Fred, tu peux pas dire un truc comme ça enfin !!! *ban twitch de 14 jours*\n";
}

void Harl::complain( std::string level ) {
	size_t i = 0;
	typedef void (Harl::*Fn)(void);
	static const std::pair<std::string, Fn> table[] = {
		std::pair<std::string, Fn>("DEBUG", &Harl::debug),
		std::pair<std::string, Fn>("INFO",  &Harl::info),
		std::pair<std::string, Fn>("WARNING",&Harl::warning),
		std::pair<std::string, Fn>("ERROR", &Harl::error)
	};
	const size_t tableSize = sizeof(table) / sizeof(table[0]);
	while (i < tableSize)
	{
		if (table[i].first == level) {
			(this->*(table[i].second))();
			return ;
		}
		i++;
	}
	std::cout << "the level " << level << " is unknown\n";
}
