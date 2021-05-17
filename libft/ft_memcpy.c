/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:48:21 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/03 14:12:55 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	dest = dst;
	source = src;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
