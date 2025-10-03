/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:25 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 17:01:47 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "╔════════════════════════════════════════╗\n";
    std::cout << "║    DIAMONDTRAP CONSTRUCTION TEST       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap diamond("Sparkle");
        std::cout << "\n--- Stats verification ---\n";
        std::cout << "HP: " << diamond.getHealth() << " (expected: 100 from FragTrap)\n";
        std::cout << "Energy: " << diamond.getEnergy() << " (expected: 50 from ScavTrap)\n";
        std::cout << "Attack: " << diamond.getAttack() << " (expected: 30 from FragTrap)\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       WHOAMI TEST                      ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap bob("Bob");
        bob.whoAmI();
        std::cout << "\nExpected:\n";
        std::cout << "  DiamondTrap name: Bob\n";
        std::cout << "  ClapTrap name: Bob_clap_name\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       ATTACK TEST (ScavTrap)           ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap attacker("Destroyer");
        attacker.attack("Target1");
        attacker.attack("Target2");
        std::cout << "Energy after 2 attacks: " << attacker.getEnergy() << " (expected: 48)\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       INHERITED FUNCTIONS TEST         ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap multi("Multi");
        std::cout << "\n--- Testing ScavTrap's guardGate() ---\n";
        multi.guardGate();
        
        std::cout << "\n--- Testing FragTrap's highFivesGuys() ---\n";
        multi.highFivesGuys();
        
        std::cout << "\n--- Testing ClapTrap's takeDamage() & beRepaired() ---\n";
        multi.takeDamage(20);
        std::cout << "HP after damage: " << multi.getHealth() << "\n";
        multi.beRepaired(15);
        std::cout << "HP after repair: " << multi.getHealth() << "\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       COPY CONSTRUCTOR TEST            ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap original("Original");
        original.takeDamage(30);
        std::cout << "\n--- Creating copy ---\n";
        DiamondTrap copy(original);
        std::cout << "\nOriginal HP: " << original.getHealth() << "\n";
        std::cout << "Copy HP: " << copy.getHealth() << " (should be same)\n";
        copy.whoAmI();
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       ASSIGNMENT OPERATOR TEST         ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap a("Alpha");
        DiamondTrap b("Beta");
        a.takeDamage(50);
        std::cout << "\n--- Before assignment ---\n";
        std::cout << "A HP: " << a.getHealth() << "\n";
        std::cout << "B HP: " << b.getHealth() << "\n";
        
        std::cout << "\n--- After b = a ---\n";
        b = a;
        std::cout << "A HP: " << a.getHealth() << "\n";
        std::cout << "B HP: " << b.getHealth() << " (should match A)\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       ENERGY DEPLETION TEST            ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap exhausted("Tired");
        std::cout << "Initial energy: " << exhausted.getEnergy() << "\n\n";
        for (int i = 0; i < 52; ++i) {
            std::cout << "Attack #" << (i + 1) << ": ";
            exhausted.attack("Dummy");
        }
        std::cout << "\nFinal energy: " << exhausted.getEnergy() << "\n";
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       DEATH TEST                       ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        DiamondTrap mortal("Fragile");
        mortal.takeDamage(1000);
        std::cout << "\n--- Actions after death ---\n";
        mortal.attack("Ghost");
        mortal.beRepaired(50);
        mortal.highFivesGuys();
        mortal.guardGate();
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       POLYMORPHISM TEST                ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";
    {
        std::cout << "--- DiamondTrap as ClapTrap* ---\n";
        ClapTrap* ptr = new DiamondTrap("Poly");
        ptr->attack("PolyTarget");  // Should call ScavTrap's attack
        delete ptr;
        
        std::cout << "\n--- DiamondTrap as FragTrap* ---\n";
        FragTrap* fptr = new DiamondTrap("PolyFrag");
        fptr->highFivesGuys();
        delete fptr;
        
        std::cout << "\n--- DiamondTrap as ScavTrap* ---\n";
        ScavTrap* sptr = new DiamondTrap("PolyScav");
        sptr->guardGate();
        sptr->attack("ScavTarget");
        delete sptr;
    }

    std::cout << "\n╔════════════════════════════════════════╗\n";
    std::cout << "║       ALL TESTS COMPLETED ✓            ║\n";
    std::cout << "╚════════════════════════════════════════╝\n";

    return 0;
}