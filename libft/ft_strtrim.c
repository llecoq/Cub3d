/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:46:03 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/09 17:35:03 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s1);
	while (ft_is_in_set(s1[i], set) == 1)
		i++;
	while (ft_is_in_set(s1[j - 1], set) == 1)
		j--;
	if (i > j)
		return (ft_calloc(&dst, 1, sizeof(char)));
	dst = (char *)malloc(sizeof(char) * j - i + 1);
	if (!dst)
		return (NULL);
	while (i < j)
	{
		dst[k++] = s1[i++];
	}
	dst[k] = '\0';
	return (dst);
}
