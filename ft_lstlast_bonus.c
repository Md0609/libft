/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:24:41 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/30 14:25:25 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;
	t_list	*last_node;

	node = lst;
	last_node = NULL;
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->next == NULL)
			last_node = node;
		node = node->next;
	}
	return (last_node);
}
