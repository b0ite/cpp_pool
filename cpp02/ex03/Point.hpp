/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:20:36 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 19:25:17 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point() : x(0), y(0) {
		}
		Point(const float x, const float y) : x(x), y(y) {
		}
		Point(const Point &other) : x(other.x), y(other.y) {
		}
		Point &operator=(const Point &other) {
			(void)other;
			return *(this);
		}
		~Point();

		const Fixed& getX() const { return x; }
		const Fixed& getY() const { return y; }
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif