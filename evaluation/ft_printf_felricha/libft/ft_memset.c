/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:04 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 17:29:13 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	byte_ptr = (unsigned char *)b;
	if (!b)
		return (NULL);
	while (i < len)
	{
		*byte_ptr = (unsigned char)c;
		i++;
		byte_ptr++;
	}
	return (b);
}
