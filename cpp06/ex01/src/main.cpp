/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:24:56 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/07 18:28:22 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/data.hpp"

int main()
{
    Data d;
    d.str = "bonjour";
    d.num = 42;

    void* original = &d;
    uintptr_t raw = Serializer::serialize(original);
    void* restored = Serializer::deserialize(raw);

    std::cout << "original : " << original << std::endl;
    std::cout << "restored : " << restored << std::endl;
    std::cout << "same ptr : " << (original == restored) << std::endl;

    Data* p = static_cast<Data*>(restored);
    std::cout << "str=" << p->str << ", num=" << p->num << std::endl;
    return 0;
}