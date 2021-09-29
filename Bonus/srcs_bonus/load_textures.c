/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:38:05 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/29 13:06:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

/** 
 * game->texts_img[0] = wall
 * game->texts_img[1] = floor
 * Rajouter la suite ici
 **/

int	load_textures_enemy(t_game *game)
{
	game->enemy.text_img_enemy = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY,
				&game->enemy.txt_enemy_x, &game->enemy.txt_enemy_y);
	if (!game->enemy.text_img_enemy)
	{
		free_tab2d(game->map);
		printf("Error\nUnable to load textures for the enemy\n");
		return (0);
	}
	place_enemy_on_map(game);
	return (1);
}

int	load_textures(t_game *game)
{
	int	i;
	char	**path;

	i = -1;
	path = ft_split(PATH, ' ');
	while (++i < 17)
	{
		game->texts_img[i] = mlx_xpm_file_to_image(game->mlx, path[i], &game->text_x[i],
					&game->text_y[i]);
		if (!game->texts_img[i])
		{
			free_tab2d(path);
			free_tab2d(game->map);
			printf("Error\nUnable to load textures\n");
			return (0);
		}
	}
	free_tab2d(path);
	return (1);
}