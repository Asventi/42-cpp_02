/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:36:41 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/30 16:36:41 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

const int	Fixed::_bits = 8;

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	_value = n << _bits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	_value = f * pow(2, _bits);
}

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &cpy): _value(cpy.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &e)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &e)
	{
		return *this;
	}
	_value = e.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float	Fixed::toFloat() const
{
	return (_value / 256.0f);
}

int Fixed::toInt() const
{
	return (_value / 256);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}




