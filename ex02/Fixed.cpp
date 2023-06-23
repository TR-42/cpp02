/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:01:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/24 01:51:38 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() :
	data(0)
{
}

Fixed::Fixed(int const value) :
	data(value << this->F_BITS_COUNT)
{
}

// ref: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
Fixed::Fixed(float const value) :
	data((int)std::roundf(value * (1 << this->F_BITS_COUNT)))
{
}

Fixed::Fixed(const Fixed &from) :
	data(from.data)
{
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &from)
{
	if (this == &from)
		return *this;

	this->data = from.data;

	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->data;
}

void Fixed::setRawBits(int const raw)
{
	this->data = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->data / (float)(1 << this->F_BITS_COUNT));
}

int Fixed::toInt(void) const
{
	return this->data >> this->F_BITS_COUNT;
}

std::ostream& operator<<(std::ostream &os, const Fixed &v)
{
	os
		<< v.toFloat();
	return os;
}

#pragma region operators
#define OP_RET_NEW(op) \
Fixed Fixed::operator op (const Fixed &other) const\
{\
	Fixed v;\
	v.setRawBits(this->data op other.data);\
	return v;\
}\

#define OP_COMP(op) \
bool operator op (const Fixed &left, const Fixed &right)\
{\
	return left.getRawBits() op right.getRawBits();\
}\

#define OP_PRE_INC_DEC(op) \
Fixed &Fixed::operator op (void)\
{\
	this->data op;\
	return *this;\
}\

#define OP_POST_INC_DEC(op) \
Fixed Fixed::operator op (int)\
{\
	Fixed copy(*this);\
	this->data op;\
	return copy;\
}\

OP_RET_NEW(+)
OP_RET_NEW(-)

// ref: https://vanhunteradams.com/FixedPoint/FixedPoint.html
Fixed Fixed::operator * (const Fixed &other) const
{
	Fixed ret;
	if (this->data == 0 || other.data == 0)
		return ret;

	long long a = this->data;
	long long b = other.data;
	ret.setRawBits((int)((a * b) >> this->F_BITS_COUNT));
	return ret;
}

Fixed Fixed::operator / (const Fixed &other) const
{
	Fixed ret;
	if (this->data == 0)
		return ret;

	long long a = this->data;
	long long b = other.data;
	ret.setRawBits((int)((a << this->F_BITS_COUNT) / b));
	return ret;
}

OP_COMP(<)
OP_COMP(<=)
OP_COMP(>)
OP_COMP(>=)
OP_COMP(==)
OP_COMP(!=)

OP_PRE_INC_DEC(++)
OP_PRE_INC_DEC(--)

OP_POST_INC_DEC(++)
OP_POST_INC_DEC(--)

#pragma endregion operators

#pragma region min & max
Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	return left < right ? left : right;
}

const Fixed &Fixed::min(const Fixed &left, const Fixed &right)
{
	return left < right ? left : right;
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	return left > right ? left : right;
}

const Fixed &Fixed::max(const Fixed &left, const Fixed &right)
{
	return left > right ? left : right;
}
#pragma endregion min & max
