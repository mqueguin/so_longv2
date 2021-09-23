/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:53:19 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/23 16:07:03 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	animation_c(t_game *game, int i, int j)
{
	static	int	animationc = 0;
	
	if (animationc < 50)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[3], j * 32, i * 32);
		animationc++;
	}
	else if (animationc >= 50 && animationc < 100)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[4], j * 32, i * 32);
		animationc++;
	}
	if (animationc >= 100)
		animationc = 0;
}

void	animation_e(t_game *game, int i, int j)
{
	printf("Valeur de count_collectible : %d\n et nb_collectible : %d\n", game->count_collectible, game->nb_collectible);
	if (game->count_collectible == game->nb_collectible)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[6], j * 32, i * 32);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->texts_img[5], j * 32, i * 32);
}