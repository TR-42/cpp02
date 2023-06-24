/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:10:41 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 19:08:50 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Fixed.hpp"

class Point
{
private:
	Fixed x;
	Fixed y;

public:
	Point();
	Point(const Point& from);
	Point(const Fixed& x, const Fixed& y);
	Point(const float& x, const float& y);
	~Point();

	Point& operator=(const Point& from);

	Point operator-(const Point& other) const;

	Fixed crossProd(const Point& other) const;

	Fixed getX() const;
	Fixed getY() const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

bool bsp(Point const a, Point const b, Point const c, Point const p);
