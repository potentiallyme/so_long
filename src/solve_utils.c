/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:20:18 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 17:14:26 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_right(t_map *map, char **tmp, int y, int x)
{
	int	mover;

	mover = 1;
	while (tmp[y][(x + mover)] == '0'
		|| tmp[y][(x + mover)] == 'C'
		|| tmp[y][(x + mover)] == 'P')
	{
		if (tmp[y][(x + mover)] == 'C')
			map->c--;
		if (tmp[y][(x + mover)] == 'E' && map->c != 0)
			break ;
		tmp[y][(x + mover)] = 'W';
		mover++;
	}
	return (x + mover - 1);
}

int	move_left(t_map *map, char **tmp, int y, int x)
{
	int	mover;

	mover = 1;
	while (tmp[y][(x - mover)] == '0'
		|| tmp[y][(x - mover)] == 'C'
		|| tmp[y][(x - mover)] == 'P')
	{
		if (tmp[y][(x - mover)] == 'C')
			map->c--;
		if (tmp[y][(x - mover)] == 'E' && map->c)
			break ;
		tmp[y][(x - mover)] = 'W';
		mover++;
	}
	return (x - mover + 1);
}

int	move_down(t_map *map, char **tmp, int y, int x)
{
	int	mover;

	mover = 1;
	while (tmp[(y + mover)][x] == '0'
		|| tmp[(y + mover)][x] == 'C'
		|| tmp[(y + mover)][x] == 'P')
	{
		if (tmp[(y + mover)][x] == 'C')
			map->c--;
		if (tmp[(y + mover)][x] == 'E' && map->c != 0)
			break ;
		tmp[(y + mover)][x] = 'W';
		mover++;
	}
	return (y + mover - 1);
}

int	move_up(t_map *map, char **tmp, int y, int x)
{
	int	mover;

	mover = 1;
	while (tmp[(y - mover)][x] == '0'
		|| tmp[(y - mover)][x] == 'C'
		|| tmp[(y - mover)][x] == 'P')
	{
		if (tmp[(y - mover)][x] == 'C')
			map->c--;
		if (tmp[(y - mover)][x] == 'E' && map->c != 0)
			break ;
		tmp[(y - mover)][x] = 'W';
		mover++;
	}
	return (y - mover + 1);
}

int	check_exit(t_map *map, char **tmp, int y, int x)
{
	if ((tmp[y][(x + 1)] == 'E'
		|| tmp[y][(x - 1)] == 'E'
		|| tmp[(y + 1)][x] == 'E'
		|| tmp[(y - 1)][x] == 'E')
		&& map->c == 0)
		return (1);
	return (0);
}
