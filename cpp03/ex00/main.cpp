/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:25 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 12:34:23 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int main() {
	ClapTrap bot1 = ClapTrap("George Droid");
	
	bot1.attack("Charlie Clanker");
	bot1.takeDamage();
	bot1.beRepaired();
}