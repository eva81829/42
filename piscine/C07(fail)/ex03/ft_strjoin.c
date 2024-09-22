/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:53:14 by fwu               #+#    #+#             */
/*   Updated: 2024/01/31 13:53:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

int	check_strs_leng(int size, char **strs)
{
	int		i;
	int		leng;
	char	*string;

	i = 0;
	leng = 0;
	while (i < size)
	{
		string = strs[i++];
		while (*string++ != '\0')
		{
			leng++;
		}
	}
	return (leng);
}

int	check_sep_leng(char *sep)
{
	int	leng;

	leng = 0;
	while (*sep++ != '\0')
	{
		leng++;
	}
	return (leng);
}

int	str_cpy(char *dest, char *src, int cur_idx)
{
	int	i;

	i = 0;
	while (*src != '\0')
	{
		dest[cur_idx++] = *src++;
		i++;
	}
	return (i);
}

char	*copy_string(char *result, int size, char **strs, char *sep)
{
	char	*string;
	int		idx_strs;
	int		cur_leng;

	idx_strs = 0;
	cur_leng = 0;
	while (idx_strs < size)
	{
		string = strs[idx_strs];
		cur_leng += str_cpy(result, string, cur_leng);
		if (idx_strs < size - 1)
		{
			cur_leng += str_cpy(result, sep, cur_leng);
		}
		idx_strs++;
	}
	result[cur_leng] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		strs_leng;
	int		sep_leng;
	int		total_leng;

	result = "";
	strs_leng = check_strs_leng(size, strs);
	sep_leng = check_sep_leng(sep);
	if (size > 0)
	{
		total_leng = strs_leng + sep_leng * (size - 1);
		result = malloc(sizeof(char) * (total_leng + 1));
		copy_string(result, size, strs, sep);
	}
	return (result);
}

// int main(void)
// {
//     int size = 4;
//     char* strs[] = {"abc", "def", "ghi", "bbbb"};
//     char *sep = "--";
//     char *result = ft_strjoin(size, strs, sep);

//     while(*result != '\0')
//     {
//         printf("%c", *result++);
//     }
//     return (0);
// }
