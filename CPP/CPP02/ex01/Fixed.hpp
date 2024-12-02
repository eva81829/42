#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int _value;                     // fixed-point number: unit(bits)
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const &other);
		~Fixed();
		Fixed& operator=(Fixed const &other);

		int getRawBits(void) const;     // get _value
		void setRawBits(int const raw); // set _value to raw
		int toInt(void) const;          // convert _value from bits to integer
		float toFloat(void) const;      // convert _value from bits to float
};

#endif // FIXED_HPP