/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:10:16 by llecoq            #+#    #+#             */
/*   Updated: 2020/12/04 14:39:42 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	res;
	char		aff;

	res = n;
	if (res < 0)
	{
		res *= -1;
		write(fd, "-", 1);
	}
	if (res > 9)
		ft_putnbr_fd(res / 10, fd);
	aff = res % 10 + '0';
	write(fd, &aff, 1);
}
