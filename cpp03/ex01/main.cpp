/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:25 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 14:03:15 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

int main() {
	ClapTrap bot1("George Droid");
	
	bot1.attack("Charlie Clanker");
	bot1.takeDamage(5);
	bot1.beRepaired(10);
	
	bot1.takeDamage(500);
	bot1.beRepaired(10);
	bot1.attack("Charlie Clanker");
	return (0);
}