/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:13 by felricha          #+#    #+#             */
/*   Updated: 2024/03/04 17:29:42 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurence;

	last_occurence = NULL;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last_occurence = (char *)s;
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (last_occurence);
}
