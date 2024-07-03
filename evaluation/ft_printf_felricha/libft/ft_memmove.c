/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:02 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 17:29:10 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pt_dst;
	unsigned char		*pt_src;
	unsigned int		i;

	pt_dst = (unsigned char *)dst;
	pt_src = (unsigned char *)src;
	i = 0;
	if (!dst || !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (pt_dst > pt_src)
	{
		while (len--)
			pt_dst[len] = pt_src[len];
	}
	if (pt_dst < pt_src)
	{
		while (i < len)
		{
			pt_dst[i] = pt_src[i];
			i++;
		}
	}
	return (pt_dst);
}
