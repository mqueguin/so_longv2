/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:54:23 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 12:53:36 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	events_key_manager(int keycode, t_game *game)
{
	if (keycode == 65307)
		echap_game_mouse(game);
	if (keycode == 119)
		ft_up(game);
	if (keycode == 115)
		ft_down(game);
	if (keycode == 97)
		ft_left(game);
	if (keycode == 100)
		ft_right(game);
	return (0);
}

int	echap_game_mouse(t_game *game)
{
	ft_putendl_fd("You quit the game !", 1);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_tab2d(game->map);
	exit (0);
}
