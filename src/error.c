/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:09:25 by gautier           #+#    #+#             */
/*   Updated: 2024/03/13 14:31:34 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(t_data *data, int flag)
{
	if (flag == 1)
	{
		free_tab(data->map_data.map);
		perror("Argument invalid. Please provide a single .ber file");
		exit(1);
	}
	if (flag == 2)
	{
		free_tab(data->map_data.map);
		perror("error\nMap must be surrounded by walls");
		exit (1);
	}
	if (flag == 3)
	{
		free_tab(data->map_data.map);
		perror("error\nMap must contain only '1', '0', 'C', 'E' or 'P' characters");
		exit (1);
	}
	if (flag == 4)
	{
		free_tab(data->map_data.map);
		perror("error\nExit and all collectibles must be reachable in the map");
		exit (1);
	}
}

void	ft_error_count(t_data *data, int flag)
{
	if (flag == 0)
	{
		free_tab(data->map_data.map);
		perror("error\nmap must contain at least 1 collectible 'C'");
		exit (1);
	}
	if (flag == 1)
	{
		free_tab(data->map_data.map);
		perror("error\nmap must contain strictly 1 exit 'E'");
		exit(1);
	}
	if (flag == 2)
	{
		free_tab(data->map_data.map);
		perror("error\nmap must contain strictly 1 start position 'P'");
		exit (1);
	}
}
