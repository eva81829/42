/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_last.C                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:36:47 by fwu               #+#    #+#             */
/*   Updated: 2024/09/25 14:38:33 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// remove the last node of the list
void	ft_lstrm_last(t_list **lst, void (*del)(void*))
{
	t_list	*last_node;
	t_list	*sec_last_node;

	last_node = *lst;
	sec_last_node = NULL;
	while (last_node != 0 && last_node->next != 0)
	{
		sec_last_node = last_node;
		last_node = last_node->next;
	}
	if (last_node)
		ft_lstdelone(last_node, del);
	if (sec_last_node)
		sec_last_node->next = NULL;
}
