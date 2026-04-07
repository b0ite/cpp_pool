/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:45:42 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 18:57:22 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

void tester()
{
    Base *surprise_base = generate();
    
    if ( !surprise_base )
	{
        std::cout << "Error: generate() returned NULL" << std::endl;
        return ;
    }
    
    std::cout << "Pointer identification: ";
    identify( surprise_base );
    
    std::cout << "Reference identification: ";
    identify( *surprise_base );
    
    delete surprise_base;

}

int main( void )
{
    std::cout << "<<=== Dynamic Cast Tester ===>>\n" << std::endl;
    
    int amount_test = 10;
	srand(time(NULL));
    for ( int i = 1; i <= amount_test; ++i )
	{ 
        std::cout << "-->> Run " << i << ":" << std::endl;
        tester();
        std::cout << std::endl;
    }

    return ( 0 );
}