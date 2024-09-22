/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 21:01:42 by fwu               #+#    #+#             */
/*   Updated: 2024/01/27 16:23:57 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	result;

	if (nb < 0)
		result = 0;
	else if (nb == 0 || nb == 1)
		result = 1;
	else
	{
		result = nb * ft_recursive_factorial(nb - 1);
	}
	return (result);
}

// int main(void)
// {
// 	int nb = 5;
// 	printf("%d", ft_recursive_factorial(nb));
// }
