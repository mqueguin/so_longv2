/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:05:17 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:29:25 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static	void	initialize_struct(t_game *game)
{
	game->count = 0;
	game->count_collectible = 0;
	game->enemy.b_move = 1;
	//game->enemy.pos[0] = 0;
	//game->enemy.pos[1] = 0;
}

int	start_game(t_game *game)
{
	initialize_struct(game);
	initialize_mlx_and_window(game);
	if (!load_textures(game) || !load_textures_enemy(game)
		|| !load_textures_numbers(game))
		return (-1);
	game->img = mlx_new_image(game->mlx, game->res[0] * 32, game->res[1] * 32);
	mlx_hook(game->mlx_win, 2, 1L << 0, events_key_manager, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, echap_game_mouse, game);
	mlx_loop_hook(game->mlx, draw_map, game);
	mlx_loop(game->mlx);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (ac != 2)
	{
		ft_putendl_fd("Error\nThe arguments are wrong!", 2);
		return (-1);
	}
	if (!check_extension(av[1]) || !check_open_file(av[1]))
		return (-1);
	game.fd = open(av[1], O_RDONLY);
	if (!ft_parse_map(&game))
		return (-1);
	if ((start_game(&game)) == -1)
		return (-1);
	return (0);
}
