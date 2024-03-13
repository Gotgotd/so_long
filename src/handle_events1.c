/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:16:24 by gautier           #+#    #+#             */
/*   Updated: 2024/03/12 14:28:18 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//make the character move one tile right on the map
//handle all type of tiles the character can be on (portal, collectibles etc.)
//- check first if the next tile is a wall.  
//If so, just make the character face right direction
//- replace the current tile by a empty ground sheet or portal sheet
//- replace the next tile by a sheet with the character facing right direction on it
void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.P_indexes.x;
	y = data->map_data.P_indexes.y;
	if (data->map_data.map[x][y + 1] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_right, y * SHEET_WIDTH, x * SHEET_HEIGTH);
	else
	{
		if (data->map_data.map[x][y + 1] == 'C')
			data->map_data.C_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_closed, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
		{
			data->map_data.map[x][y] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		}
		data->map_data.P_indexes.y = y + 1;
		if (data->map_data.map[x][y + 1] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_right_portal, (y + 1) * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_right, (y + 1) * SHEET_WIDTH, x * SHEET_HEIGTH);
	}
}

//same as previous for moving one tile left
void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.P_indexes.x;
	y = data->map_data.P_indexes.y;
	if (data->map_data.map[x][y - 1] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_left, y * SHEET_WIDTH, x * SHEET_HEIGTH);
	else
	{
		if (data->map_data.map[x][y - 1] == 'C')
			data->map_data.C_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_closed, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
		{
			data->map_data.map[x][y] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		}
		data->map_data.P_indexes.y = y - 1;
		if (data->map_data.map[x][y - 1] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_left_portal, (y - 1) * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_left, (y - 1) * SHEET_WIDTH, x * SHEET_HEIGTH);
	}
}

//same as previous for moving one tile up
void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.P_indexes.x;
	y = data->map_data.P_indexes.y;
	if (data->map_data.map[x - 1][y] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_up, y * SHEET_WIDTH, x * SHEET_HEIGTH);
	else
	{
		if (data->map_data.map[x - 1][y] == 'C')
			data->map_data.C_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_closed, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
		{
			data->map_data.map[x][y] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		}
		data->map_data.P_indexes.x = x - 1;
		if (data->map_data.map[x - 1][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_up_portal, y * SHEET_WIDTH, (x - 1) * SHEET_HEIGTH);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_up, y * SHEET_WIDTH, (x - 1) * SHEET_HEIGTH);
	}
}

//same as previous for moving one tile down
void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.P_indexes.x;
	y = data->map_data.P_indexes.y;
	if (data->map_data.map[x + 1][y] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_down, y * SHEET_WIDTH, x * SHEET_HEIGTH);
	else
	{
		if (data->map_data.map[x + 1][y] == 'C')
			data->map_data.C_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_closed, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		else
		{
			data->map_data.map[x][y] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.ground, y * SHEET_WIDTH, x * SHEET_HEIGTH);
		}
		data->map_data.P_indexes.x = x + 1;
		if (data->map_data.map[x + 1][y] == 'E')
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_down_portal, y * SHEET_WIDTH, (x + 1) * SHEET_HEIGTH);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_down, y * SHEET_WIDTH, (x + 1) * SHEET_HEIGTH);
	}
}

//function that trigger the right function so the character can move, regarding which key is pressed 
//on the keyboard (W, A, S, D and arrow keys ; Esc)
//Also check if all collectible have been collected and open the exit if so to finish the game
int	handle_events(int keycode, t_data *data)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit(0);
    }
	else if (keycode == 119 || keycode == 65362)
		move_up(data);
	else if (keycode == 115 || keycode == 65364)
		move_down(data);
	else if (keycode == 97 || keycode == 65361)
		move_left(data);
	else if (keycode == 100 || keycode == 65363)
		move_right(data);
	if (data->map_data.C_collected == data->map_data.C_count && data->map_data.P_indexes.x == data->map_data.E_indexes.x 
		&& data->map_data.P_indexes.y == data->map_data.E_indexes.y)
		game_success(data);
	else if (data->map_data.C_collected == data->map_data.C_count)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.portal_opened, data->map_data.E_indexes.y * SHEET_WIDTH, data->map_data.E_indexes.x * SHEET_HEIGTH);
    return (0);
}
