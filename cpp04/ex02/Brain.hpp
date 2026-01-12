/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:21:32 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:35:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string	ideas[100];
		Brain( std::string );
	public:
		~Brain();
		Brain();
		Brain( Brain const & copy );
		Brain & operator=( Brain const & instance );
};

#endif
