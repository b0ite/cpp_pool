/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:20:26 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 19:59:45 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed s0 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	Fixed s1 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	Fixed s2 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());
	
	if (s0 == Fixed(0) && s1 == Fixed(0) && s2 == Fixed(0))
        return false;
	bool all_nonneg = (s0 >= Fixed(0) && s1 >= Fixed(0) && s2 >= Fixed(0));
    bool all_nonpos = (s0 <= Fixed(0) && s1 <= Fixed(0) && s2 <= Fixed(0));
	return (all_nonneg || all_nonpos);
}