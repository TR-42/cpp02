/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 22:12:28 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 01:53:56 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

#define PRINT_CALC(expr) std::cout << #expr "\t--> " << (expr) << std::endl

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	PRINT_CALC(a);
	PRINT_CALC(++a);
	PRINT_CALC(a);
	PRINT_CALC(a++);
	PRINT_CALC(a);
	PRINT_CALC(b);

	PRINT_CALC(Fixed::max(a, b));
	PRINT_CALC(Fixed::min(a, b));

	std::cout << "~~~~~~~~~~~~~~~~~~~" << std::endl;

	PRINT_CALC(Fixed(10) / Fixed(0.5f));
	PRINT_CALC(Fixed(10) / Fixed(0.2f));
	PRINT_CALC(Fixed(10) - Fixed(0.2f));
	PRINT_CALC(Fixed(10) + Fixed(0.2f));
	PRINT_CALC(Fixed(10) > Fixed(0.2f));
	PRINT_CALC(Fixed(10) < Fixed(0.2f));
	PRINT_CALC(Fixed(10) <= Fixed(10.f));
	PRINT_CALC(Fixed(10) >= Fixed(10.f));
	PRINT_CALC(Fixed(10) == Fixed(10.f));
	PRINT_CALC(Fixed(10) != Fixed(10.f));
	PRINT_CALC(Fixed(10) != Fixed(0.2f));

	return 0;
}
