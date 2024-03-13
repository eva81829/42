/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:34:08 by fwu               #+#    #+#             */
/*   Updated: 2024/01/20 21:37:17 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	src_end;

	i = 0;
	src_end = 0;
	while (i < n)
	{
		if (src[i] == '\0' || src_end == 1)
		{
			dest[i] = '\0';
			src_end = 1;
		}
		else
		{
			dest[i] = src[i];
		}
		i++;
	}
	return (dest);
}
