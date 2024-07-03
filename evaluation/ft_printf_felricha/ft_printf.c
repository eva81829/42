/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:11:08 by felricha          #+#    #+#             */
/*   Updated: 2024/04/18 15:38:12 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_input(const char *type, size_t *count, va_list args)
{
	if (*type == 'c')
		ft_putchar_pf(va_arg(args, int), count);
	else if (*type == 's')
		ft_putstr_pf(va_arg(args, char *), count);
	else if (*type == 'x' || *type == 'X')
		ft_puthex_pf(type, va_arg(args, unsigned int), count);
	else if (*type == 'd' || *type == 'i')
		ft_putnbr_pf(va_arg(args, int), count);
	else if (*type == 'u')
		ft_put_unsigned_pf(va_arg(args, unsigned int), count);
	else if (*type == '%')
		ft_putchar_pf('%', count);
	else if (*type == 'p')
		ft_printptr_pf(va_arg(args, void *), count);
	else
		return (-1);
	return (1);
}

void	ft_read_string(const char *input, size_t *count, va_list args)
{
	while (*input)
	{
		if (*input == '%' && *input + 1 != '\0')
		{
			input++;
			while (*input == ' ')
				input++;
			if (ft_treat_input((char *)input, count, args) == 1)
				input++;
		}
		else if (*input != '%')
		{
			ft_putchar_pf(*input, count);
			input++;
		}
	}
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	count;

	count = 0;
	va_start (args, input);
	if (!input)
		return (count);
	ft_read_string(input, &count, args);
	va_end (args);
	return ((int)count);
}

int main()
{
	// char caractere = 'A';
	// char *chaine = "Hello, world!";
	// void *pointeur = &caractere;
	// int entier = 123;
	// unsigned int entier_non_signe = 456;

	// ft_printf("Le vrai printf :\n\n");
	// printf("Caractère : %c\n", caractere);
	// printf("Chaîne : %s\n", chaine);
	// printf("Pointeur : %p\n", pointeur);
	// printf("Entier décimal : %d\n", entier);
	// printf("Entier non signé : %u\n", entier_non_signe);
	// printf("Hexadécimal (minuscule) : %x\n", entier);
	// printf("Hexadécimal (majuscule) : %X\n", entier);
	// printf("Pourcentage : %%\n\n");

	// ft_printf("Mon printf :\n\n");
	// ft_printf("Caractère : %c\n", caractere);
	// ft_printf("Chaîne : %s\n", chaine);
	// ft_printf("Pointeur : %p\n", pointeur);
	// ft_printf("Entier décimal : %d\n", entier);
	// ft_printf("Entier non signé : %u\n", entier_non_signe);
	// ft_printf("Hexadécimal (minuscule) : %x\n", entier);
	// ft_printf("Hexadécimal (majuscule) : %X\n", entier);
	// ft_printf("Pourcentage : %%\n");

	// printf("qwertyuiop1234567890-=[]\n\r\t  1233-1");
	// ft_printf("qwertyuiop1234567890-=[]\n\r\t  1233-1");

	int a = 123;
	void *pointeur = &a;	


	int p1;
	int p2;	
	p1 = printf("%c %s %li %u %p %%%% %x %X\n", 'a', "2345678iujkl", -2147483648, 2147483647, pointeur, 500, 600);
	p2 = ft_printf("%c %s %i %u %p %%%% %x %X\n", 'a',  "2345678iujkl",-2147483648, 2147483647, pointeur, 500 ,600);
	
	ft_printf("%d %d", p1, p2);
	return 0;
}
