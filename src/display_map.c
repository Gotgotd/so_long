/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:02:44 by gautier           #+#    #+#             */
/*   Updated: 2024/03/19 16:29:43 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*convert_img(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &(data->img.size),
			&(data->img.size));
	return (img);
}

void	set_img(t_data *data)
{
	data->img.size = SIZE;
	data->img.ground = convert_img(data, "./assets/img/ground.xpm");
	data->img.wall = convert_img(data, "./assets/img/wall.xpm");
	data->img.demon_eye = convert_img(data, "./assets/img/demon_eye.xpm");
	data->img.pl_down = convert_img(data, "./assets/img/pl_down.xpm");
	data->img.pl_up = convert_img(data, "./assets/img/pl_up.xpm");
	data->img.pl_left = convert_img(data, "./assets/img/pl_left.xpm");
	data->img.pl_right = convert_img(data, "./assets/img/pl_right.xpm");
	data->img.portal_clsd = convert_img(data, "./assets/img/portal_clsd.xpm");
	data->img.portal_opnd = convert_img(data, "./assets/img/portal_opnd.xpm");
	data->img.pl_up_p = convert_img(data, "./assets/img/pl_up_p.xpm");
	data->img.pl_down_p = convert_img(data, "./assets/img/pl_down_p.xpm");
	data->img.pl_left_p = convert_img(data, "./assets/img/pl_left_p.xpm");
	data->img.pl_right_p = convert_img(data, "./assets/img/pl_right_p.xpm");
	data->img.pl_win = convert_img(data, "./assets/img/pl_win.xpm");
	data->img.win_img = convert_img(data, "./assets/img/win_img.xpm");
}

void	display_img(t_data *data, void *img, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img,
		y * SIZE, x * SIZE);
}

void	put_img_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			if (data->map_data.map[x][y] == '1')
				display_img(data, data->img.wall, y, x);
			if (data->map_data.map[x][y] == '0')
				display_img(data, data->img.ground, y, x);
			if (data->map_data.map[x][y] == 'C')
				display_img(data, data->img.demon_eye, y, x);
			if (data->map_data.map[x][y] == 'P')
				display_img(data, data->img.pl_down, y, x);
			if (data->map_data.map[x][y] == 'E')
				display_img(data, data->img.portal_clsd, y, x);
			y++;
		}
		x++;
	}
}

void	display_map(t_data *data)
{
	data->map_data.heigth = data->map_data.nb_row * SIZE;
	data->map_data.width = data->map_data.nb_column * SIZE;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	set_img(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_data.width,
			data->map_data.heigth, "so_long");
	if (!data->mlx_win)
	{
		free(data->mlx);
		return ;
	}
	put_img_to_map(data);
}
