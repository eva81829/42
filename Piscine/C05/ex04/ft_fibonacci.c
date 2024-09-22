/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:44:30 by fwu               #+#    #+#             */
/*   Updated: 2024/01/22 22:56:13 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_fibonacci(int index)
{
	int	result;

	result = -1;
	if (index >= 0)
	{
		if (index == 0)
			result = 0;
		else if (index == 1)
			result = 1;
		else
			result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	}
	return (result);
}

// int main(void)
// {
// 	int index = -2;
// 	printf("%d", ft_fibonacci(index));
// }
