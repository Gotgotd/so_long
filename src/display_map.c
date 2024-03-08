/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:02:44 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 11:59:01 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_sheets(t_data *data)
{
	data->sheets.width = SHEET_WIDTH;
	data->sheets.heigth = SHEET_HEIGTH;
	data->sheets.ground = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/ground.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.wall = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/wall.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.demon_eye = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/demon_eye.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.knight_down = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/knight_down.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.knight_up = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/knight_up.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.knight_left = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/knight_left.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.knight_right = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/knight_right.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.portal_closed = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/portal_closed.xpm", &(data->sheets.width), &(data->sheets.heigth));
	data->sheets.portal_opened = mlx_xpm_file_to_image(data->mlx, "./assets/sheets/portal_opened.xpm", &(data->sheets.width), &(data->sheets.heigth));
}

void	put_sheets_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while(data->map_data.map[x])
	{
		y = 0;
		while(data->map_data.map[x][y])
		{
			if (data->map_data.map[x][y] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.wall, y * SHEET_WIDTH, x * SHEET_HEIGTH);
			if (data->map_data.map[x][y] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
			if (data->map_data.map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.demon_eye, y * SHEET_WIDTH, x * SHEET_HEIGTH);
			if (data->map_data.map[x][y] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_down, y * SHEET_WIDTH, x * SHEET_HEIGTH);
			if (data->map_data.map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_closed, y * SHEET_WIDTH, x * SHEET_HEIGTH);
			y++;
		}
		x++;
	}
}

void	display_map(t_data *data)
{
	data->map_data.heigth = data->map_data.nb_row * SHEET_HEIGTH;
	data->map_data.width = data->map_data.nb_column * SHEET_WIDTH;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	set_sheets(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_data.width, data->map_data.heigth, "so_long");
	if (!data->mlx_win)
	{
		free(data->mlx);
		return ;
	}
	put_sheets_to_map(data);
} 