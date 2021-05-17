/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:04:39 by llecoq            #+#    #+#             */
/*   Updated: 2021/03/09 17:40:23 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	empty_file(int ret, char **line)
{
	if (ret <= 0)
		*line = ft_strdup("");
	return (ret);
}

char	*join_buff(char **save, int fd, char *buff)
{
	char	*temp;

	if (!save[fd])
		save[fd] = ft_strdup("");
	temp = ft_strjoin(save[fd], buff);
	free(save[fd]);
	save[fd] = temp;
	return (save[fd]);
}

int	get_line(char **save, char **line, int fd, int ret)
{
	int		len;
	char	*temp;

	len = 0;
	if (!save[fd])
		return (empty_file(ret, line));
	while (save[fd][len] && save[fd][len] != '\n')
		len++;
	if (save[fd][len] == '\0')
	{
		*line = ft_strdup(save[fd]);
		free(save[fd]);
		save[fd] = 0;
		return (0);
	}
	else if (save[fd][len] == '\n')
	{
		*line = ft_substr(save[fd], 0, len);
		temp = ft_strdup(save[fd] + len + 1);
		if (save[fd])
			free(save[fd]);
		save[fd] = temp;
		return (1);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;
	static char	*save[10240];

	ret = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (save[fd] && ft_strchr(save[fd], '\n'))
		return (get_line(save, line, fd, ret));
	while (ret > 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		save[fd] = join_buff(save, fd, buff);
		if (ft_strchr(save[fd], '\n'))
			break ;
	}
	return (get_line(save, line, fd, ret));
	return (1);
}
