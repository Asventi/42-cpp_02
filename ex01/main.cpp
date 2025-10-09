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
#include <climits>

int	main()
{
	float	initial = -42.576;
	Fixed	a(initial);

	std::cout << "Number initiated with: " << initial << '\n';
	std::cout << "Raw bits: " << a.getRawBits() << "\n\n";
	std::cout << "To float: " << a.toFloat() << "\tTo int: " << a.toInt() << '\n';
}
