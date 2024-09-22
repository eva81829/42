/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:18:11 by fwu               #+#    #+#             */
/*   Updated: 2024/01/22 22:58:09 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	result = 0;
	if (power >= 0)
	{
		if (power == 0)
		{
			result = 1;
		}
		else
		{
			result = 1;
			i = 0;
			while (i++ < power)
			{
				result *= nb;
			}
		}
	}
	return (result);
}

// int main(void)
// {
// 	int nb = -10;
// 	int power = 2;
// 	printf("%d", ft_iterative_power(nb, power));
// }
