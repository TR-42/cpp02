/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 08:59:01 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 00:25:28 by kfujita          ###   ########.fr       */
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

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& left, Fixed& right);
	static const Fixed& min(const Fixed& left, const Fixed& right);

	static Fixed& max(Fixed& left, Fixed& right);
	static const Fixed& max(const Fixed& left, const Fixed& right);
};

bool operator>(const Fixed& left, const Fixed& right);
bool operator<(const Fixed& left, const Fixed& right);
bool operator>=(const Fixed& left, const Fixed& right);
bool operator<=(const Fixed& left, const Fixed& right);
bool operator==(const Fixed& left, const Fixed& right);
bool operator!=(const Fixed& left, const Fixed& right);


std::ostream& operator<<(std::ostream& os, const Fixed& v);
