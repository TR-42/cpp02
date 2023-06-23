/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:59:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/23 22:52:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	static const int F_BITS_COUNT = 8;
	int data;

public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed& from);
	~Fixed();

	Fixed& operator=(const Fixed& from);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

};

std::ostream& operator<<(std::ostream& os, const Fixed& v);
