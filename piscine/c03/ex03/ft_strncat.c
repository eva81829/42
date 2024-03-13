/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:14:38 by fwu               #+#    #+#             */
/*   Updated: 2024/01/23 21:44:21 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
//     char src1[6] = "abcd";	
//     char dest1[11] = "abcd";
// 	unsigned int nb1 = 6;
// 	printf("src1    [%s]\n", src1);
// 	printf("dest1   [%s]\n", dest1);

//     char *result1 = NULL;	
// 	result1 = strncat(dest1, src1, nb1);
// 	printf("result1 [%s]\n\n", result1);

//     char src2[6] = "abcd";
//     char dest2[11] = "abcd";
// 	unsigned int nb2 = 6;	
// 	printf("src2    [%s]\n", src2);
// 	printf("dest2   [%s]\n", dest2);

//     char *result2 = NULL;
// 	result2 = ft_strncat(dest2, src2, nb2);
// 	printf("result2 [%s]\n", result2);

// 	return (0);
// }
