#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	_value = num << fractionalBits;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	_value = std::round(num * (1 << fractionalBits));
}

// copy all the attributes from other to this
Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
	// call by value: after copy, this and other still have different addresses
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return *this;
}

// const(at the end of the line): in this function you can't modify any attribute of this class
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int Fixed::toInt(void) const
{
	return this->_value >> fractionalBits;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value)) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& o, Fixed const &fixed)
{
	std::cout << fixed.toFloat();
	return o;
}
