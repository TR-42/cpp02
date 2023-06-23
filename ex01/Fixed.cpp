/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 09:01:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/23 23:10:48 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() :
	data(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) :
	data(value << this->F_BITS_COUNT)
{
	std::cout << "Int constructor called" << std::endl;
}

// ref: https://embeddedartistry.com/blog/2018/07/12/simple-fixed-point-conversion-in-c/
Fixed::Fixed(float const value) :
	data((int)std::roundf(value * (1 << this->F_BITS_COUNT)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &from) :
	data(from.data)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &from)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &from)
		return *this;

	this->data = from.data;

	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->data;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

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
