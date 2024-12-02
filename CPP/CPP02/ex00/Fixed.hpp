#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int _value;                           // fixed-point number: unit(bits)
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &other);            // copy constructor
		~Fixed();
		Fixed& operator=(Fixed const &other); // copy assignment operator

		int getRawBits(void) const;           // get _value
		void setRawBits(int const raw);       // set _value to raw
};

#endif // FIXED_HPP