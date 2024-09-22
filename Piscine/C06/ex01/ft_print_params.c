/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:57:28 by fwu               #+#    #+#             */
/*   Updated: 2024/01/23 15:10:57 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_params(char *str)
{
	while (*str != '\0')
	{
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			str = argv[i++];
			ft_print_params(str);
		}
	}
	return (0);
}
