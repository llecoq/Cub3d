/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:17:59 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 10:56:21 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screenshot(t_head *head)
{
	head->control.screenshot = 1;
	save_bmp(head, "in_game_screenshot.bmp");
	head->control.screenshot = 0;
}

void	set_bmp_file(t_save *save, t_head *head, char *header)
{
	save->file_size = 40 + 14 + (head->res_x * head->res_y) * 4;
	save->offset = 40 + 14;
	save->header_size = 40;
	save->planes = 1;
	save->bpp = 32;
	save->img_size = head->res_x * head->res_y * 4;
	ft_bzero(header, 54);
	ft_memmove(header, "BM", 2);
	ft_memmove(header + 2, &save->file_size, 4);
	ft_memmove(header + 10, &save->offset, 4);
	ft_memmove(header + 14, &save->header_size, 4);
	ft_memmove(header + 18, &head->res_x, 4);
	ft_memmove(header + 22, &head->res_y, 4);
	ft_memmove(header + 26, &save->planes, 4);
	ft_memmove(header + 28, &save->bpp, 4);
	ft_memmove(header + 34, &save->img_size, 4);
}

int	save_bmp(t_head *head, char *name)
{
	t_save	save;
	int		fd;
	int		i;
	int		j;
	char	*header;

	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (!fd)
		error("Could not create bpm_img file.", head);
	if (!ft_calloc(&header, 54, sizeof(char)))
		return (error("Failed to calloc header for bmp file.", head));
	i = head->res_y - 1;
	set_bmp_file(&save, head, header);
	write(fd, header, 54);
	while (i >= 0)
	{
		j = -1;
		while (++j < head->res_x)
			write(fd, &head->data[i * head->width + j], 4);
		i--;
	}
	close(fd);
	if (!head->control.screenshot)
		ft_clear_memory(head);
	return (1);
}
