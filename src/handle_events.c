/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:16:24 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 17:22:10 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.P_indexes.x;
	y = data->map_data.P_indexes.y;
	if (data->map_data.map[x - 1][y] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_up, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		printf("ici");
	}
	else
	{
		data->map_data.map[x][y] = '0';
		if (data->map_data.map[x - 1][y] == 'C')
			data->map_data.C_collected += 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		data->map_data.P_indexes.x = x - 1;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_up, y * SHEET_WIDTH, (x - 1) * SHEET_HEIGTH);
	}
}

int	handle_events(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
	else if (keycode == 119 || keycode == 65362)
		move_up(data);
    return (0);
}