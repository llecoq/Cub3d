/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:16:53 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/12 12:13:39 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	data(t_threads *p, int *text, int height)
{
	p->text = text;
	p->step = ((double)height / 2.0);
	if (p->plan == 1)
	{
		p->width = p->head->width_top;
		p->height_text = p->head->height_top;
	}
	if (p->plan == 2)
	{
		p->width = p->head->width_right;
		p->height_text = p->head->height_right;
	}
	if (p->plan == 3)
	{
		p->width = p->head->width_bottom;
		p->height_text = p->head->height_bottom;
	}
	if (p->plan == 4)
	{
		p->width = p->head->width_left;
		p->height_text = p->head->height_left;
	}
	return (1);
}

int	*data_sky(t_threads *p, int i)
{
	int		*sky_data;

	sky_data = NULL;
	if (i == 0)
		sky_data = p->head->data_sky_0;
	else if (i == 1)
		sky_data = p->head->data_sky_1;
	else if (i == 2)
		sky_data = p->head->data_sky_2;
	else if (i == 3)
		sky_data = p->head->data_sky_3;
	return (sky_data);
}

size_t	ft_strlen_tab(char **tab)
{
	size_t	len;

	len = 0;
	if (!tab)
		return (0);
	while (tab[len])
		len++;
	return (len);
}

void	sort_plan(t_plan *alst)
{
	double	temp;
	t_plan	*plan;

	plan = alst;
	while (alst)
	{
		if (alst->next && alst->d < alst->next->d)
		{
			temp = alst->next->d;
			alst->next->d = alst->d;
			alst->d = temp;
			alst = plan;
		}
		alst = alst->next;
	}
}

void	asort_plan(t_plan *alst)
{
	double	temp;
	t_plan	*plan;

	plan = alst;
	while (alst)
	{
		if (alst->next && alst->d > alst->next->d)
		{
			temp = alst->next->d;
			alst->next->d = alst->d;
			alst->d = temp;
			alst = plan;
		}
		alst = alst->next;
	}
}
