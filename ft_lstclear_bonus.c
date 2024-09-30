/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:17:52 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:03 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save_lst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		save_lst = *lst;
		*lst = (*lst)->next;
		(*del)(save_lst->content);
		free(save_lst);
	}
}
