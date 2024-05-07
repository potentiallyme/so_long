/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:58:03 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/05 18:58:09 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_up(t_data *data, void *asset, int w, int l)
{
	mlx_put_image_to_window(data->mlx, data->win, asset, l * 20, w * 20);
}

void	where_from_cont(t_map *map, t_data *data, int s)
{
	if (map->dir == 3)
	{
		image_replacer(data, data->asset[51], "./assets/boy_down.xpm", s);
		image_replacer(data, data->asset[52], "./assets/trail_down.xpm", s);
		image_replacer(data, data->asset[53], "./assets/trail_end_down.xpm", s);
		image_replacer(data, data->asset[54], "./assets/ball_down.xpm", s);
	}
	if (map->dir == 4)
	{
		image_replacer(data, data->asset[51], "./assets/boy_left.xpm", s);
		image_replacer(data, data->asset[52], "./assets/trail_left.xpm", s);
		image_replacer(data, data->asset[53], "./assets/trail_end_left.xpm", s);
		image_replacer(data, data->asset[54], "./assets/ball_left.xpm", s);
	}
}

void	where_from(t_map *map, t_data *data, int s)
{
	if (map->dir == 1)
	{
		image_replacer(data, data->asset[51], "./assets/boy_up.xpm", s);
		image_replacer(data, data->asset[52], "./assets/trail_up.xpm", s);
		image_replacer(data, data->asset[53], "./assets/trail_end_up.xpm", s);
		image_replacer(data, data->asset[54], "./assets/ball_up.xpm", s);
	}
	if (map->dir == 2)
	{
		image_replacer(data, data->asset[51], "./assets/boy_right.xpm", s);
		image_replacer(data, data->asset[52], "./assets/trail_right.xpm", s);
		image_replacer(data, data->asset[53], "./assets/trail_end_right.xpm",
			s);
		image_replacer(data, data->asset[54], "./assets/ball_right.xpm", s);
	}
	where_from_cont(map, data, s);
}
