/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:10:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:31:32 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	check_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error\nThe file doesnt exist", 2);
		return (0);
	}
	return (1);
}

int	check_extension(char *file)
{
	int		len;
	int		i;

	len = ft_strlen(file);
	i = -1;
	if (file)
	{
		while (++i < len - 4)
			file++;
		if (ft_strncmp(file, ".ber", 4))
		{
			ft_putendl_fd("Error\nThe extension must be '.ber'...", 2);
			return (0);
		}
	}
	return (1);
}
