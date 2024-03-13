/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:54:26 by fwu               #+#    #+#             */
/*   Updated: 2024/01/17 15:36:00 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
// 	char src1 [4] = "888";	
// 	char dest1 [4] = "065";
// 	char *result1 = NULL;
// 	char src2 [4] = "888";	
// 	char dest2 [4] = "065";	
// 	char *result2 = NULL;

// 	printf("src:[%s] ", src1);
// 	printf("dest:[%s] ", dest1);
// 	result1 = strcpy(dest1, src1);
// 	printf("result1:[%s] \n", result1);

// 	printf("src:[%s] ", src2);
// 	printf("dest:[%s] ", dest2);	
// 	result2 = ft_strcpy(dest2, src2);
// 	printf("result2:[%s] ", result2);
// }
