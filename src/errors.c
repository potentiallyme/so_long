/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:38 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/06 18:38:45 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_errors(t_map *map)
{
	ft_printf("\n\nThe map isn't correct. Make sure there");
	ft_printf("are only %s1 P %sand %s1 E%s", BLU, RST, BLU, RST);
	ft_printf(", at least %s1 C%s, and it is a ", BLU, RST);
	ft_printf("%srectangular map surrounded by walls!%s\n\n", R, RST);
	map_free(map);
}

void	map_unsolve(t_game *game)
{
	ft_printf("\n\n%sThe map isn't correct. Make sure it", PPL);
	ft_printf(" can be solved! \n%sThe movement is quite", YLW);
	ft_printf(" unique, use some of the premade maps to");
	ft_printf(" get a hang of it, such as %stiny.ber ", R);
	ft_printf("%sor%s easy.ber%s\n\n", YLW, R, RST);
	no_data_free(game);
}

void	data_error(t_game *game, t_data *data)
{
	ft_printf("\n\nImage error, make sure all the images needed ");
	ft_printf("are in the %s'assets'%s folder\n\n", BLU, RST);
	data_free(data);
	map_free(game->map);
	free(game->map);
	free(game);
	exit(0);
}

void	file_error(void)
{
	ft_printf("\n\nFile can't be opened, make sure it exists in");
	ft_printf(" the %s'maps'%s folder\n\n", BLU, RST);
}

void	char_error(t_game *game)
{
	ft_printf("\n\nThere are characters you can't use!\n");
	ft_printf("Make sure there are only %s1 P %sand %s1 E", BLU, RST, BLU);
	ft_printf("%s, at least %s1 C%s, and it is a ", RST);
	ft_printf("%srectangular map surrounded by walls!%s\n\n", BLU, RST, YLW, RST);
	game_free(game, 1);
}
