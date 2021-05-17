/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:58:23 by llecoq            #+#    #+#             */
/*   Updated: 2021/02/24 14:54:40 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

# include <fcntl.h>

int			get_next_line(int fd, char **line);

#endif
