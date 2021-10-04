/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:17:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/01 11:24:03 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	void	draw_second_part(t_game *game)
{
	if (game->map[game->player_pos[1]][game->player_pos[0]] == 'C'
			|| game->map[game->player_pos[1]][game->player_pos[0]] == 'P')
	{
		if (game->map[game->player_pos[1]][game->player_pos[0]] == 'C')
			game->count_collectible++;
		game->map[game->player_pos[1]][game->player_pos[0]] = '0';
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[2],
		game->player_pos[0] * 32, game->player_pos[1] * 32);
}

static	void	draw_collectible(t_game *game, int i, int j)
{
	//mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1],
	//	j * 32, i * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[3],
		j * 32, i * 32);
}

static	void	draw_exit(t_game *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1],
		j * 32, i * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[4],
		j * 32, i * 32);
}

int	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->y)
	{
		j = -1;
		while (++j < game->x)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->texts_img[0], j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				draw_collectible(game, i, j);
			else if (game->map[i][j] == 'E')
				draw_exit(game, i, j);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->texts_img[1], j * 32, i * 32);
			draw_second_part(game);
		}
	}
	return (0);
}
