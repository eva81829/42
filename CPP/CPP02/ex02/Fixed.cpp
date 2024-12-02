#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(int const num)
{
	_value = num << fractionalBits;
}

Fixed::Fixed(float const num)
{
	_value = std::round(num * (1 << fractionalBits));
}

// copy all the attributes from other to this
Fixed::Fixed(Fixed const &other)
{
	*this = other;
	// call by value: after copy, this and other still have different addresses
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(Fixed const &other)
{
	this->_value = other._value;
	return *this;
}

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed newFixed;

	newFixed._value = this->_value + other._value;
	return newFixed;
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed newFixed;
	newFixed._value = this->_value - other._value; 
	return newFixed;
}

// other.toFloat(): remove other.fractionalBits
// keep this->fractionalBits
// so that this->fractionalBits won't be * by other.fractionalBits
Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed newFixed;
	newFixed._value = this->_value * other.toFloat(); 
	return newFixed;
}

// other.toFloat(): remove other.fractionalBits
// keep this->fractionalBits
// so that this->fractionalBits won't be / by other.fractionalBits
Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed newFixed;
	newFixed._value = this->_value / other.toFloat(); 
	return newFixed;
}

Fixed& Fixed::operator++(void)
{
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed newFixed(*this);
	// copy this->_value into newFixed._value, to store the current value
	this->_value += 1;
	return newFixed; // return the original value (before decrement)
}

Fixed& Fixed::operator--(void)
{
	this->_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed newFixed(*this);
	// copy this->_value into newFixed._value, to store the current value
	this->_value -= 1;
	return newFixed; // return the original value (before decrement)
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->_value != other._value;
}

bool Fixed::operator>(Fixed const &other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(Fixed const &other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->_value <= other._value;
}

// const(at the end of the line): in this function you can't modify any attribute of this class
int Fixed::getRawBits(void) const
{
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

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

// const Fixed&: can only use the const member function of this class
// for example: Fixed::max(a, b).toFloat(), cause .toFloat() is const member function
// if you pass non-const Fixed& to const Fixed&, they still using the same address
const Fixed& Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 > fixed2) ? fixed1 : fixed2;
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

const Fixed& Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	return (fixed1 < fixed2) ? fixed1 : fixed2;
}

std::ostream& operator<<(std::ostream& o, Fixed const &fixed)
{
	std::cout << fixed.toFloat();
	return o;
}
