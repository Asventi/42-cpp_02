/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:47:50 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/15 16:47:50 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	const Fixed	d1((b.x() - a.x()) * (p.y() - a.y()) - (b.y() - a.y()) * (p.x() - a.x()));
	const Fixed	d2((c.x() - b.x()) * (p.y() - b.y()) - (c.y() - b.y()) * (p.x() - b.x()));
	const Fixed	d3((a.x() - c.x()) * (p.y() - c.y()) - (a.y() - c.y()) * (p.x() - c.x()));

	if (d1.toFloat() > 0 && d2.toFloat() > 0 && d3.toFloat() > 0)
		return (true);
	if (d1.toFloat() < 0 && d2.toFloat() < 0 && d3.toFloat() < 0)
		return (true);
	return (false);
}