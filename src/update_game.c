/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:55:15 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:49:13 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*trail_dir(t_game *game)
{
	if (game->map->dir == 1)
		return (game->data->asset[36]);
	if (game->map->dir == 2)
		return (game->data->asset[37]);
	if (game->map->dir == 3)
		return (game->data->asset[38]);
	if (game->map->dir == 4)
		return (game->data->asset[39]);
	return (NULL);
}

void	close_trail(t_game *game, int y, int x, int rot)
{
	if (rot <= 1)
		return ;
	if (game->map->dir == 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[13], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y + 1) * 20);
	}
	else if (game->map->dir == 2)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[12], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x - 1) * 20, y * 20);
	}
	close_trail_cont(game, y, x);
}

void	close_trail_cont(t_game *game, int y, int x)
{
	if (game->map->dir == 3)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[11], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y - 1) * 20);
	}
	else if (game->map->dir == 4)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[14], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x + 1) * 20, y * 20);
	}
}

void	update_game(t_game *game, int y, int x, int rot)
{
	static_sync(game, 1000);
	what_dir(game, x, y);
	if (game->map->dir == 1)
		trail_up(game, y, x, rot);
	if (game->map->dir == 2)
		trail_right(game, y, x, rot);
	if (game->map->dir == 3)
		trail_down(game, y, x, rot);
	if (game->map->dir == 4)
		trail_left(game, y, x, rot);
	static_sync(game, 25000);
	if (game->map->tab[y][x] == 'N')
		return (game_loss(game));
}

int	is_stuck(t_game *game, int y, int x)
{
	int	s;

	s = 20;
	if ((game->map->tab[y][(x - 1)] == '1'
		|| (game->map->tab[y][(x - 1)] == 'E'
		&& game->map->c != 0))
		&& (game->map->tab[y][(x + 1)] == '1'
		|| (game->map->tab[y][(x + 1)] == 'E'
		&& game->map->c != 0))
		&& (game->map->tab[(y - 1)][x] == '1'
		|| (game->map->tab[(y - 1)][x] == 'E'
		&& game->map->c != 0))
		&& (game->map->tab[(y + 1)][x] == '1'
		|| (game->map->tab[(y + 1)][x] == 'E'
		&& game->map->c != 0)))
		return (1);
	return (0);
}
