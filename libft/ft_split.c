/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 07:42:17 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/09 17:44:34 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_clear(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

size_t	ft_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	i = 0;
	nb_strs = 0;
	while (s[i] != c && s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			nb_strs++;
		i++;
	}
	while (s[i] && c == s[i])
	{
		while (s[i + 1] && c != s[i + 1])
		{
			if (s[i] == c || s[i] == '\0')
				nb_strs++;
			i++;
		}
		i++;
	}
	return (nb_strs);
}

char	*ft_find_str(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_strs;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!tab)
		return (NULL);
	while (i < nb_strs)
	{
		while (s[j] == c)
			j++;
		tab[i] = ft_find_str(s + j, c);
		if (!tab[i])
			return (ft_clear(tab));
		j = ft_strlen(tab[i]) + j;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
