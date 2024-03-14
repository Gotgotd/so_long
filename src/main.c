/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:09 by gautier           #+#    #+#             */
/*   Updated: 2024/03/14 14:30:15 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

int	check_file_extension(char *av, t_data *data)
{
	int		i;
	int		j;
	char	*ext;

	i = ft_strlen(av) - 1;
	j = 3;
	ext = ".ber";
	while (av[i] != '.')
	{
		if (av[i] != ext[j])
			ft_error_2(data, 3);
		i--;
		j--;
	}
	return (0);
} 

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error_1(&data, 1);
	check_file_extension(av[1], &data);
	map_parsing(av, &data);
	display_map(&data);
	mlx_key_hook(data.mlx_win, handle_events, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_window, &data);
	mlx_loop(data.mlx);
}
