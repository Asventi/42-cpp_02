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

#include <iostream>

const int	Fixed::bits = 8;

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



