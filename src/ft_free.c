/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:10:08 by gautier           #+#    #+#             */
/*   Updated: 2024/03/20 16:17:32 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//free any double tab sent
void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

//free all the images initialized at the beginning of the program
void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.pl_down);
	mlx_destroy_image(data->mlx, data->img.pl_down_p);
	mlx_destroy_image(data->mlx, data->img.pl_left);
	mlx_destroy_image(data->mlx, data->img.pl_left_p);
	mlx_destroy_image(data->mlx, data->img.pl_right);
	mlx_destroy_image(data->mlx, data->img.pl_right_p);
	mlx_destroy_image(data->mlx, data->img.pl_up);
	mlx_destroy_image(data->mlx, data->img.pl_up_p);
	mlx_destroy_image(data->mlx, data->img.pl_win);
	mlx_destroy_image(data->mlx, data->img.portal_clsd);
	mlx_destroy_image(data->mlx, data->img.portal_opnd);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.win_img);
	mlx_destroy_image(data->mlx, data->img.demon_eye);
}

//free the data and exit the program.
void	quit_game(t_data *data)
{
	destroy_img(data);
	free_tab(data->map_data.map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}
