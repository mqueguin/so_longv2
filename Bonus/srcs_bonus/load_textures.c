/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:38:05 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/01 12:16:28 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

/** 
 * game->texts_img[0] = wall
 * game->texts_img[1] = floor
 * Rajouter la suite ici
 **/

int	load_textures_numbers(t_game *game)
{
	char	**path;
	int		i;

	path = ft_split(PATH_NUMBERS, ' ');
	i = -1;
	while(++i < 10)
	{
		game->numbers.text_number[i] = mlx_xpm_file_to_image(game->mlx,
			path[i], &game->numbers.text_numbers_x[i],
			&game->numbers.text_numbers_y[i]);
		if (!game->numbers.text_number[i])
		{
			free_tab2d(game->map);
			free_tab2d(path);
			ft_putendl_fd("Error\nUnable to load numbers textures", 2);
			return (0);
		}
	}
	free_tab2d(path);
	return (1);
}

int	load_textures_enemy(t_game *game)
{
	char **path;

	path = ft_split(PATH_ENEMY, ' ');
	game->enemy.text_img_enemy[0] = mlx_xpm_file_to_image(game->mlx, path[0],
				&game->enemy.txt_enemy_x[0], &game->enemy.txt_enemy_y[0]);
	game->enemy.text_img_enemy[1] = mlx_xpm_file_to_image(game->mlx, path[1],
				&game->enemy.txt_enemy_x[1], &game->enemy.txt_enemy_y[1]);
	if (!game->enemy.text_img_enemy[0] || !game->enemy.text_img_enemy[1])
	{
		free_tab2d(game->map);
		free_tab2d(path);
		printf("Error\nUnable to load textures for the enemy\n");
		return (0);
	}
	free_tab2d(path);
	place_enemy_on_map(game);
	return (1);
}

int	load_textures(t_game *game)
{
	int	i;
	char	**path;

	i = -1;
	path = ft_split(PATH, ' ');
	while (++i < 7)
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