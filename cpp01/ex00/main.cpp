#include "Zombie.hpp"
#include <array>
#include <iostream>
#include <random>

int rand_int(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}

void message(std::string message){
	std::cout << message << std::endl;
}

int main() {
	std::array<std::string, 5> names = {
		"Tristan",
		"Faustine",
		"Marie",
		"Ivan",
		"IBG"
	};

	message("test de la classe Zombie et de ses fonctions");
	Zombie z(names[rand_int(0, 4)]);
	z.announce();
	message("P.S. : celui là va mourir tout seul a la fin du programme...");
	randomChump(names[rand_int(0, 4)]);
	Zombie* z2 = newZombie(names[rand_int(0, 4)]);
	z2->announce();
	message("et on le tue. *brandit sa machete modifiée*");
	delete z2;
	z2 = nullptr;
	message("Maintenant au tour du premier...");
	return 0;
}