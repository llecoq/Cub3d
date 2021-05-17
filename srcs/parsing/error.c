/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:38:18 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/13 12:55:55 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	res_error(char *line)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	if (i != 3)
		return (clear_tab(tab));
	i = -1;
	while (tab[1][++i])
		if (!ft_isdigit(tab[1][i]))
			return (clear_tab(tab));
	i = -1;
	while (tab[2][++i])
		if (!ft_isdigit(tab[2][i]))
			return (clear_tab(tab));
	clear_tab(tab);
	return (1);
}

int	parse_error_map(int errnum, t_head *head)
{
	if (errnum == 1)
		dprintf(1, "ERROR: Invalid characters in map\n");
	if (errnum == 2)
		dprintf(1, "ERROR: More than one player in map\n");
	head->parse->error = 1;
	return (-1);
}

int	parse_error(int errnum, char **argv, t_head *head)
{
	if (errnum == 2)
		dprintf(1, "ERROR: Please indicate map path\n");
	if (errnum == 3)
		dprintf(1, "ERROR: %s is not a valid map file\n", argv[1]);
	if (errnum == 4)
		dprintf(1, "ERROR: %s is not a valid command. Try --save\n", argv[2]);
	if (errnum == 5)
		dprintf(1, "ERROR: Too many arguments\n");
	if (errnum == 6)
		perror("open failed");
	if (errnum == 7)
		dprintf(1, "ERROR: Resolution format is not valid\n");
	if (errnum == 8)
	{
		dprintf(1, "ERROR: [%s] is not a valid format", argv[0]);
		dprintf(1, " or path for this texture was already set up\n");
		free(argv[0]);
	}
	if (errnum == 9)
		dprintf(1, "ERROR: Map path is a directory\n");
	head->parse->error = 1;
	return (0);
}

int	error(char *str, t_head *head)
{
	dprintf(1, "ERROR: %s\n", str);
	head->parse->error = 1;
	return (1);
}
