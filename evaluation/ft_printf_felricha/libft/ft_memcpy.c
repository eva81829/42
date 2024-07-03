/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:01 by felricha          #+#    #+#             */
/*   Updated: 2024/02/28 18:54:45 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*byte_dst;
	const unsigned char	*byte_src;

	byte_dst = (unsigned char *)dst;
	byte_src = (unsigned char *)src;
	if (!dst || !src)
		return (dst);
	while (n > 0)
	{
		*byte_dst++ = *byte_src++;
		n--;
	}
	return (dst);
}
