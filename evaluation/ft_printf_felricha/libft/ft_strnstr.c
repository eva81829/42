/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:55:12 by felricha          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:40 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle || !haystack)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && n >= needle_len)
	{
		if (*haystack == *needle
			&& ft_strncmp(haystack, needle, needle_len) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		n--;
	}
	return (NULL);
}
