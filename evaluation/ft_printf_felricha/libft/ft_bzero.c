/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:56:49 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 16:45:20 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) str;
	i = 0;
	if (!str)
		return ;
	while (i < n)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}
}
