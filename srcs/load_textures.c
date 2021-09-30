/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:38:05 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/30 18:35:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/** 
 * game->texts_img[0] = wall
 * game->texts_img[1] = floor
 * Rajouter la suite ici
 **/

int	load_textures(t_game *game)
{
	int		i;
	char	**path;

	i = -1;
	path = ft_split(PATH, ' ');
	while (++i < 5)
	{
		game->texts_img[i] = mlx_xpm_file_to_image(game->mlx, path[i],
				&game->text_x[i], &game->text_y[i]);
		if (!game->texts_img[i])
		{
			free_tab2d(path);
			free_tab2d(game->map);
			printf("Error\nImpossible de charger les textures\n");
			return (0);
		}
	}
	free_tab2d(path);
	return (1);
}
