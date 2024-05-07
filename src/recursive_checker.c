/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:21:18 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:50:20 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	recursive_checker(t_map *map, char **tmp, int y, int x)
{
	int		r;
	int		c;
	char	**new_map;

	r = 0;
	c = map->c;
	new_map = NULL;
	if (check_exit(map, tmp, y, x))
		return (r + 1);
	if (tmp[y][(x + 1)] == '0' || tmp[y][(x + 1)] == 'C')
	{
		new_map = ft_strdup_double(tmp);
		r += recursive_checker(map, new_map, y, move_right(map, new_map, y, x));
		ft_free(new_map);
		map->c = c;
	}
	if (tmp[y][(x - 1)] == '0' || tmp[y][(x - 1)] == 'C')
	{
		new_map = ft_strdup_double(tmp);
		r += recursive_checker(map, new_map, y, move_left(map, new_map, y, x));
		ft_free(new_map);
		map->c = c;
	}
	r += recursive_cont(map, tmp, y, x);
	return (r);
}

int	recursive_cont(t_map *map, char **tmp, int y, int x)
{
	int		r;
	int		c;
	char	**new_map;

	r = 0;
	c = map->c;
	new_map = NULL;
	if (tmp[(y + 1)][x] == '0' || tmp[(y + 1)][x] == 'C')
	{
		new_map = ft_strdup_double(tmp);
		r += recursive_checker(map, new_map, move_down(map, new_map, y, x), x);
		ft_free(new_map);
		map->c = c;
	}
	if (tmp[(y - 1)][x] == '0' || tmp[(y - 1)][x] == 'C')
	{
		new_map = ft_strdup_double(tmp);
		r += recursive_checker(map, new_map, move_up(map, new_map, y, x), x);
		ft_free(new_map);
		map->c = c;
	}
	return (r);
}
