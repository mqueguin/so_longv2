/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:34:42 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/30 19:43:47 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	get_player_pos(t_game *game, int x, int y)
{
	game->player_pos[0] = x;
	game->player_pos[1] = y;
	return (1);
}

static	int	recover_and_check_cpe(t_game *game, int x, int y, int b_player)
{
	int	b_exit;

	b_exit = 0;
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
				ft_putstr_fd("Error\nThe card contains an invalid character", 2);
				return (0);
			}
		}
	}
	check_elements_in_map(game, b_exit, b_player);
	return (1);
}

static	int	ft_verif_rectangle(t_game *game)
{
	int	x;
	int	y;
	int	i;

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

	x_max = check_top_wall(game);
	if (x_max == 0)
		return (0);
	game->x = x_max;
	y = 0;
	while (game->map[y])
		y++;
	game->y = y;
	x = -1;
	while (game->map[y - 1][++x])
		if (game->map[y - 1][x] != '1')
			return (ft_putendl_fd("Error\nLe mur du bas n'est pas ferme", 2));
	y = -1;
	while (game->map[++y])
	{
		x = 0;
		if (game->map[y][0] != '1')
			return (ft_putendl_fd("Error\nLe mur de gauche n'est pas ferme", 2));
		if (game->map[y][x_max - 1] != '1' || game->map[y][x_max])
			return (ft_putendl_fd("Error\nLe mur de droite n'est pas ferme", 2));
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
	if (!recover_and_check_cpe(game, -1, -1, 0))
		return (0);
	if (!ft_verif_rectangle(game) || !ft_verif_map_is_close(game))
		return (0);
	return (1);
}
