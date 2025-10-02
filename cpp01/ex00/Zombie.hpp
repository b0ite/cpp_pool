/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:59:34 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 14:33:03 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	
	private:
		std::string name;
	
	public:
		Zombie ( std::string name );
		~Zombie ( void );
		void announce( void ) const;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif