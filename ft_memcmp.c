/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:00:43 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/25 22:51:00 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr;
	const unsigned char	*ptr1;

	ptr = (const unsigned char *)s1;
	ptr1 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	if (*ptr != *ptr1)
		return (*ptr - *ptr1);
	return (ft_memcmp(ptr + 1, ptr1 + 1, n - 1));
}
