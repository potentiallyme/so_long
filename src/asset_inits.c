/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:34:57 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:04:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	wall_assets(t_game *game, t_data *data)
{
	mm_sec(game, data, 21, "./assets/wall1.xpm");
	mm_sec(game, data, 22, "./assets/wall2.xpm");
	mm_sec(game, data, 23, "./assets/wall3.xpm");
	mm_sec(game, data, 24, "./assets/wall4.xpm");
	mm_sec(game, data, 25, "./assets/wall5.xpm");
	mm_sec(game, data, 26, "./assets/wall6.xpm");
	mm_sec(game, data, 27, "./assets/wall7.xpm");
	mm_sec(game, data, 28, "./assets/wall8.xpm");
	mm_sec(game, data, 29, "./assets/wall9.xpm");
}

void	boy_assets(t_game *game, t_data *data)
{
	mm_sec(game, data, 13, "./assets/boy_up.xpm");
	mm_sec(game, data, 12, "./assets/boy_right.xpm");
	mm_sec(game, data, 11, "./assets/boy_down.xpm");
	mm_sec(game, data, 14, "./assets/boy_left.xpm");
}

void	basic_assets(t_game *game, t_data *data)
{
	mm_sec(game, data, 0, "./assets/collectible.xpm");
	mm_sec(game, data, 1, "./assets/exit_closed.xpm");
	mm_sec(game, data, 31, "./assets/exit_open.xpm");
	mm_sec(game, data, 2, "./assets/floor.xpm");
}

void	trail_assets(t_game *game, t_data *data)
{
	mm_sec(game, data, 36, "./assets/trail_up.xpm");
	mm_sec(game, data, 37, "./assets/trail_right.xpm");
	mm_sec(game, data, 38, "./assets/trail_down.xpm");
	mm_sec(game, data, 39, "./assets/trail_left.xpm");
}
