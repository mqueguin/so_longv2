/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:34:42 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/16 17:42:05 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static	int	get_player_pos(t_game *game, int x, int y)
{
	game->player_pos[0] = x;
	game->player_pos[1] = y;
	return (1);
}

int	recover_playerpos_and_check_collect_exit(t_game *game)
{
	int	x;
	int	y;
	int	b_exit;
	int	b_player;

	y = -1;
	b_exit = 0;
	b_player = 0;
	game->nb_collectible = 0;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				b_player = get_player_pos(game, x, y);
			else if (game->map[y][x] == 'C')
				game->nb_collectible++;
			else if (game->map[y][x] == 'E')
				b_exit = 1;
			else if (game->map[y][x] != '0' && game->map[y][x] != '1')
			{
				free_tab2d(game->map);
				printf("Error\nLa map contient un %c et ce n'est pas un caractere valide\n", game->map[y][x]);
				return (0);
			}
		}
	}
	if (!b_exit || !game->nb_collectible || !b_player)
	{
		free_tab2d(game->map);
		printf("Error\nLa map n est pas complete il manque un collectible ou une sortie\n");
		return (0);
	}
	return (1);
}

static	int	ft_verif_rectangle(t_game *game)
{
	int	x;
	int	y;
	int	i;
	//int	j;
	
	x = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y])
	{
		i = 0;
		while (game->map[y][i])
			i++;
		if (i != x)
		{
			printf("Error\nThe map is not a rectangle\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_verif_map_is_close(t_game *game)
{
	int	x;
	int	y;
	int	x_max;

	x= -1;
	while (game->map[0][++x])
	{
		if (game->map[0][x] != '1')
		{
			printf("Error\nLe mur du haut n'est pas ferme\n");
			return (0);
		}
	}
	x_max = x;
	game->x = x_max;
	y = 0;
	while (game->map[y])
		y++;
	game->y = y;
	x = -1;
	while (game->map[y - 1][++x])
	{
		if (game->map[y - 1][x] != '1')
		{
			printf("Error\nLe mur du bas n'est pas ferme\n");
			return (0);
		}
	}
	y = -1;
	while (game->map[++y])
	{
		x = 0;
		if (game->map[y][0] != '1')
		{
			printf("Error\nLa colonne de gauche n'est pas ferme\n");
			return (0);
		}
		if (game->map[y][x_max - 1] != '1' || game->map[y][x_max])
		{
			printf("Error\nLa colonne de droite n'est pas ferme\n");
			return (0);
		}
	}
	game->res[0] = x_max;
	game->res[1] = y;
	return (1);
}

int	ft_parse_map(t_game *game)
{
	int		ret;
	char	buffer[5000];

	ft_memset(buffer, 0, 5000);
	ret = read(game->fd, buffer, 5000);
	if (ret < 0)
	{
		printf("Error\nError during read of file\n");
		return (0);
	}
	game->map = ft_split(buffer, '\n');
	if (!recover_playerpos_and_check_collect_exit(game))
		return (0);
	if (!ft_verif_rectangle(game) || !ft_verif_map_is_close(game))
		return (0);
	return (1);
}
