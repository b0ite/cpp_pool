/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:49:30 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 15:27:56 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	
	private:
		std::string name;
	
	public:
		Zombie();
		void setName(std::string n);
		Zombie ( std::string name );
		~Zombie ( void );
		void announce( void ) const;
};

Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif