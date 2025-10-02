/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:56:52 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 15:58:57 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int raw;
		static const int fracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed( int const n );
		Fixed( float const n );
		Fixed &operator = (const Fixed &other){
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &other) {
				raw = other.raw;
				 setRawBits(other.getRawBits());
			}
			return (*this);
		}
		~Fixed();
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, Fixed const& obj );

#endif