/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:40 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:32:14 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	loop_game(t_game *game)
{
	if (!game->map->on)
		return ;
	game->map->mv_c = 0;
	print_moves(game);
	mlx_hook(game->data->win, KeyPress, KeyPressMask, &key_hook, game);
	mlx_hook(game->data->win, 17, 1L << 17, cross_free, game);
	mlx_loop(game->data->mlx);
}

void	so_long(char *av, int flag)
{
	t_game	*game;
	int		fd;

	game = ft_calloc(1, sizeof(t_game));
	fd = open(av, O_RDWR);
	if (!check_fd(fd, game))
		return ;
	game->map = init_map(fd);
	close(fd);
	if (game->map->on)
		game->map->av1 = ft_strdup(av);
	if (flag == 1)
		free(av);
	is_square(game->map);
	is_sized(game->map);
	is_solvable(game);
	if (!game->map->on)
		check_final(game);
	game->data = init_data(game);
	if (!game->data)
		exit(0);
	make_game(game);
	loop_game(game);
	game_free(game, 1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !is_it_ber(av[1]))
	{
		ft_printf("\n%sERROR%s\nMake sure to have the f", R, YLW);
		ft_printf("ollowing format: %s./so_long maps/\"map_name\".ber\n\n%s",
			BLU, RST);
		return (0);
	}
	welcome_message();
	so_long(av[1], 0);
}
