/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:10:00 by fwu               #+#    #+#             */
/*   Updated: 2024/01/20 22:34:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	diff;

	i = 0;
	while (!(s1[i] == '\0' && s2[i] == '\0'))
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
//     char str2[10] = "apple";
//     int result1 = strcmp(str1, str2);
// 	printf("%s %s %d", str1, str2, result1);

// 	printf("\n");
//     char str3[10] = "apple";
//     char str4[10] = "apple";
//     int result2 = ft_strcmp(str3, str4);
// 	printf("%s %s %d", str3, str4, result2);

// 	return (0);
// }
