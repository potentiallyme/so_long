/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:58:02 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:09:05 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_up_game(t_game *game, int i, int j)
{
	if (game->map->tab[i][j] == 'C')
		put_up(game->data, game->data->asset[0], i, j);
	else if (game->map->tab[i][j] == 'E')
		put_up(game->data, game->data->asset[1], i, j);
	else if (game->map->tab[i][j] == '0')
		put_up(game->data, game->data->asset[2], i, j);
	else if (game->map->tab[i][j] == 'N')
		put_up(game->data, game->data->asset[9], i, j);
}

void	make_game(t_game *game)
{
	int	i;
	int	j;

	if (!game->map->on)
		return ;
	i = 0;
	while (i < ft_linelen(game->map->tab))
	{
		j = 0;
		while (j < ft_strlen(game->map->tab[i]))
		{
			if (game->map->tab[i][j] == 'C' || game->map->tab[i][j] == 'E'
				|| game->map->tab[i][j] == '0' || game->map->tab[i][j] == 'N')
				put_up_game(game, i, j);
			else if (game->map->tab[i][j] == 'P')
				what_way(game, i, j);
			else if (game->map->tab[i][j] == '1')
				pick_floor(game->data, i, j);
			else
				char_error(game);
			j++;
		}
		i++;
	}
}

void	init_assets_zero(t_data *data)
{
	int	i;

	i = 0;
	while (i < 80)
	{
		data->asset[i] = NULL;
		i++;
	}
}

t_data	*init_mlx(t_game *game, void *mlx_ptr, void *win_ptr)
{
	t_data	*data;
	int		w;

	w = 20;
	data = (t_data *)malloc(sizeof(t_data));
	if (!(data))
		data_error(game, data);
	data->mlx = mlx_ptr;
	data->win = win_ptr;
	init_assets_zero(data);
	basic_assets(game, data);
	boy_assets(game, data);
	wall_assets(game, data);
	trail_assets(game, data);
	anim_assets(game, data);
	mm_sec(game, data, 5, "./assets/closed_off.xpm");
	mm_sec(game, data, 7, "./assets/trail_end_up.xpm");
	mm_sec(game, data, 70, "./assets/ball_side.xpm");
	mm_sec(game, data, 79, "./assets/ball_vert.xpm");
	mm_sec(game, data, 9, "./assets/enemy.xpm");
	mm_sec_big(game, data, 49, "./assets/bg.xpm");
	mm_sec_big(game, data, 48, "./assets/restart.xpm");
	mm_sec_big(game, data, 47, "./assets/end_all.xpm");
	return (data);
}

t_data	*init_data(t_game *game)
{
	int		screen_x;
	int		screen_y;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*data;

	if (!game->map->on)
		return (0);
	screen_x = 0;
	screen_y = 0;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	win_ptr = mlx_new_window(mlx_ptr, ((ft_strlen(game->map->tab[0])) * 20),
			(ft_linelen(game->map->tab) + 1) * 20, "L A B Y R I N T H O S");
	data = init_mlx(game, mlx_ptr, win_ptr);
	return (data);
}
