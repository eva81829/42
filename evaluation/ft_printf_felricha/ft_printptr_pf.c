/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:42 by felricha          #+#    #+#             */
/*   Updated: 2024/03/15 13:07:33 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr_pf(void *ptr, size_t *count)
{
	const char	*type;

	type = "x";
	ft_putstr_pf("0x", count);
	ft_puthex_pf(type, (unsigned long long)ptr, count);
}
