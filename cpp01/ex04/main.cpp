/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:02:23 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 23:21:06 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {
	if (argc < 4)
	{
		std::cerr << "Wrong usage !\nUsage : " << argv[0] << " s1 s2" << std::endl;
		return (1);
	}
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "s1 mustn't be empty !" << std::endl;
		return (1);
	}
	if (s1 == s2)
	{
		std::cout << "1s and s2 are the same ;)\n";
	}
	std::cout << "ouverture du fichier\n";
	std::ifstream in(filename, std::ios::binary);
	if (!in) {
		std::cerr << "Can't open " << filename << std::endl;
		return (1);
	}
	std::cout << "fichier ouvert !\n";
	std::string content((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
	in.close();

	std::string out;
	const size_t n = content.size();
	const size_t size1 = s1.size();
	size_t i = 0;
	out.reserve(n);
	std::cout << "commencer a remplacer\n";
	while (i < n)
	{
		if (i + size1 < n && std::memcmp(content.data() + i, s1.data(), size1) == 0)
		{
			out.append(s2);
			i += size1;
		}
		else {
			out.push_back(content[i]);
			i++;
		}
	}
	std::cout << "tout est remplacé maintenant on met dans le fichier output\n";
	std::ofstream ofs(filename + ".replace", std::ios::binary);
	if (!ofs)
	{
		std::cerr << "Cannot open output file >:(\n";
		return (1);	 
	}
	ofs.write(out.data(), out.size());
	ofs.close();

	return (0);
}