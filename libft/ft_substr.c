/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:11:34 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/11 13:42:38 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*dst;
	int		newlen;

	i = 0;
	newlen = len;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		newlen = 0;
	else if (ft_strlen(s) < len)
		newlen = ft_strlen(s);
	dst = malloc(sizeof(char) * newlen + 1);
	if (!dst)
		return (NULL);
	while (i < newlen)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
