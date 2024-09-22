/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:33:13 by fwu               #+#    #+#             */
/*   Updated: 2024/01/14 19:25:42 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_rectangle(int rowx, int rowy, int x, int y)
{
	if ((rowy == 0 && rowx == 0) || (rowy == 0 && rowx == x - 1))
	{
		ft_putchar('A');
	}
	else if ((rowy == y - 1 && rowx == x - 1) || (rowy == y - 1 && rowx == 0))
	{
		ft_putchar('C');
	}
	else if ((rowy >= 1 && rowx >= 1) && (rowy < y - 1 && rowx < x - 1))
	{
		ft_putchar(' ');
	}
	else 
	{
		ft_putchar('B');
	}
}

void	rush(int x, int y)
{
	int	rowx;
	int	rowy;

	rowy = 0;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (rowy < y)
	{
		rowx = 0;
		while (rowx < x)
		{
			print_rectangle(rowx, rowy, x, y);
			rowx++;
		}
		ft_putchar('\n');
		rowy++;
	}
}
