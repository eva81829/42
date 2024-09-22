/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpothier <vpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:28:52 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 22:47:40 by vpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	t_arg 	*arg;
	// char 	*dict_content;
	
	arg = malloc(sizeof(*arg));
	check_arg(arg, argc, argv);
	if (arg->status == FALSE)
	{
		return (0);
	}
	
	number_convert(arg->value);
	free(arg);
	return (0);
}
