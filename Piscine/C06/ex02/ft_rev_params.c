/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:05:44 by fwu               #+#    #+#             */
/*   Updated: 2024/01/23 15:11:00 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
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
		i = argc - 1;
		while (i > 0)
		{
			str = argv[i--];
			ft_rev_params(str);
		}
	}
	return (0);
}
