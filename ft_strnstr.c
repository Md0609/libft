/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:01:00 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/27 18:40:18 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	p;

	if (big == NULL && little == 0)
		return (0);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		p = 0;
		if (big[i] == little[p])
		{
			while (p + i < len && big[i + p] == little[p])
			{
				p++;
				if (!little[p])
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
