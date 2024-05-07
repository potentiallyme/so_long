/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:20:11 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 16:24:37 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_col(t_game *game)
{
	int	s;

	s = 20;
	if (game->map->c > 0)
		game->map->c--;
	if (game->map->c < 1)
	{
		mlx_put_image_to_window(game->data->mlx, game->data->win,
			game->data->asset[31], game->map->e->x * 20, game->map->e->y * 20);
	}
}

int	is_it_ber(char *s)
{
	char	*chr;

	chr = ft_strrchr(s, '.');
	if (!s || !chr)
		return (0);
	if (ft_strcmp(chr, ".ber"))
		return (0);
	return (1);
}

char	*return_gnl(int fd)
{
	int		i;
	char	*s;
	char	*t;

	i = 0;
	t = get_next_line(fd);
	s = 0;
	while (t)
	{
		s = ft_strjoin(s, t);
		free(t);
		t = get_next_line(fd);
	}
	free(t);
	return (s);
}

void	is_sized(t_map *map)
{
	if (!map->on)
		return ;
	if (ft_strlen(map->tab[1]) > 116 || ft_linelen(map->tab) > 67)
	{
		ft_printf("%sThe map is too big, please ", BLU);
		ft_printf("make or use a smaller one...%s\n\n", RST);
		map_free(map);
	}
}
