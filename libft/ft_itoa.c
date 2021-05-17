/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:21:41 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/09 17:27:14 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_nb_len(int n)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	len;
	unsigned int	i;
	char			*dest;

	nb = (unsigned int)n;
	len = ft_nb_len(n);
	i = len - 1;
	if (!ft_calloc(&dest, len, sizeof(char)))
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		dest[0] = '-';
	}
	while (nb > 9)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb + 48;
	dest[len] = '\0';
	return (dest);
}
