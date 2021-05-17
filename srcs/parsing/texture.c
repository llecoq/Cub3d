/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 13:35:37 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 16:15:18 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	treat_invalid_line(char *line, t_head *head)
{
	if (*line != 0)
	{
		dprintf(1, "ERROR: [%s] is not a valid line\n", line);
		head->parse->error = 1;
	}
	free(line);
}

int	texture_error(char *line, t_head *head, int n)
{	
	char	**tab;
	int		i;

	i = 0;
	if (((n == 1) && (head->parse->no == 1))
		|| ((n == 2) && (head->parse->so == 1))
		|| ((n == 3) && (head->parse->we == 1))
		|| ((n == 4) && (head->parse->ea == 1))
		|| ((n == 5) && (head->parse->s == 1)))
		return (-1);
	if (n == 5 && line[1] != ' ')
		error("Wrong texture format path", head);
	if (n != 5 && line[2] != ' ')
		error("Wrong texture format path", head);
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	if (i != 2)
		return (clear_tab(tab));
	clear_tab(tab);
	return (1);
}

void	store_texture(int n, t_head *head, char *line, int i)
{
	if (n == 3 && head->parse->we == 0)
	{
		head->text->we = ft_strdup(line + i);
		head->parse->we = 1;
	}
	if (n == 4 && head->parse->ea == 0)
	{
		head->text->ea = ft_strdup(line + i);
		head->parse->ea = 1;
	}
	if (n == 5 && head->parse->s == 0)
	{
		head->text->s = ft_strdup(line + i);
		head->parse->s = 1;
	}
}

int	treat_texture(t_head *head, char *line, int n)
{
	int		i;

	i = 0;
	if (texture_error(line, head, n) != 1)
		return (parse_error(8, &line, head));
	while (ft_isalnum(line[i]) || (line[i] == ' '))
		i++;
	if (n == 1 && head->parse->no == 0)
	{
		head->text->no = ft_strdup(line + i);
		head->parse->no = 1;
	}
	if (n == 2 && head->parse->so == 0)
	{
		head->text->so = ft_strdup(line + i);
		head->parse->so = 1;
	}
	if (n == 3 || n == 4 || n == 5)
		store_texture(n, head, line, i);
	free(line);
	return (1);
}
