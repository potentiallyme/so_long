/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:26:50 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:41:38 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void empty_map(t_map)
// {

// }

void	game_free(t_game *game, int ex)
{
	if (!game->map->on)
		check_final(game);
	map_free(game->map);
	image_destroyer(game->data);
	mlx_destroy_window(game->data->mlx, game->data->win);
	if (game->data->mlx)
		mlx_destroy_display(game->data->mlx);
	free(game->data->mlx);
	free(game->data);
	free(game->map);
	free(game);
	if (ex == 1)
		exit(0);
}

void	no_data_free(t_game *game)
{
	map_free(game->map);
	free(game->map);
	free(game);
	exit(0);
}

void	map_free(t_map *map)
{
	if (map->on)
	{
		if (map->p)
			free(map->p);
		if (map->tab)
			ft_free(map->tab);
		if (map->e)
			free(map->e);
		if (map->av1)
			free(map->av1);
		map->on = 0;
	}
}

void	data_free(t_data *data)
{
	image_destroyer(data);
	mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
}
