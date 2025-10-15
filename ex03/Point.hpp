/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:32:17 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/15 15:32:17 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;

public:
	Fixed x() const;
	Fixed y() const;

	Point();
	Point(float x, float y);
	~Point();
	Point(const Point &pt);
	Point	&operator=(const Point &);
};

#endif