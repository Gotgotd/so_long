/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:22:15 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 16:03:52 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//check if the map is a rectangle. Otherwise, error message.
void	is_map_rectangle(t_data *data)
{
	unsigned int	x;

	x = 0;
	data->map_data.nb_column = ft_strlen(data->map_data.map[x]);
	while (data->map_data.map[x])
	{
		if (ft_strlen(data->map_data.map[x]) != data->map_data.nb_column)
		{
			perror("Error\nMap must be a rectangle.");
			exit(1);
		}
		x++;
	}
	data->map_data.nb_row = x;
	if (x == data->map_data.nb_column)
	{
		perror("Error\nMap must be a rectangle.");
		exit(1);
	}
}

void	check_char(char c, t_data *data)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P' )
		ft_error(3);
	else if (c == 'C')
		data->map_data.C_count += 1;
	else if (c == 'E')
		data->map_data.E_count += 1;
	else if (c == 'P')
		data->map_data.P_count += 1;
}

//check if the map is surrounded by walls and made of
//the good characters and the right numbers of them
void	check_walls_and_char(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			check_char(data->map_data.map[x][y], data);
			if (data->map_data.map[0][y] != '1')
				ft_error(2);
			if (data->map_data.map[x][0] != '1' 
				|| data->map_data.map[x][data->map_data.nb_column - 1] != '1')
				ft_error(2);
			if (data->map_data.map[data->map_data.nb_row - 1][y] != '1')
				ft_error(2);
			y++;
		}
		x++;
	}
	check_counts(data);
}

//extract map from file and store it into a double tab
char	**read_map(char **av)
{
	char 	*line;
	char	**map;
	char	*map_line;
	int		map_file;

	map_file = open(av[1], O_RDONLY, 0777);
	if (map_file == -1)
	{
		perror("Error\nMap file unvalid.");
		exit(1);
	}
	map_line = ft_strdup("");
	while(1)
	{
		line = get_next_line(map_file);
		if (!line)
			break ;
		map_line = ft_strjoin_and_free(map_line, line);
		free(line);
	}
	map = ft_split(map_line, '\n');
	close(map_file);
	free(map_line);
	return (map);
}

//read the map from the file and put it in a double tab.
//then, check if it is valid to be used by the program.
void	map_parsing(char **av, t_data *data)
{
	//unsigned int x = 0;
	init_map_data(data);
	data->map_data.map = read_map(av);
	/* while (data->map_data.map[x])
	{
		printf("%s\n", data->map_data.map[x]);
		x++;
	}  */
	is_map_rectangle(data);
	check_walls_and_char(data);
	is_path_valid(av, data);
}
