/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:54:23 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/30 18:47:30 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	events_key_manager(int keycode, t_game *game)
{
	if (keycode == 53)
		echap_game_mouse(game);
	if (keycode == 13)
		ft_up(game);
	if (keycode == 1)
		ft_down(game);
	if (keycode == 0)
		ft_left(game);
	if (keycode == 2)
		ft_right(game);
	return (0);
}

int	echap_game_mouse(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_tab2d(game->map);
	exit(0);
}
