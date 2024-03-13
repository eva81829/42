/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:54:50 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 14:15:12 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	unsigned int	i;	
	int d;

	i = -10;
	d = ft_printf("print:[%u]", i);
	ft_printf("return:[%d]", d);

	d = printf("print:[%u]", i);
	printf("return:[%d]", d);
	return (0);
}
// size_t	i;
// i = 1500234534567823456;
// printf("%p\n", (char *)i);
// ft_printf("%p\n", (char *)i);	
// printf("%x\n", (unsigned int)i);
// ft_printf("%x\n", (unsigned int)i);
