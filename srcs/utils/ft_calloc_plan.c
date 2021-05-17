/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_plan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 15:54:32 by llecoq            #+#    #+#             */
/*   Updated: 2021/05/11 18:21:41 by llecoq           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	del(void *content)
{
	char	*line;

	line = (char *)content;
	free(line);
	line = NULL;
}

t_vec	*new_vec(double x, double y)
{
	t_vec	*new_elem;

	new_elem = malloc(sizeof(t_vec));
	if (!new_elem)
		return (NULL);
	new_elem->x = x;
	new_elem->y = y;
	return (new_elem);
}

t_vec	**ft_calloc_vec(t_vec ***ptr, size_t count, size_t size)
{
	size_t		total;
	t_vec		**plan;
	size_t		i;

	count++;
	total = count * size;
	plan = malloc(total);
	if (!plan)
		return (NULL);
	*ptr = plan;
	i = 0;
	while (i < count)
		(*ptr)[i++] = NULL;
	return (*ptr);
}

t_plan	**ft_calloc_plan(t_plan ***ptr, size_t count, size_t size)
{
	size_t		total;
	t_plan		**plan;
	size_t		i;

	count++;
	total = count * size;
	plan = malloc(total);
	if (!plan)
		return (NULL);
	*ptr = plan;
	i = 0;
	while (i < count)
		(*ptr)[i++] = NULL;
	return (*ptr);
}
