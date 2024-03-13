/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:33:40 by gautier           #+#    #+#             */
/*   Updated: 2024/03/13 14:31:34 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//free the data and exit the program.
void	quit_game (t_data *data)
{
	free_tab(data->map_data.map);
	exit (0);
}


//close the window when you clcik on the cross
int	close_window(t_data *data)
{
	free_tab(data->map_data.map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

//when the knight has collected all the demon eyes and reach the opened portal
//the function display a win message, the knight_win sheet, wait 6sec
//and exit the program
void	game_success(t_data *data)
{ 
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.win_sheet, (data->map_data.width / 8 ), (data->map_data.heigth / 8));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->sheets.knight_win, data->map_data.P_indexes.y * SHEET_WIDTH, data->map_data.P_indexes.x * SHEET_HEIGTH);
	mlx_do_sync(data->mlx);
	usleep(6000000);
	quit_game(data);
}

