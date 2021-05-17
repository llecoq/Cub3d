/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:34:10 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/18 17:29:54 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(char **ptr, size_t count, size_t size)
{
	size_t		total;
	char		*str;

	count++;
	total = count * size;
	str = malloc(total);
	ft_bzero(str, total);
	*ptr = str;
	return (*ptr);
}

char	**ft_calloc_map(char ***ptr, size_t count, size_t size)
{
	size_t		total;
	char		**str;

	count++;
	total = count * size;
	str = malloc(total);
	ft_bzero(str, total);
	*ptr = str;
	return (*ptr);
}
