/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:56:45 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 15:54:03 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	raw = 0;
}

Fixed::Fixed( int const n ) : raw(n << fracBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : raw(roundf(n * (1 << fracBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : raw(other.raw){
	std::cout << "Copy constructor called" << std::endl;	
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (raw);
}

void Fixed::setRawBits( int const raw ) {
	this->raw = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)((float)raw / (float)(1 << fracBits)));
}

int Fixed::toInt( void ) const {
	return (raw >> fracBits);
}

std::ostream& operator << ( std::ostream& os, Fixed const& obj ) {
	os << obj.toFloat(); return os;
}