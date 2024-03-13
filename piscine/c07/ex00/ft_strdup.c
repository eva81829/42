/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:46:08 by fwu               #+#    #+#             */
/*   Updated: 2024/01/27 11:44:41 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		total;
	char	*dest;
	int		i;

	total = ft_strlen(src);
	dest = malloc(sizeof(char) * (total + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < total)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
	// char *src;
	// char *dest;
	// char *ft_dest;
	// src = "abc";
	// dest = strdup(src);
	// ft_dest = ft_strdup(src);

	// printf("%p\n", src);
	// printf("%p\n", dest);
	// printf("%p\n", ft_dest);

	// printf("src:     [%s]\n", src);
	// printf("dest:    [%s]\n", dest);
	// printf("ft_dest: [%s]\n", ft_dest);

	// free(dest);
	// free(ft_dest);	
// }
