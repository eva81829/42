/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:44:08 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 12:39:16 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_args(const char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_printf_d(va_arg(args, int)));
	else if (c == 'i')
		return (ft_printf_i(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printf_lx(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printf_ux(va_arg(args, unsigned int)));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

static int	print_characters(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_args(*++format, args);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
			count++;
		}
	}
	return (count);
}

// va_list args: Declare a va_list variable to manage the variable arguments
// va_start: Initialize the va_list 'args' 
//to start at the argument after 'format'
// va_end: Cleanup the va_list 'args' after processing

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = print_characters(format, args);
	va_end(args);
	return (count);
}
