/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:36:48 by pjarnac           #+#    #+#             */
/*   Updated: 2025/04/30 16:36:48 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int	main()
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	a.setRawBits(42);
	std::cout << "[a] raw bits: " << a.getRawBits() << '\n';
	std::cout << "[b] raw bits: " << b.getRawBits() << '\n';
	b = a;
	std::cout << "[b] raw bits: " << b.getRawBits() << '\n';
	c.setRawBits(54);
	std::cout << "[c] raw bits: " << c.getRawBits() << '\n';
	Fixed	d(c);
	std::cout << "[d] raw bits: " << d.getRawBits() << '\n';
}
