/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:31:57 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:45:45 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_cont(t_game *game, char *mv, char *px)
{
	ft_printf("\r%sK E Y  P R E S S E S : %i %s", BLU, game->map->mv_c, RST);
	ft_printf("| %sB L O C K S  T R A V E L L E D : %i%s", R, game->map->px_c,
		RST);
	mlx_string_put(game->data->mlx, game->data->win, (9.5) * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111, mv);
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 3.5) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, px);
	free(mv);
	free(px);
}

void	print_moves_tiny(t_game *game, char *mv, char *px)
{
	mlx_string_put(game->data->mlx, game->data->win, 1 * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111, "K : ");
	mlx_string_put(game->data->mlx, game->data->win, 2.2 * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111, mv);
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 2.2) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, "B : ");
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 1) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, px);
	free(mv);
	free(px);
}

void	print_moves_small(t_game *game, char *mv, char *px)
{
	if (ft_strlen(game->map->tab[1]) < 15)
	{
		print_moves_tiny(game, mv, px);
		return ;
	}
	mlx_string_put(game->data->mlx, game->data->win, 2.2 * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111,
		"K P R E S S E S : ");
	mlx_string_put(game->data->mlx, game->data->win, (8.5) * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111, mv);
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 7.5) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, "B L O C K S : ");
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 2.5) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, px);
	free(mv);
	free(px);
}

void	print_moves(t_game *game)
{
	char	*mv;
	char	*px;

	mv = ft_itoa(game->map->mv_c);
	px = ft_itoa(game->map->px_c);
	mlx_put_image_to_window(game->data->mlx, game->data->win,
		game->data->asset[49], 0, (ft_linelen(game->map->tab)) * 20);
	if (ft_strlen(game->map->tab[1]) < 40)
	{
		print_moves_small(game, mv, px);
		return ;
	}
	mlx_string_put(game->data->mlx, game->data->win, 2.2 * 20,
		(ft_linelen(game->map->tab) + 0.75) * 20, 11111111,
		"K E Y  P R E S S E S : ");
	mlx_string_put(game->data->mlx, game->data->win,
		(ft_strlen(game->map->tab[0]) - 13.5) * 20, (ft_linelen(game->map->tab)
			+ 0.75) * 20, 11111111, "B L O C K S  T R A V E L L E D : ");
	mlx_string_put(game->data->mlx, game->data->win,
		ft_strlen(game->map->tab[0]) * 10, (ft_linelen(game->map->tab) + 0.75)
		* 20, 11111111, "R to restart | ESC to quit");
	print_cont(game, mv, px);
}
