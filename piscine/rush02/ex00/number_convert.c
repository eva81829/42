/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpothier <vpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:38:20 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 23:32:44 by vpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	index_to_digit(int leng, int index)
{
	return (leng - index);
}

int	digit_to_index(int leng, int digit)
{
	return (leng - digit);
}

void	print_ten(int value) //value >= 0  && value <= 99
{
	char	*letters;

	if (value <= 19)
	{
		letters = get_number_0_to_19(value);
		ft_putstr(letters);
	}
	else if (value >= 20 && value <= 99)
	{
		letters = get_number_10_to_100(value / 10);
		ft_putstr(letters);
		if (value % 10 != 0)
		{
			ft_putstr(" ");
			letters = get_number_0_to_19(value % 10);
			ft_putstr(letters);
		}
	}
}

void	print_hundred(int value) //value >= 100 && value <= 999
{
	char	*letters;

	if (value < 100)
	{
		print_ten(value);
	}
	else if (value >= 100 && value <= 999)
	{
		letters = get_number_0_to_19(value / 100);
		ft_putstr	(letters);	
		ft_putstr(" ");
		letters = get_number_10_to_100(10);
		ft_putstr	(letters);	
		if (value % 100 != 0)
		{
			ft_putstr(" ");
			value = value - (value / 100) * 100;
			print_ten	(value);			
		}
	}
}

int get_digit_numbers(int cur_digit)
{
	int result;

	result = cur_digit % 3;
	if ((result == 1) || (result == 2))
	{
		return (result);
	}
	else
	{
		return (3);
	}
}

int get_multiple_thousand(int cur_digit)
{
	int	result;

	result = cur_digit / 3;
	if	(cur_digit % 3 == 0)
	{
		result -= 1;
	}
	return (result); 
}

int	get_hundred_value(char *value, int cur_digit, int cur_index)
{
	int		int_hundred_value;	
	char	char_hundred_value[3 + 1];
	int		d_numbers;
	int		i;

	d_numbers = get_digit_numbers(cur_digit);
	i = 0;
	while (i < d_numbers)
	{
		char_hundred_value[i++] = value[cur_index++];
	}
	char_hundred_value[i] = '\0';
	// ft_putstr(" hundred_value:");
	// ft_putstr(char_hundred_value);
	int_hundred_value = ft_atoi_hundred(char_hundred_value);
	return (int_hundred_value); 
}

void	number_convert(char *value)
{
	// (void) value;
	char	*letters;	
	int		leng;
	int		i;
	int		cur_digit;
	int		d_numbers;
	int		mul_thousand;
	int		int_hundred_value;

	leng = ft_strlen(value);
	i = 0;
	while (i < leng)
	{
		cur_digit = index_to_digit(leng, i);
		d_numbers = get_digit_numbers(cur_digit);
		mul_thousand = get_multiple_thousand(cur_digit);
		int_hundred_value = get_hundred_value(value, cur_digit, i);
		if (leng < 4) //value < 1000
		{
			print_hundred(int_hundred_value);
		}
		else
		{
			if (int_hundred_value > 0 && mul_thousand > 0)
			{
				if (cur_digit != leng)
				{
					ft_putstr(" ");
				}
				print_hundred(int_hundred_value);
				ft_putstr(" ");
				letters = get_number_more_than_1000(mul_thousand - 1);
				ft_putstr(letters);
			}
			else
			{
				if (int_hundred_value > 0)
				{
					ft_putstr(" ");
					print_hundred(int_hundred_value);
				}
			}
		}
		i += d_numbers;
	}
}

// 1 % 3 == 0...1 ( str[i] * 1)
// 2 % 3 == 0...2 ( str[i] * 10)
// 3 % 3 == 0...3 ( str[i] * 100)

// 4 % 3 == 1...1 ( str[i] * 1)
// 5 % 3 == 1...1 ( str[i] * 1)
// 6 % 3 == 2...1 ( str[i] * 1)

// 10 % 3 == 3...1 ( str[i] * 1)
// 11 % 3 == 3...2 ( str[i] * 10)
// 12 % 3 == 3...0 ( str[i] * 100)
