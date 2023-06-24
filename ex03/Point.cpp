/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:07:34 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 19:13:07 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
}

Point::Point(const Point &from) :
	x(from.x),
	y(from.y)
{
}

Point::Point(const Fixed &x, const Fixed &y) :
	x(x),
	y(y)
{
}

Point::Point(const float &x, const float &y) :
	x(Fixed(x)),
	y(Fixed(y))
{
}

Point::~Point()
{
}

Point &Point::operator=(const Point &from)
{
	this->x = from.x;
	this->y = from.y;

	return *this;
}

Point Point::operator-(const Point &other) const
{
	return Point(this->x - other.x, this->y - other.y);
}

Fixed Point::crossProd(const Point &other) const
{
	return ((this->x * other.y) - (this->y * other.x));
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream &os, const Point &p)
{
	os
		<< "("
		<< p.getX()
		<< ","
		<< p.getY()
		<< ")"
	;

	return os;
}
