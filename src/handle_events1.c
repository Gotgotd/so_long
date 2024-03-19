/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:16:24 by gautier           #+#    #+#             */
/*   Updated: 2024/03/19 17:32:40 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//make the character move one tile right on the map
//handle all type of tiles the character can be on (portal, collectibles etc.)
//- check first if the next tile is a wall.  
//If so, just make the character face right direction
//- replace the current tile by a empty ground sheet or portal sheet
//- replace the next tile by a sheet with the character 
//facing right direction on it
void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.p_pos.x;
	y = data->map_data.p_pos.y;
	if (data->map_data.map[x][y + 1] == '1')
		display_img(data, data->img.pl_right, y, x);
	else
	{
		if (data->map_data.map[x][y + 1] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.portal_clsd, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.y = y + 1;
		if (data->map_data.map[x][y + 1] == 'E')
			display_img(data, data->img.pl_right_p, (y + 1), x);
		else
			display_img(data, data->img.pl_right, (y + 1), x);
		data->nb_moves++;
	}
}

//same as previous for moving one tile left
void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.p_pos.x;
	y = data->map_data.p_pos.y;
	if (data->map_data.map[x][y - 1] == '1')
		display_img(data, data->img.pl_left, y, x);
	else
	{
		if (data->map_data.map[x][y - 1] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.portal_clsd, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.y = y - 1;
		if (data->map_data.map[x][y - 1] == 'E')
			display_img(data, data->img.pl_left_p, (y - 1), x);
		else
			display_img(data, data->img.pl_left, (y - 1), x);
		data->nb_moves++;
	}
}

//same as previous for moving one tile up
void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.p_pos.x;
	y = data->map_data.p_pos.y;
	if (data->map_data.map[x - 1][y] == '1')
		display_img(data, data->img.pl_up, y, x);
	else
	{
		if (data->map_data.map[x - 1][y] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.portal_clsd, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.x = x - 1;
		if (data->map_data.map[x - 1][y] == 'E')
			display_img(data, data->img.ground, y, (x - 1));
		else
			display_img(data, data->img.pl_up, y, (x - 1));
		data->nb_moves++;
	}
}

//same as previous for moving one tile down
void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->map_data.p_pos.x;
	y = data->map_data.p_pos.y;
	if (data->map_data.map[x + 1][y] == '1')
		display_img(data, data->img.pl_down, y, x);
	else
	{
		if (data->map_data.map[x + 1][y] == 'C')
			data->map_data.c_collected += 1;
		if (data->map_data.map[x][y] == 'E')
			display_img(data, data->img.portal_clsd, y, x);
		else
		{
			data->map_data.map[x][y] = '0';
			display_img(data, data->img.ground, y, x);
		}
		data->map_data.p_pos.x = x + 1;
		if (data->map_data.map[x + 1][y] == 'E')
			display_img(data, data->img.pl_down_p, y, (x + 1));
		else
			display_img(data, data->img.pl_down, y, (x + 1));
	}
}

//function that trigger the right function so the character can move, 
//regarding which key is pressed on the keyboard 
//(W, A, S, D and arrow keys, esc); 
//Also check if all collectible have been collected and 
//open the exit if so to finish the game
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
	if (data->map_data.c_collected == data->map_data.c_count
		&& data->map_data.p_pos.x == data->map_data.e_pos.x
		&& data->map_data.p_pos.y == data->map_data.e_pos.y)
		game_success(data);
	else if (data->map_data.c_collected == data->map_data.c_count)
		display_img(data, data->img.portal_opnd, data->map_data.e_pos.y,
			data->map_data.e_pos.x);
	display_black_rectangle(data);
	display_nb_moves(data);
	return (0);
}
