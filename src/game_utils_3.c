/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:04:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:06:09 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mm_sec(t_game *game, t_data *data, int at, char *name)
{
	int	s;

	s = 20;
	data->asset[at] = mlx_xpm_file_to_image(data->mlx, name, &s, &s);
	if (!data->asset[at])
		data_error(game, data);
}

void	mm_sec_big(t_game *game, t_data *data, int at, char *name)
{
	int	x;
	int	y;

	x = 68 * 20;
	y = 128 * 20;
	data->asset[at] = mlx_xpm_file_to_image(data->mlx, name, &x, &y);
	if (!data->asset[at])
		data_error(game, data);
}

void	av_checker(char *av, int flag)
{
	if (flag == 1)
		free(av);
}

int	check_fd(int fd, t_game *game)
{
	if (fd < 1)
	{
		free(game);
		file_error();
		return (0);
	}
	return (1);
}
