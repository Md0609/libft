/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:29:57 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/25 22:42:42 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ntr;
	size_t				i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	ntr = ((unsigned char *)dest);
	while (i < n)
	{
		ntr[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
