/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:43:46 by fwu               #+#    #+#             */
/*   Updated: 2024/01/27 16:21:36 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	if (nb >= 0)
	{
		i = 1;
		while (i <= nb)
		{
			result *= i++;
		}
	}
	else if (nb < 0)
	{
		result = 0;
	}
	return (result);
}

// int main(void)
// {
// 	int nb = 5;
// 	printf("%d\n", ft_iterative_factorial(nb));
// }
