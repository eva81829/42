/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 01:12:43 by fwu               #+#    #+#             */
/*   Updated: 2024/01/27 11:48:21 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	total;
	int	i;

	total = max - min;
	if (total <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * (total));
	if (!*range)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < total)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (total);
}

// int	main(void)
// {
// 	int	*arr = 0;
// 	int	**range = &arr;

// 	int	min = 2147483643;
// 	int	max = 2147483647;
// 	int	i = 0;
// 	int	result = 0;

// 	result = ft_ultimate_range(range, min, max);
// 	printf("result:%d \n", result);
// 	if (!*range)
// 		return (0);	
// 	while (i < result)
// 	{
// 		printf("main:%d ", (*range)[i++]);
// 	}
// 	free(arr);
// 	return (0);
// }
