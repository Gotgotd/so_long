/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:15:44 by gautier           #+#    #+#             */
/*   Updated: 2024/03/19 16:28:30 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_data(t_data *data)
{
	data->map_data.c_collected = 0;
	data->map_data.c_count = 0;
	data->map_data.e_count = 0;
	data->map_data.heigth = 0;
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.p_count = 0;
	data->map_data.width = 0;
	data->nb_moves = 0;
}
