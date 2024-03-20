/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:09:25 by gautier           #+#    #+#             */
/*   Updated: 2024/03/20 16:16:51 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <errno.h>

//Display the proper error message on the terminal
//before exiting the program
void	ft_error_1(t_data *data, int flag)
{
	errno = 1;
	if (flag == 1)
	{
		perror("Argument invalid. Please provide a single .ber file");
		exit(1);
	}
	if (flag == 2)
	{
		free_tab(data->map_data.map);
		perror("Error\nMap must be surrounded by walls");
		exit (1);
	}
	if (flag == 3)
	{
		free_tab(data->map_data.map);
		perror("Error\nMap must contain only '1', '0', 'C','E' or 'P' char");
		exit (1);
	}
	if (flag == 4)
	{
		free_tab(data->map_data.map);
		perror("Error\nExit and all collectibles must be reachable in the map");
		exit (1);
	}
}

//Same as above
void	ft_error_2(t_data *data, int flag)
{
	errno = 1;
	if (flag == 0)
	{
		free_tab(data->map_data.map);
		perror("Error\nMap must contain at least 1 collectible 'C'");
		exit (1);
	}
	if (flag == 1)
	{
		free_tab(data->map_data.map);
		perror("Error\nMap must contain strictly 1 exit 'E'");
		exit (1);
	}
	if (flag == 2)
	{
		free_tab(data->map_data.map);
		perror("Error\nMap must contain strictly 1 start position 'P'");
		exit (1);
	}
	if (flag == 3)
	{
		perror("Error\nMap file must be a .ber file");
		exit (1);
	}
}

//Same as above
void	ft_error_3(int flag)
{
	errno = 1;
	if (flag == 0)
	{
		perror("Error\nFile can't be opened");
		exit (1);
	}
	if (flag == 1)
	{
		perror("Error\nMap file is empty");
		exit (1);
	}
}
