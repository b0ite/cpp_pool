/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:49:32 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 15:29:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	if (N <= 0)
	{
		std::cout << "N <= 0, un pointeur null va être retourné" << std::endl;
		return nullptr;
	}
	int	i = 0;
	Zombie* horde = new Zombie[N];
	while(i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}