/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdios-el <mdios-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:07:49 by mdios-el          #+#    #+#             */
/*   Updated: 2024/10/02 20:10:08 by mdios-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_start_index(char const *input_str, char const *set)
{
	int	i;

	i = 0;
	while (is_in_set(input_str[i], set) && input_str[i] != '\0')
		i++;
	return (i);
}

static int	get_end_index(char const *input_str, char const *set)
{
	int	input_str_len;

	input_str_len = ft_strlen(input_str) - 1;
	while (input_str_len >= 0 && is_in_set(input_str[input_str_len], set))
		input_str_len--;
	return (input_str_len);
}

static char	*cpy_trim_str(char const *s1, int start_index, int end_index)
{
	int		trim_len;
	char	*result;
	int		i;

	i = 0;
	trim_len = end_index - start_index + 1;
	result = malloc(trim_len + 1);
	if (!result)
		return (NULL);
	while (start_index <= end_index)
		result[i++] = s1[start_index++];
	result[i] = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	char	*empty_str;

	start_index = get_start_index(s1, set);
	end_index = get_end_index(s1, set);
	if (!s1 || s1[0] == '\0')
	{
		empty_str = malloc(1);
		if (!empty_str)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	if (start_index > end_index)
	{
		empty_str = malloc(1);
		if (!empty_str)
			return (NULL);
		empty_str[0] = '\0';
		return (empty_str);
	}
	return (cpy_trim_str(s1, start_index, end_index));
}
