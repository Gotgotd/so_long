/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:33:40 by gautier           #+#    #+#             */
/*   Updated: 2024/03/19 16:28:06 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//free the data and exit the program.
void	quit_game(t_data *data)
{
	free_tab(data->map_data.map);
	exit (0);
}

void	display_black_rectangle(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 18)
	{
		x = 0;
		while (x < 120)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0);
			x++;
		}
		y++;
	}
}

void	display_nb_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->nb_moves);
	mlx_string_put(data->mlx, data->mlx_win, 20, 12, 0xFF0000, "MOVES :");
	mlx_string_put(data->mlx, data->mlx_win, 80, 12, 0xFF0000, moves);
	free(moves);
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
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.win_img,
		(data->map_data.width / 8), (data->map_data.heigth / 8));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.pl_win,
		data->map_data.p_pos.y * SIZE,
		data->map_data.p_pos.x * SIZE);
	mlx_do_sync(data->mlx);
	usleep(8000000);
	quit_game(data);
}
