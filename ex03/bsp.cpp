/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:13:56 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 19:06:04 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ref: http://www.sousakuba.com/Programming/gs_hittest_point_triangle.html
bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Point const AB = b - a;
	Point const BP = p - a;

	Point const BC = c - b;
	Point const CP = p - c;

	Point const CA = a - c;
	Point const AP = p - a;

	Fixed const zero(0);

	Fixed c1 = AB.crossProd(BP);
	Fixed c2 = BC.crossProd(CP);
	Fixed c3 = CA.crossProd(AP);

	return (
		(zero < c1 && zero < c2 && zero < c3)
		||
		(c1 < zero && c2 < zero && c3 < zero)
	);
}
