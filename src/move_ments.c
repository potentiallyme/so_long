/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ments.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:53:05 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:29:36 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	game->map->mv_c++;
	if (keycode == 65307)
		game_exit(game);
	else if (keycode == 'r')
		game_restart(game);
	else if (is_stuck(game, game->map->p->y, game->map->p->x))
		game_stuck();
	else if (keycode == 'w' || keycode == 65362)
		go_up(game, game->map->p->y, game->map->p->x);
	else if (keycode == 'd' || keycode == 65363)
		go_right(game, game->map->p->y, game->map->p->x);
	else if (keycode == 's' || keycode == 65364)
		go_down(game, game->map->p->y, game->map->p->x);
	else if (keycode == 'a' || keycode == 65361)
		go_left(game, game->map->p->y, game->map->p->x);
	else if (keycode == 'i')
		instructions_message();
	return (1);
}

void	go_left(t_game *game, int y, int x)
{
	int	rot;

	rot = 0;
	while (game->map->tab[y][(x - 1)] != '1')
	{
		if (game->map->tab[y][(x - 1)] == 'C')
			update_col(game);
		else if (game->map->tab[y][(x - 1)] == 'E' && game->map->c == 0)
			return (update_game(game, y, x - 1, rot), game_win(game));
		else if (game->map->tab[y][(x - 1)] == 'E' && game->map->c > 0)
			break ;
		else if (game->map->tab[y][(x - 1)] == 'N')
			return (game_loss(game));
		game->map->tab[y][x] = '1';
		x--;
		game->map->dir = 4;
		game->map->px_c++;
		print_moves(game);
		update_game(game, y, x, rot);
		rot++;
	}
	close_trail(game, y, x, rot);
	static_boy(game, x, y);
	game->map->p->x = x;
	game->map->p->y = y;
}

void	go_right(t_game *game, int y, int x)
{
	int	rot;

	rot = 0;
	while (game->map->tab[y][(x + 1)] != '1')
	{
		if (game->map->tab[y][(x + 1)] == 'C')
			update_col(game);
		else if (game->map->tab[y][(x + 1)] == 'E' && game->map->c == 0)
			return (update_game(game, y, x + 1, rot), game_win(game));
		else if (game->map->tab[y][(x + 1)] == 'E' && game->map->c > 0)
			break ;
		else if (game->map->tab[y][(x + 1)] == 'N')
			return (game_loss(game));
		game->map->tab[y][x] = '1';
		x++;
		game->map->dir = 2;
		game->map->px_c++;
		print_moves(game);
		update_game(game, y, x, rot);
		rot++;
	}
	close_trail(game, y, x, rot);
	static_boy(game, x, y);
	game->map->p->x = x;
	game->map->p->y = y;
}

void	go_down(t_game *game, int y, int x)
{
	int	rot;

	rot = 0;
	while (game->map->tab[(y + 1)][x] != '1')
	{
		if (game->map->tab[(y + 1)][x] == 'C')
			update_col(game);
		else if (game->map->tab[(y + 1)][x] == 'E' && game->map->c == 0)
			return (update_game(game, y + 1, x, rot), game_win(game));
		else if (game->map->tab[(y + 1)][x] == 'E' && game->map->c > 0)
			break ;
		else if (game->map->tab[(y + 1)][x] == 'N')
			return (game_loss(game));
		game->map->tab[y][x] = '1';
		y++;
		game->map->dir = 3;
		game->map->px_c++;
		print_moves(game);
		update_game(game, y, x, rot);
		rot++;
	}
	close_trail(game, y, x, rot);
	static_boy(game, x, y);
	game->map->p->x = x;
	game->map->p->y = y;
}

void	go_up(t_game *game, int y, int x)
{
	int	rot;

	rot = 0;
	while (game->map->tab[(y - 1)][x] != '1')
	{
		if (game->map->tab[(y - 1)][x] == 'C')
			update_col(game);
		else if (game->map->tab[(y - 1)][x] == 'E' && game->map->c == 0)
			return (update_game(game, y - 1, x, rot), game_win(game));
		else if (game->map->tab[(y - 1)][x] == 'E' && game->map->c > 0)
			break ;
		else if (game->map->tab[(y - 1)][x] == 'N')
			return (game_loss(game));
		game->map->tab[y][x] = '1';
		y--;
		game->map->dir = 1;
		game->map->px_c++;
		print_moves(game);
		update_game(game, y, x, rot);
		rot++;
	}
	close_trail(game, y, x, rot);
	static_boy(game, x, y);
	game->map->p->x = x;
	game->map->p->y = y;
}
