/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:13:43 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/01 12:16:25 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <mlx.h>

# define PATH "txt/w.xpm txt/f.xpm txt/steve.xpm txt/diamond.xpm txt/diamond2.xpm txt/exit.xpm txt/exit2.xpm"
# define PATH_NUMBERS "txt/0.xpm txt/1.xpm txt/2.xpm txt/3.xpm txt/4.xpm txt/5.xpm txt/6.xpm txt/7.xpm txt/8.xpm txt/9.xpm"
# define PATH_ENEMY "txt/creeper.xpm txt/creeper2.xpm"

typedef struct	s_enemy
{
	int		enemy_pos[2];
	void	*text_img_enemy[2];
	int		txt_enemy_x[2];
	int		txt_enemy_y[2];
	int		b_move;
}				t_enemy;

typedef struct	s_numbers
{
	void	*text_number[10];
	int		text_numbers_x[10];
	int		text_numbers_y[10];
}				t_numbers;


typedef struct s_game
{
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		x;
	int		y;
	int		endian;
	int		fd;
	int		res[2];
	char	**map;
	int		player_pos[2]; //x: 0, y: 1
	void	*texts_img[7];
	int		text_x[7];
	int		text_y[7];
	int		count;
	int		nb_collectible;
	int		count_collectible;
	t_enemy	enemy;
	t_numbers	numbers;
}				t_game;

int			check_extension(char *file);
int			check_open_file(char *file);
int			ft_parse_map(t_game *game);
void		initialize_mlx_and_window(t_game *game);
int			draw_map(t_game *game);
//int			recover_player_collect_and_exit_pos(t_game *game);
void		my_mlx_pixel_put(t_game *data, int x, int y, int color);
int			load_textures(t_game *game);
int			echap_game_mouse(t_game *game);
int			events_key_manager(int keycode, t_game *game);
void		ft_up(t_game *game);
void		ft_down(t_game *game);
void		ft_left(t_game *game);
void		ft_right(t_game *game);
int			exit_victory(t_game *game);
void		animation_c(t_game *game, int i, int j);
void		animation_e(t_game *game, int i, int j);

int			load_textures_enemy(t_game *game);
int 		load_textures_numbers(t_game *game);
int			place_enemy_on_map(t_game *game);
void		enemy_moves(t_game *game);
void		draw_enemy_with_animation(t_game *game);
#endif
