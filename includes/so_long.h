/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 13:13:43 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/06 19:42:11 by mqueguin         ###   ########.fr       */
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

# define PATH "txt/w.xpm txt/f.xpm txt/steve.xpm txt/diamond.xpm txt/exit.xpm"

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
	int		player_pos[2];
	void	*texts_img[5];
	int		text_x[5];
	int		text_y[5];
	int		count;
	int		nb_collectible;
	int		count_collectible;

}				t_game;

int			check_extension(char *file);
int			check_open_file(char *file);
int			ft_parse_map(t_game *game);
void		check_elements_in_map(t_game *game, int b_exit, int b_player);
int			check_top_wall(t_game *game);
int			check_right_left_wall(t_game *game, int x_max);
void		initialize_mlx_and_window(t_game *game);
int			draw_map(t_game *game);
void		my_mlx_pixel_put(t_game *data, int x, int y, int color);
int			load_textures(t_game *game);
int			echap_game_mouse(t_game *game);
int			events_key_manager(int keycode, t_game *game);
void		ft_up(t_game *game);
void		ft_down(t_game *game);
void		ft_left(t_game *game);
void		ft_right(t_game *game);
int			exit_victory(t_game *game);

#endif
