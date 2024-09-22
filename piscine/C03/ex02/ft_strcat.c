/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:16:51 by fwu               #+#    #+#             */
/*   Updated: 2024/01/22 20:16:11 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
//     char src1[6] = "apple";	
//     char dest1[11] = "fruit";
// 	printf("src1    [%s]\n", src1);
// 	printf("dest1   [%s]\n", dest1);

//     char *result1 = NULL;	
// 	result1 = strcat(dest1, src1);
// 	printf("result1 [%s]\n\n", result1);

//     char src2[6] = "apple";
//     char dest2[11] = "fruit";
// 	printf("src2    [%s]\n", src2);
// 	printf("dest2   [%s]\n", dest2);

//     char *result2 = NULL;	
// 	result2 = ft_strcat(dest2, src2);
// 	printf("result2 [%s]\n", result2);
// 	return (0);
// }
