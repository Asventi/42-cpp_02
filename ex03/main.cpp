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

#include "Point.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

bool	bsp(const Point a, const Point b, const Point c, const Point p);

TEST_CASE("Classic triangle")
{
	CHECK(bsp(Point(0, 0), Point(1, 0), Point(0.5f, 1), Point(0.5f, 0.5f)) == true);
	CHECK(bsp(Point(0, 0), Point(1, 0), Point(-0.5f, 1), Point(0.5f, 0.5f)) == false);
	CHECK(bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.5f, 0.5f)) == false);
}

TEST_CASE("Flat triangle")
{
	CHECK(bsp(Point(0, 0), Point(1, 0), Point(0.5f, 0), Point(0.5f, 0)) == false);
	CHECK(bsp(Point(0, 0), Point(1, 0), Point(0.5f, 0), Point(0, 0)) == false);
}