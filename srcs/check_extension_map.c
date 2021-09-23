/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:10:48 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/22 13:54:25 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * Ici on check si l'extension du fichier est valide et si le fichier existe
 * (En gros si il est possible de l ouvrir avec open)) 
**/
int	check_open_file(char *file)
{
	int	fd;

	//printf("Valeur de file : %s\n", file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nThe file doesn't exist\n");
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
			printf("Error\nThe extension must be '.ber'\n");
			return (0);
		}
	}
	return (1);
}
