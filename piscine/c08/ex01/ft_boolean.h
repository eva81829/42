/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:22:58 by fwu               #+#    #+#             */
/*   Updated: 2024/02/01 12:28:33 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# define EVEN_MSG "I have an even number of arguments." 
# define ODD_MSG "I have an odd number of arguments."
# define SUCCESS 0

# define EVEN(n) ((n) % 2 == 0)

typedef int	t_bool;

t_bool	ft_is_even(int nbr);

#endif // FT_BOOLEAN_H