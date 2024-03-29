/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:33:45 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:58:39 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int main(void)
// {
// 	printf("isdigit:    %d \n", isdigit(57));	
// 	printf("ft_isdigit  %d", ft_isdigit(57));
// }
