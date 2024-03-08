/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:09 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 10:22:49 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"


int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(1);
	map_parsing(av, &data);
	display_map(&data);
	mlx_key_hook(data.mlx_win, handle_events, &data);
	mlx_hook(data.mlx_win, 17, 1L<<0, close_window, &data);
	mlx_loop(data.mlx);
}
