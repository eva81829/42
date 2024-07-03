/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:32:14 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 16:49:24 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*cal;

	cal = 0;
	cal = malloc(size * count);
	if (!cal)
		return (NULL);
	ft_bzero(cal, size * count);
	return (cal);
}
