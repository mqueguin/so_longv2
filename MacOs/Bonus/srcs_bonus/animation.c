/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:53:19 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:31:37 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	draw_enemy_with_animation(t_game *game)
{
	static int	animation_enemy = 0;

	mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[1],
		game->enemy.pos[0] * 32,
		game->enemy.pos[1] * 32);
	if (animation_enemy < 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy.text_img_enemy[0], game->enemy.pos[0] * 32,
			game->enemy.pos[1] * 32);
		animation_enemy++;
	}
	else if (animation_enemy >= 50 && animation_enemy < 100)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy.text_img_enemy[1], game->enemy.pos[0] * 32,
			game->enemy.pos[1] * 32);
		animation_enemy++;
	}
	if (animation_enemy >= 100)
		animation_enemy = 0;
	if (game->enemy.pos[0] == game->player_pos[0]
		&& game->enemy.pos[1] == game->player_pos[1])
		exit_lose(game);
}

void	animation_c(t_game *game, int i, int j)
{
	static int	animationc = 0;

	if (animationc < 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[3], j * 32, i * 32);
		animationc++;
	}
	else if (animationc >= 50 && animationc < 100)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[4], j * 32, i * 32);
		animationc++;
	}
	if (animationc >= 100)
		animationc = 0;
}

void	animation_e(t_game *game, int i, int j)
{
	if (game->count_collectible == game->nb_collectible)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[6], j * 32, i * 32);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->texts_img[5], j * 32, i * 32);
}
