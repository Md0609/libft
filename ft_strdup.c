/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:56:14 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/25 23:03:23 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len(const char *s)
{
	if (*s == '\0' || s == NULL)
		return (0);
	return (1 + len(s + 1));
}

void	cpy_str(char *dest, const char *src)
{
	if (*src == '\0')
	{
		*dest = '\0';
		return ;
	}
	*dest = *src;
	cpy_str(dest + 1, src + 1);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = len(s);
	dup = malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (dup == NULL)
		return (NULL);
	cpy_str(dup, s);
	return (dup);
}
