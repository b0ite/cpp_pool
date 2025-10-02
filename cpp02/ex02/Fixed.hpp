/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:56:52 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/02 17:06:16 by igilbert         ###   ########.fr       */
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
			//std::cout << "Copy assignment operator called" << std::endl;
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
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		bool operator>(Fixed const& other) const;
		bool operator<(Fixed const& other) const;
		bool operator>=(Fixed const& other) const;
		bool operator<=(Fixed const& other) const;
		bool operator==(Fixed const& other) const;
		bool operator!=(Fixed const& other) const;

		Fixed operator+(Fixed const& other) const;
		Fixed operator-(Fixed const& other) const;
		Fixed operator*(Fixed const& other) const;
		Fixed operator/(Fixed const& other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

};

std::ostream& operator<<( std::ostream& os, Fixed const& obj );


#endif