/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/15 15:32:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed Point::x() const
{
	return _x;
}

Fixed Point::y() const
{
	return _y;
}

Point::Point(): _x(0), _y(0) {}

Point::Point(float x, float y): _x(x), _y(y) {}

Point::Point(const Point &pt): _x(pt._x), _y(pt._y) {}

Point &Point::operator=(const Point &)
{
	return (*this);
}

Point::~Point() {};
