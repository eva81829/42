/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:37:50 by fwu               #+#    #+#             */
/*   Updated: 2024/01/22 22:56:56 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 0;
	if (power >= 0)
	{
		if (power == 0)
		{
			result = 1;
		}
		else
		{
			result = nb * ft_recursive_power(nb, power - 1);
		}
	}
	return (result);
}

// int main(void)
// {
// 	int nb = 2;
// 	int power = 1;
// 	printf("%d", ft_recursive_power(nb, power));
// }
