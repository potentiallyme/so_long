/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:26:31 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:20:17 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	cross_free(t_game *game)
{
	game_exit(game);
	return (1);
}

void	image_replacer(t_data *data, void *asset, char *name, int s)
{
	if (asset)
		mlx_destroy_image(data->mlx, asset);
	asset = mlx_xpm_file_to_image(data->mlx, name, &s, &s);
	mlx_destroy_image(data->mlx, asset);
}

void	image_destroyer(t_data *data)
{
	int	i;

	i = 0;
	while (i < 80)
	{
		if (data->asset[i] != NULL)
			mlx_destroy_image(data->mlx, data->asset[i]);
		i++;
	}
}

void	check_final(t_game *game)
{
	if (game->map)
		free(game->map);
	if (game->data)
		free(game->data);
	if (game)
		free(game);
	exit(0);
}

void	free_info(t_info *t)
{
	ft_free(t->tmp);
	free(t);
}
