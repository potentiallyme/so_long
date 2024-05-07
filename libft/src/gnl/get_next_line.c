/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 07:29:26 by lmoran            #+#    #+#             */
/*   Updated: 2024/01/30 16:40:12 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_conditions(int fd)
{
	char	tvar;

	tvar = 0;
	if (fd < 0)
		return (0);
	if (read(fd, &tvar, 0) == -1)
		return (0);
	return (1);
}

void	ft_clean(char *fd_l, char (*s)[BUFFER_SIZE + 1])
{
	int		i;
	char	*s_ptr;

	i = 0;
	while (fd_l[i] != '\0' && fd_l[i] != '\n')
		i++;
	fd_l[++i] = '\0';
	s_ptr = ft_strchr(*s, '\n');
	i = 0;
	if (s_ptr)
		ft_strlcpy_gnl(*s, s_ptr + 1, BUFFER_SIZE);
	else
		ft_bzero(*s, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	s[2048][BUFFER_SIZE + 1];
	char		*rd_l;

	rd_l = 0;
	if (!ft_conditions(fd))
		return (NULL);
	if (s[fd][0] != 0)
	{
		rd_l = ft_strdup_gnl(s[fd]);
		if (ft_strchr(rd_l, '\n'))
			return (ft_clean(rd_l, &s[fd]), rd_l);
		ft_bzero(s[fd], BUFFER_SIZE);
	}
	while (read(fd, s[fd], BUFFER_SIZE) > 0)
	{
		rd_l = ft_strjoin_gnl(rd_l, s[fd]);
		if (ft_strchr(rd_l, '\n'))
			return (ft_clean(rd_l, &s[fd]), rd_l);
		ft_bzero(s[fd], BUFFER_SIZE);
	}
	if (rd_l)
		return (ft_clean (rd_l, &s[fd]), rd_l);
	return (NULL);
}
