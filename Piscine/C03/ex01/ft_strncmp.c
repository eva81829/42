/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:40 by fwu               #+#    #+#             */
/*   Updated: 2024/01/21 00:40:54 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	diff;

	i = 0;
	while (!((s1[i] == '\0' && s2[i] == '\0') || (i == (int) n)))
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
		{
			return (diff);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
//     char str1[10] = "apple";
//     char str2[10] = "app";
// 	int n1 = 4;
//     int result1 = strncmp(str1, str2, n1);
// 	printf("%s %s %d", str1, str2, result1);

// 	printf("\n");
//     char str3[10] = "apple";
//     char str4[10] = "app";
// 	int n2 = 4;	
//     int result2 = ft_strncmp(str3, str4, n2);
// 	printf("%s %s %d", str3, str4, result2);

// 	return (0);
// }
