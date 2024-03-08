/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:53:48 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 16:02:58 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//check if the map has the right numbers of collectibles,
//start position and exit position
void	check_counts(t_data *data)
{
	if (data->map_data.C_count < 1)
		ft_error_count(0);
	if (data->map_data.E_count != 1)
		ft_error_count(1);
	if (data->map_data.P_count != 1)
		ft_error_count(2);
}

//initiliaze x and y indexes in the t_map_data structure for P and E,
//needed to check if the path between them is valid
void	init_player_and_exit(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			if (data->map_data.map[x][y] == 'P')
			{
				data->map_data.P_indexes.x = x;
				data->map_data.P_indexes.y = y;
			}
			if (data->map_data.map[x][y] == 'E')
			{
				data->map_data.E_indexes.x = x;
				data->map_data.E_indexes.y = y;
			}
			y++;
		}
		x++;
	}
}

//replace all characters but '1' with a 'F'
//if the map is well written, there is only '1' and 'F' left
void	flood_map(char **map, t_indexes indexes)
{
	if (map[indexes.x][indexes.y] == '1' || map[indexes.x][indexes.y] == 'F')
			return ; 
	map[indexes.x][indexes.y] = 'F';
	flood_map(map, (t_indexes){indexes.x, indexes.y + 1});
	flood_map(map, (t_indexes){indexes.x, indexes.y - 1});
	flood_map(map, (t_indexes){indexes.x + 1, indexes.y});
	flood_map(map, (t_indexes){indexes.x - 1, indexes.y});
}

//check if there is any 'C', 'E' left in the map
//if not, it means that there is no way to access all collectibles 
//and/or the exit == Map Error
int	check_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

//check if there is a valid path to all collectibles and to the exit
//by using a recursive flooding function described above
void	is_path_valid(char **av, t_data *data)
{
	char **new_map;
	t_indexes indexes;

	init_player_and_exit(data);
	new_map = read_map(av);
	indexes = data->map_data.P_indexes;
	flood_map(new_map, indexes);
	if (!check_path(new_map))
	{
		free_tab(new_map);
		ft_error(4);
	}
	free_tab(new_map);
}
