/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:20:02 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:58:48 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	is_solvable(t_game *game)
{
	int		i;
	int		j;
	int		c;
	int		ret;
	char	**tmp;

	if (!game->map->on)
		return ;
	tmp = ft_strdup_double(game->map->tab);
	i = game->map->p->y;
	j = game->map->p->x;
	c = game->map->c;
	ret = recursive_checker(game->map, tmp, i, j);
	if (!ret)
	{
		ft_free(tmp);
		map_unsolve(game);
	}
	ft_free(tmp);
	ft_printf("   ");
	ft_printf("%s%s%s%s%s CAN BE COMPLETED %s%i%s DIFFERENT WAYS\n\n", BLU, B,
		game->map->av1, RST, BLU, YLW, ret, BLU);
	if (game->map->on)
		game->map->c = c;
}

void	is_square(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map || !map->on)
		return ;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (!((map->tab[i][j] == '1' && i == 0) || (map->tab[i][j] == '1'
				&& i == ft_linelen(map->tab)) || (map->tab[i][j] == '1'
				&& j == 0) || (map->tab[i][j] == '1'
				&& j == ft_strlen(map->tab[i]))
				|| ft_strlen_comp(map->tab)))
			{
				map_errors(map);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	count_all(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map->on)
		return ;
	while (map->tab[i])
	{
		j = 0;
		while (map->tab[i][j])
		{
			if (map->tab[i][j] == 'C')
				map->c++;
			if (map->tab[i][j] == 'P')
				make_player(map->p, i, j);
			if (map->tab[i][j] == 'E')
				make_player(map->e, i, j);
			if (map->tab[i][j] == 'N')
				map->n++;
			j++;
		}
		i++;
	}
}
