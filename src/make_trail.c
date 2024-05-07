/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_trail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:37:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 15:38:34 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	trail_up(t_game *game, int y, int x, int rot)
{
	if (rot == 0)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[79], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y + 1) * 20);
	}
	if (rot >= 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[79], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			trail_dir(game), x * 20, (y + 1) * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y + 2) * 20);
	}
}

void	trail_right(t_game *game, int y, int x, int rot)
{
	if (rot == 0)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[70], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x - 1) * 20, y * 20);
	}
	if (rot >= 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[70], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			trail_dir(game), (x - 1) * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x - 2) * 20, y * 20);
	}
}

void	trail_down(t_game *game, int y, int x, int rot)
{
	if (rot == 0)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[79], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y - 1) * 20);
	}
	if (rot >= 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[79], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			trail_dir(game), x * 20, (y - 1) * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], x * 20, (y - 2) * 20);
	}
}

void	trail_left(t_game *game, int y, int x, int rot)
{
	if (rot == 0)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[70], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x + 1) * 20, y * 20);
	}
	if (rot >= 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[70], x * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			trail_dir(game), (x + 1) * 20, y * 20);
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[5], (x + 2) * 20, y * 20);
	}
}
