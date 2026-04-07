/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:50:26 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 16:50:27 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./convert <literal1> [literal2 ...]" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; ++i)
    {
        std::cout << "---- test " << i << " ----" << std::endl;
        ScalarConverter::convert(argv[i]);
    }
    return 0;
}