/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:22:51 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/22 19:55:01 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	parse_it(char **map, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P' || map[i][j] == 'C' || map[i][j] == 'E')
		return (1);
	return (0);
}

static int	wall_check(char **map, int i, int j)
{
	int len;
	int lines;

	len = ft_strlen(map[0]);
	lines = ft_lines_double(map);
	if ((i == 0 || i == lines) && map[i][j] != '1')
		return (0);
	if (((i != 0 || i != lines) && (j == 0 || j == len)) && map[i][j] != '1')
		return (0);	
	return (1);
}

static char *fuse_em(int fd)
{
	char *tmp;
	char *tmp_g;

	tmp = 0;
	tmp_g = get_next_line(fd);
	while (tmp_g)
	{
		tmp = ft_strjoin(tmp, tmp_g);
		tmp_g = get_next_line(fd);
	}
	return (tmp);
}

static char	**check_and_make(int fd)
{
	int		i;
	int		lines;
	char	**map;

	i = 0;
	map = 0;
	lines = 0;
	map = ft_split(fuse_em(fd), '\n');
	lines = ft_lines_double(map);
	i = 0;
	if (ft_iterate_double(map, parse_it) && ft_iterate_double(map, wall_check) && ft_strlen_comp(map))
		return (map);
	return (NULL);
}

// int	main(int ac, char **av)
// {
// 	int fd;
// 	char **map;

// 	fd = open(av[1], O_RDWR);
// 	map = NULL;
// 	map = check_and_make(fd);
// 	close(fd);
// 	if (map)
// 		ft_putstr_double(map);
// 	else
// 		ft_putstr("fail");
// 	(void)ac;
// }
