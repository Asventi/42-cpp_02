/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:36:41 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/30 16:36:41 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
	static const int	_bits;
	int					_value;

public:
	int		getRawBits() const;
	void	setRawBits(int raw);
	float	toFloat() const;
	int		toInt() const;

	bool	operator<(const Fixed& fix) const;
	bool	operator>(const Fixed& fix) const;
	bool	operator>=(const Fixed& fix) const;
	bool	operator<=(const Fixed& fix) const;

	bool	operator==(const Fixed& fix) const;
	bool	operator!=(const Fixed& fix) const;

	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	Fixed	operator+(const Fixed &r) const;
	Fixed	operator-(const Fixed &r) const;
	Fixed	operator/(const Fixed &r) const;
	Fixed	operator*(const Fixed &r) const;

	static Fixed		&min(Fixed &l, Fixed &r);
	static const Fixed	&min(const Fixed &l, const Fixed &r);
	static Fixed		&max(Fixed &l, Fixed &r);
	static const Fixed	&max(const Fixed &l, const Fixed &r);

	explicit Fixed(int n);
	explicit Fixed(float f);
	Fixed();
	~Fixed();
	Fixed(const Fixed &cpy);
	Fixed &operator=(const Fixed &e);
};

std::ostream &operator<<(std::ostream &os, const Fixed& fix);

#endif
