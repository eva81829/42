/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpothier <vpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:10:36 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 22:54:08 by vpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_value(char *value) //check value vaild
{
	int	count;

	count = 0;
	while (*value != '\0')
	{
		if (!(*value >= '0' && *value <= '9'))
		{
			ft_putstr("Error\n");
			return (FALSE);
		}
		value++;
		count++;
	}
	if (count == 0)
	{
		ft_putstr("Error\n");
		return (FALSE);
	}
	return (TRUE);
}
/*check argument numbers vaild*/
void	check_arg(t_arg *arg, int argc, char **argv)
{
	if (argc == 2)/*only 1 argument*/
	{
		arg->path   = DEFAULT_PATH;
		arg->value  = argv[1];
	}
	else if (argc == 3) //2 arguments
	{
		arg->path   = argv[1];
		arg->value  = argv[2];
	}
	else //0 or more than 2 arguments
	{
		arg->path   = "";
		arg->value  = "";
	}
	if (check_value(arg->value) == TRUE)
		arg->status = TRUE;
	else
		arg->status = FALSE;
}