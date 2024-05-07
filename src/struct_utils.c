/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:19:50 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:41:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_p(t_player *p)
{
	p->is = 0;
	p->x = 0;
	p->y = 0;
}

void	make_player(t_player *p, int i, int j)
{
	p->x = j;
	p->y = i;
	p->is++;
}

void	init_map_zero(t_map *map)
{
	map->av1 = 0;
	map->c = 0;
	map->n = 0;
	map->dir = 0;
	map->mv_c = 0;
	map->px_c = 0;
	map->on = 1;
}

t_map	*init_map(int fd)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	map->p = ft_calloc(1, sizeof(t_player));
	map->e = ft_calloc(1, sizeof(t_player));
	init_p(map->p);
	init_p(map->e);
	init_map_zero(map);
	map->tab = ft_split(return_gnl(fd), '\n', 1);
	if (!map->tab)
		map_errors(map);
	count_all(map);
	if (map->on && (map->c < 1 || map->p->is != 1 || map->e->is != 1))
		map_errors(map);
	return (map);
}
