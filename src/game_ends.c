/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_ends.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:27:20 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/05 16:39:27 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	game_stuck(void)
{
	ft_printf("\r\n\r\n                 ");
	ft_printf("%sU  A R E  S T U C K%s\n\n", YLW, PPL);
	ft_printf("           ");
	ft_printf("T A P  %s'R'%s T O  T R Y  A G A I N\n", BLU, PPL);
	ft_printf("         ");
	ft_printf("O R  T A P  %s'ESC'%s  T O  G I V E  U P", R, PPL);
}

void	game_restart(t_game *game)
{
	char	*av;

	av = ft_strdup(game->map->av1);
	ft_printf("\n\n                 %sR E S T A R T I N G%s\n\n", YLW, RST);
	game_free(game, 0);
	so_long(av, 1);
}

void	game_win(t_game *game)
{
	ft_printf("\n\n                 ");
	ft_printf("%s******************", BLU);
	ft_printf("\n                 ");
	ft_printf("* %sG A M E  W I N %s*", YLW, BLU);
	ft_printf("\n                 ");
	ft_printf("%s******************%s\n\n", BLU, RST);
	game_free(game, 1);
}

void	game_loss(t_game *game)
{
	ft_printf("\n\n                   ");
	ft_printf("%s**************", YLW);
	ft_printf("\n                   ");
	ft_printf("* %sU  L O S E %s*", R, YLW);
	ft_printf("\n                   ");
	ft_printf("%s**************%s\n\n", YLW, RST);
	game_free(game, 1);
}

void	game_exit(t_game *game)
{
	ft_printf("\n\n                ");
	ft_printf("%sG A M E   E X I T E D%s\n\n", YLW, RST);
	game_free(game, 1);
}
