/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:25 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 15:31:05 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Static construction test ===\n";
    {
        FragTrap s("StaticFrag");
        s.attack("TargetA");
        s.beRepaired(5);
        s.takeDamage(3);
        s.highFivesGuys();
    }

    std::cout << "\n=== Copy & assignment ===\n";
    {
        FragTrap original("OriginalFrag");
        original.attack("TargetX");
        FragTrap copy(original);
        FragTrap assigned("AssignedFrag");
        assigned = original;
        copy.attack("CopyTarget");
        assigned.highFivesGuys();
    }

    std::cout << "\n=== Dynamic polymorphism test ===\n";
    {
        ClapTrap *p = new FragTrap("DynFrag");
        p->attack("TargetDyn");
        p->takeDamage(20);
        delete p;
    }

    std::cout << "\n=== Energy depletion test ===\n";
    {
        FragTrap e("EnergyFrag");
        for (int i = 0; i < 10; ++i) {
            std::cout << "Attempt attack #" << (i + 1) << '\n';
            e.attack("DrainTarget");
        }
    }

    std::cout << "\n=== Death & post-death behavior ===\n";
    {
        FragTrap fragile("Fragile");
        fragile.takeDamage(1000);
        fragile.attack("Nobody");
        fragile.beRepaired(10);
        fragile.highFivesGuys();
    }

    return 0;
}