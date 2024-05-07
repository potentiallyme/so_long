/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:59:51 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 19:02:13 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	what_dir(t_game *game, int j, int i)
{
	int	s;
	int	way;

	way = 0;
	s = 20;
	if (game->map->dir == 3)
		way = 11;
	else if (game->map->dir == 4)
		way = 14;
	else if (game->map->dir == 1)
		way = 13;
	else if (game->map->dir == 2)
		way = 12;
	put_up(game->data, game->data->asset[way], i, j);
}

void	what_way(t_game *game, int i, int j)
{
	int	way;

	way = 11;
	if (game->map->tab[(i + 1)][j] == '1')
	{
		way = 11;
		game->map->dir = 3;
	}
	else if (game->map->tab[i][(j - 1)] == '1')
	{
		way = 14;
		game->map->dir = 4;
	}
	else if (game->map->tab[(i - 1)][j] == '1')
	{
		way = 13;
		game->map->dir = 1;
	}
	else if (game->map->tab[i][(j + 1)] == '1')
	{
		way = 12;
		game->map->dir = 2;
	}
	put_up(game->data, game->data->asset[way], i, j);
}

void	pick_floor(t_data *data, int i, int j)
{
	int	s;
	int	r;

	s = 20;
	r = ft_make_rand(i, j);
	if (r + 20 < 30 && r + 20 > 20)
		put_up(data, data->asset[(r + 20)], i, j);
	else
		put_up(data, data->asset[21], i, j);
}
