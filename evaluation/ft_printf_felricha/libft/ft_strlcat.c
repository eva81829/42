/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:07 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 17:29:32 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t		dest_len;
	size_t		total_len;
	const char	*s;

	s = src;
	dest_len = 0;
	if ((!dest || !src) && !dstsize)
		return (0);
	while (*(dest + dest_len) && dest_len < dstsize)
		dest_len++;
	if (dest_len < dstsize)
		total_len = dest_len + ft_strlen(s);
	else
		return (dstsize + ft_strlen(s));
	while (*s && (dest_len + 1) < dstsize)
	{
		*(dest + dest_len) = *s++;
		dest_len++;
	}
	*(dest + dest_len) = '\0';
	return (total_len);
}
