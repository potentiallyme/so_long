/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_anims.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:27:18 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:04:59 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	anim_assets(t_game *game, t_data *data)
{
	mm_sec(game, data, 71, "./assets/sq_up.xpm");
	mm_sec(game, data, 72, "./assets/sq_right.xpm");
	mm_sec(game, data, 73, "./assets/sq_down.xpm");
	mm_sec(game, data, 74, "./assets/sq_left.xpm");
	mm_sec(game, data, 75, "./assets/mid_up.xpm");
	mm_sec(game, data, 76, "./assets/mid_right.xpm");
	mm_sec(game, data, 77, "./assets/mid_down.xpm");
	mm_sec(game, data, 78, "./assets/mid_left.xpm");
}

int	get_sq_mid(t_game *game)
{
	int	sq;

	sq = 0;
	if (game->map->dir == 1)
		sq = 73;
	if (game->map->dir == 2)
		sq = 72;
	if (game->map->dir == 3)
		sq = 71;
	if (game->map->dir == 4)
		sq = 74;
	return (sq);
}

void	static_sync(t_game *game, int interval)
{
	mlx_do_sync(game->data->mlx);
	usleep(interval);
}

int	static_boy(t_game *game, int x, int y)
{
	int	sq;

	sq = get_sq_mid(game);
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->asset[(sq + 4)], x * 20, y * 20);
	static_sync(game, 35000);
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->asset[sq], x * 20, y * 20);
	static_sync(game, 35000);
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->asset[(sq + 4)], x * 20, y * 20);
	static_sync(game, 35000);
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->asset[(sq - 60)], x * 20, y * 20);
	static_sync(game, 35000);
	return (1);
}
