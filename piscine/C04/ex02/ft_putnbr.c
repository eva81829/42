/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:13:00 by fwu               #+#    #+#             */
/*   Updated: 2024/01/22 20:32:38 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_min_int(int nb)
{
	char	*str;
	int		result;

	str = NULL;
	result = 0;
	if (nb == -2147483648)
	{
		str = "-2147483648";
		result = 1;
		while (*str != '\0')
			write(1, str++, 1);
	}
	return (result);
}

int	transform(char *str, int value)
{
	int	i;

	i = 0;
	while (1)
	{
		if (value / 10 <= 0)
		{
			str[i] = value + '0';
			i++;
			break ;
		}
		str[i] = value % 10 + '0';
		value /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	str[15];
	int		i;
	int		value;

	if (check_min_int(nb))
		return ;
	i = 0;
	while (i < 15)
	{
		str[i] = '\0';
		i++;
	}
	if (nb < 0)
		value = -1 * nb;
	else
		value = nb;
	i = transform(str, value);
	if (nb < 0)
		str[i++] = '-';
	while (i > 0)
		write(1, &str[--i], 1);
}

// int	main(void)
// {
// 	ft_putnbr(-2147483647);
// }
