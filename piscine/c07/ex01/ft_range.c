/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:23:32 by fwu               #+#    #+#             */
/*   Updated: 2024/01/25 01:03:20 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	total;
	int	*arr;
	int	i;

	total = max - min;
	if (total <= 0)
		return (0);
	arr = malloc(sizeof(int) * (total));
	if (!arr)
		return (0);
	i = 0;
	while (i < total)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// int main(void)
// {
// 	int *arr;
// 	int min = 1;
// 	int max = 10;
// 	int i = 0;
// 	arr = ft_range(min, max);

// 	while (i < max - min)
// 	{
// 		printf("%d", arr[i++]);
// 	}
// 	free(arr);
// }
