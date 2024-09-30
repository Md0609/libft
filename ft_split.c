/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:51:07 by mdios-el          #+#    #+#             */
/*   Updated: 2024/09/27 23:38:11 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	w_count(char const *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
		{
			count++;
			while (str[i] != delimiter && str[i] != '\0')
				i++;
		}
		else
			while (str[i] == delimiter && str[i] != '\0')
				i++;
	}
	return (count);
}

size_t	get_w_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	free_split(char **free_s, int i)
{
	while (i > 0)
	{
		i--;
		free(free_s[i]);
	}
	free(free_s);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	w_len;
	size_t	w_mem;
	int		i;

	w_mem = w_count(s, c);
	result = (char **)malloc((w_mem + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			w_len = get_w_len(s, c);
			result[i++] = ft_substr(s, 0, w_len);
			if (result[i - 1] == NULL)
				return (free_split(result, i), NULL);
			s += w_len;
		}
	}
	result[i] = NULL;
	return (result);
}
