/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:03:43 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 18:52:10 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_color(char *line)
{
	int	i;
	int	color;

	color = 0;
	i = 0;
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
	{
		color = (color * 10 + line[i] - 48);
		i++;
	}
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (color);
	return (-1);
}

int	valid_f(t_head *head, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(line, ',');
	while (tab[i])
		i++;
	if (i != 3)
		if (error("Color format is not valid", head))
			return (clear_tab(tab));
	head->text->f_r = valid_color(tab[0]);
	head->text->f_g = valid_color(tab[1]);
	head->text->f_b = valid_color(tab[2]);
	if (head->text->f_r == -1 || head->text->f_g == -1
		|| head->text->f_b == -1)
		if (error("Color format is not valid", head))
			return (clear_tab(tab));
	clear_tab(tab);
	return (1);
}

int	valid_c(t_head *head, char *line)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(line, ',');
	while (tab[i])
		i++;
	if (i != 3)
		if (error("Color format is not valid", head))
			return (clear_tab(tab));
	head->text->c_r = valid_color(tab[0]);
	head->text->c_g = valid_color(tab[1]);
	head->text->c_b = valid_color(tab[2]);
	if (head->text->c_r == -1 || head->text->c_g == -1
		|| head->text->c_b == -1)
		if (error("Color format is not valid", head))
			return (clear_tab(tab));
	clear_tab(tab);
	return (1);
}

int	treat_fc(t_head *head, char *line, int n)
{
	char	*temp;

	temp = line;
	temp++;
	while (*temp == ' ')
		temp++;
	if (n == 6)
		valid_f(head, temp);
	if (n == 7)
		valid_c(head, temp);
	free(line);
	if (head->text->c_r > 255 || head->text->c_g > 255 || head->text->c_b > 255)
		error("C color format is not valid", head);
	head->text->c = ((head->text->c_r * 256 * 256) + (head->text->c_g * 256)
			+ (head->text->c_b));
	if (head->text->f_r > 255 || head->text->f_g > 255 || head->text->f_b > 255)
		error("F color format is not valid", head);
	head->text->f = ((head->text->f_r * 256 * 256) + (head->text->f_g * 256)
			+ (head->text->f_b));
	return (1);
}
