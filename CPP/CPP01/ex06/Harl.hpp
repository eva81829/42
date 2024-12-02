#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# define NUM_LEVELS 4
# define DEBUG "DEBUG"
# define INFO  "INFO"
# define WARNING  "WARNING"
# define ERROR "ERROR"

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static const std::string levels[NUM_LEVELS];
	public:
		Harl();
		void complain(std::string level);
};

#endif // HARL_HPP