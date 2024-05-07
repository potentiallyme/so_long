/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoran <lmoran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:33:41 by lmoran            #+#    #+#             */
/*   Updated: 2024/03/08 15:29:19 by lmoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>

// C O L O R S
# define R "\e[38;5;196m"
# define B "\e[1m"
# define ORA "\e[38;5;208m"
# define RST "\e[0m"
# define BLU "\e[38;5;27m"
# define PCH "\e[38;5;223m"
# define UNL "\e[4m"
# define YLW "\e[38;5;226m"
# define PPL "\e[38;5;93m"
# define FDE "\e[2m"

// S T R U C T U R E S
typedef struct s_player
{
	int			x;
	int			y;
	int			is;
}				t_player;

typedef struct s_map
{
	char		**tab;
	char		*av1;
	int			c;
	int			n;
	int			on;
	int			dir;
	int			mv_c;
	int			px_c;
	t_player	*e;
	t_player	*p;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*asset[80];
}				t_data;

typedef struct s_game
{
	t_data		*data;
	t_map		*map;
}				t_game;

typedef struct s_info
{
	char		**tmp;
	int			c;
}				t_info;

// !TO SORT
void			data_error(t_game *game, t_data *data);
void			mm_sec(t_game *game, t_data *data, int at, char *name);
void			file_error(void);
void			print_moves(t_game *game);
void			soft_free(t_game *game);
void			check_final(t_game *game);
void			char_error(t_game *game);
void			init_map_zero(t_map *map);
void			map_unsolve(t_game *game);
void			close_trail(t_game *game, int y, int x, int rot);
void			close_trail_cont(t_game *game, int y, int x);
void			no_data_free(t_game *game);
void			mm_sec_big(t_game *game, t_data *data, int at, char *name);
void			free_info(t_info *t);
void			*trail_dir(t_game *game);
void			*info_maker(t_map *map, char **tmp);
int				recursive_cont(t_map *map, char **tmp, int y, int x);
void			data_free(t_data *data);

// M A I N . C
void			loop_game(t_game *game);
void			so_long(char *av, int flag);

// P A R S E _ C O R E . C
void			is_solvable(t_game *game);
void			is_square(t_map *map);
void			count_all(t_map *map);

// P A R S E _ U T I L S . C
void			update_col(t_game *game);
int				is_it_ber(char *s);
int				recursive_checker(t_map *map, char **tmp, int y, int x);
char			*return_gnl(int fd);
void			is_sized(t_map *map);

// S O L V E _ U T I L S . C
int				move_right(t_map *map, char **tmp, int y, int x);
int				move_left(t_map *map, char **tmp, int y, int x);
int				move_up(t_map *map, char **tmp, int y, int x);
int				move_down(t_map *map, char **tmp, int y, int x);
int				check_exit(t_map *map, char **tmp, int y, int x);

// S T R U C T _ U T I L S . C
t_map			*init_map(int fd);
void			make_player(t_player *p, int i, int j);

// E R R O R S _ F R E E S . C
void			map_free(t_map *map);
void			map_errors(t_map *map);
void			image_destroyer(t_data *data);
void			image_replacer(t_data *data, void *asset, char *name, int s);

// M A K E _ G A M E . C
void			make_game(t_game *game);
t_data			*init_data(t_game *game);
t_data			*init_mlx(t_game *game, void *mlx_ptr, void *win_ptr);

// G A M E _ U T I L S . C
void			put_up(t_data *data, void *asset, int w, int l);
void			what_way(t_game *game, int i, int j);
void			pick_floor(t_data *data, int i, int j);
void			what_dir(t_game *game, int j, int i);

// G A M E _ U T I L S _ 2 . C
void			where_from(t_map *map, t_data *data, int s);
void			where_from_cont(t_map *map, t_data *data, int s);
void			mlx_window_thing(t_game *game, void *asset, int x, int y);

// G A M E _ U T I L S _ 3 . C
void			av_checker(char *av, int flag);
int				check_fd(int fd, t_game *game);

// M O V E _ M E N T S . C
int				key_hook(int keycode, t_game *game);
void			go_left(t_game *game, int y, int x);
void			go_right(t_game *game, int y, int x);
void			go_down(t_game *game, int y, int x);
void			go_up(t_game *game, int y, int x);

// U P D A T E _ G A M E . C
void			update_game(t_game *game, int y, int x, int rot);
int				is_stuck(t_game *game, int y, int x);

// M A K E _ T R A I L . C
void			trail_up(t_game *game, int y, int x, int rot);
void			trail_right(t_game *game, int y, int x, int rot);
void			trail_down(t_game *game, int y, int x, int rot);
void			trail_left(t_game *game, int y, int x, int rot);

// A S S E T _ I N I T S . C
void			wall_assets(t_game *game, t_data *data);
void			boy_assets(t_game *game, t_data *data);
void			basic_assets(t_game *game, t_data *data);
void			trail_assets(t_game *game, t_data *data);

// G A M E _ E N D S . C
void			game_stuck(void);
void			game_restart(t_game *game);
void			game_win(t_game *game);
void			game_loss(t_game *game);
void			game_exit(t_game *game);

// F R E E S . C
void			game_free(t_game *game, int ex);
int				cross_free(t_game *game);

// W E L C O M E _ I N . C
void			welcome_message(void);
void			instructions_message(void);

// S T A T I C _ A N I M S . C
void			anim_assets(t_game *game, t_data *data);
int				static_boy(t_game *game, int x, int y);
void			static_sync(t_game *game, int interval);

#endif