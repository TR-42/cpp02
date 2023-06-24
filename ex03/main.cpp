/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:12:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 19:14:38 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

static void proc(
	float ax, float ay,
	float bx, float by,
	float cx, float cy,
	float px, float py
)
{
	Point a(ax, ay);
	Point b(bx, by);
	Point c(cx, cy);
	Point p(px, py);

	std::cout
		<< "a:" << a
		<< ", b:" << b
		<< ", c:" << c
		<< ", p:" << p
		<< std::endl;
	
	bool isIn = bsp(a, b, c, p);

	std::cout << "-> " << isIn << std::endl;
}

int main( void ) {
	proc(
		0,0,
		5,5,
		5,0,
		2,1
	);
	proc(
		0,0,
		5,5,
		5.5,0,
		2,10
	);
	return 0;
}
