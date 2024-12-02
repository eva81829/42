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
		Fixed(Fixed const &other);      // copy constructor
		~Fixed();

		Fixed& operator=(Fixed const &other);
		Fixed operator+(Fixed const &other) const;
		Fixed operator-(Fixed const &other) const;
		Fixed operator*(Fixed const &other) const;
		Fixed operator/(Fixed const &other) const;

		Fixed& operator++(void);        // Prefix increment  (++x)
		Fixed operator++(int);          // Postfix increment (x++)
		Fixed& operator--(void);        // Prefix decrement  (--x)
		Fixed operator--(int);          // Postfix decrement (x--)

		bool operator==(Fixed const &other) const;
		bool operator!=(Fixed const &other) const;
		bool operator>(Fixed const &other) const;
		bool operator<(Fixed const &other) const;
		bool operator>=(Fixed const &other) const;
		bool operator<=(Fixed const &other) const;

		int getRawBits(void) const;     // get _value
		void setRawBits(int const raw); // set _value to raw
		int toInt(void) const;          // convert _value from bits to integer
		float toFloat(void) const;      // convert _value from bits to float
		
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(Fixed const &fixed1, Fixed const &fixed2);		
		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(Fixed const &fixed1, Fixed const &fixed2);		
};

#endif // FIXED_HPP