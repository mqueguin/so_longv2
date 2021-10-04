/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:05:18 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:06:28 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	get_size(int count)
{
	int	size;

	if (count == 0)
		return (1);
	size = 0;
	while (count > 0)
	{
		count /= 10;
		size++;
	}
	return (size);
}

void	draw_count(t_game *game)
{
	int	size;
	int	count;
	int	tmp;

	count = game->count;
	tmp = count;
	size = get_size(count) - 1;
	while (size >= 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->numbers.text_number[(tmp % 10)], size * 32, 0);
		tmp /= 10;
		size--;
	}
}
