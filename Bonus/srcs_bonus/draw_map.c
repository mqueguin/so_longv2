/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 14:17:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/23 16:48:20 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static	int	get_size(int count)
{
	int	size;
	if (count == 0)
		return (1);
	size = 0;
	while (count > 0)
	{
		count /= 10;
		size++;
	}
	return (size);
}

static	void	draw_count(t_game *game)
{
	int	size;
	int	count;
	int	tmp;

	count = game->count;
	tmp = count;
	size = get_size(count) - 1;
	while (size >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[(tmp % 10) + 7], size * 32, 0);
		tmp /= 10;
		size--;
	}
}

int	draw_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->y)
	{
		j = 0;
		while (j < game->x)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[0], j * 32, i * 32);
			else if (game->map[i][j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1], j * 32, i * 32);
				animation_c(game, i, j);
			}
			else if (game->map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1], j * 32, i * 32);
				animation_e(game, i, j);
			}
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1], j * 32, i * 32);
			draw_count(game);
			if (game->map[game->player_pos[1]][game->player_pos[0]] == 'C'
					|| game->map[game->player_pos[1]][game->player_pos[0]] == 'P')
			{
				if (game->map[game->player_pos[1]][game->player_pos[0]] == 'C')
					game->count_collectible++;
				game->map[game->player_pos[1]][game->player_pos[0]] = '0';
			}
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[2],
		game->player_pos[0] * 32, game->player_pos[1] * 32);
			j++;
		}
		i++;
	}
	return (0);
}
