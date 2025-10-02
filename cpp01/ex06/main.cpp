/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:29:20 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 00:33:18 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int arc, char **arv) {
	if (arc < 2) {
		std::cerr << "Usage : " << arv[0] << " \"LEVEL\"\n";
		return 1;
	}
	Harl h;
	h.complain(arv[1]);
	return (0);
}