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

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

Fixed::Fixed(const int n)
{
	_value = n << 8;
	if (n < 0)
		_value |= 1 << 31;
	else
		_value &= ~(1 << 31);
}

Fixed::Fixed(const float f)
{
	int		n = static_cast<int>(f);

	if (n > 0)
	{
		if ((n >> (32 - (_bits  + 1))) != 0)
			std::cerr << "[ Warning ] Initial integer part is too big, it will lose accuracy\n";
	}
	else if (~(n >> (32 - (_bits + 1))) != 0)
		std::cerr << "[ Warning ] Initial integer part is too big, it will lose accuracy\n";
	_value = n << _bits;
	if (n < 0)
		_value |= 1 << 31;
	else
		_value &= ~(1 << 31);
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



