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
	_value = n << _bits;
}

Fixed::Fixed(const float f)
{
	_value = f * powf(2, _bits);
}

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed &cpy): _value(cpy.getRawBits())
{
}

Fixed &Fixed::operator=(const Fixed &e)
{
	if (this == &e)
	{
		return *this;
	}
	_value = e.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
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

std::ostream &operator<<(std::ostream &os, const Fixed &fix)
{
	os << fix.toFloat();
	return (os);
}

bool	Fixed::operator<(const Fixed &fix) const
{
	return (getRawBits() < fix.getRawBits());
}

bool	Fixed::operator>(const Fixed &fix) const {return (fix < *this);}
bool	Fixed::operator>=(const Fixed &fix) const {return !(*this < fix);}
bool	Fixed::operator<=(const Fixed &fix) const {return !(*this > fix);}

bool Fixed::operator==(const Fixed &fix) const
{
	return (getRawBits() == fix.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fix) const {return !(*this == fix);}



Fixed &Fixed::operator++()
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return (old);
}

Fixed &Fixed::operator--()
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return (old);
}

Fixed Fixed::operator+(const Fixed &r) const
{
	Fixed old = *this;
	old._value += r._value;
	return (old);
}

Fixed Fixed::operator-(const Fixed &r) const
{
	Fixed old = *this;
	old._value -= r._value;
	return (old);
}

Fixed Fixed::operator/(const Fixed &r) const
{
	Fixed	old = *this;
	float	res;

	res = static_cast<float>(old._value) / r._value;
	old._value = roundf(res * powf(2, _bits));
	return (old);
}

Fixed Fixed::operator*(const Fixed &r) const
{
	Fixed old = *this;
	old._value *= r._value;
	old._value /= powf(2, _bits);
	return (old);
}

const Fixed &Fixed::min(const Fixed &l, const Fixed &r)
{
	if (l < r)
		return (l);
	return (r);
}

Fixed &Fixed::min(Fixed &l, Fixed &r)
{
	if (l < r)
		return (l);
	return (r);
}

const Fixed &Fixed::max(const Fixed &l, const Fixed &r)
{
	if (l > r)
		return (l);
	return (r);
}

Fixed &Fixed::max(Fixed &l, Fixed &r)
{
	if (l > r)
		return (l);
	return (r);
}
