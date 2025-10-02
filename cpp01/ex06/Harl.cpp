/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:29:34 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 00:46:49 by igilbert         ###   ########.fr       */
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

Level toLevel(const std::string &lvl) {
	if (lvl == "DEBUG")		return DEBUG;
	if (lvl == "INFO")		return INFO;
    if (lvl == "WARNING")	return WARNING;
    if (lvl == "ERROR")		return ERROR;
    						return UNKNOWN;
}

void Harl::complain( std::string level ) {
	Level l = toLevel(level);
	switch(l) {
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break;
		default:
			std::cout << "the level " << level << " is unknown\n";
	}
}
