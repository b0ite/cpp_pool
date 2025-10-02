/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:56:49 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 20:04:52 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    Point A(0.0f, 0.0f);
    Point B(10.0f, 0.0f);
    Point C(0.0f, 10.0f);

    Point P_inside(2.0f, 2.0f);

    Point P_on_edge(5.0f, 0.0f);

    Point P_outside(10.0f, 10.0f);

    Point D1(0.0f, 0.0f);
    Point D2(1.0f, 1.0f);
    Point D3(2.0f, 2.0f);
    Point P_any(1.0f, 0.0f);

    std::cout << "Inside test: " << (bsp(A, B, C, P_inside) ? "true" : "false") << std::endl;
    std::cout << "On edge test: " << (bsp(A, B, C, P_on_edge) ? "true" : "false") << std::endl;
    std::cout << "Outside test: " << (bsp(A, B, C, P_outside) ? "true" : "false") << std::endl;

    std::cout << "Degenerate triangle test: " << (bsp(D1, D2, D3, P_any) ? "true" : "false") << std::endl;

    return 0;
}