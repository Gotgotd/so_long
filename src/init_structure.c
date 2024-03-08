/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:15:44 by gautier           #+#    #+#             */
/*   Updated: 2024/03/08 15:20:09 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_data(t_data *data)
{
	data->map_data.C_collected = 0;
	data->map_data.C_count = 0;
	data->map_data.E_count = 0;
	data->map_data.heigth = 0;
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.P_count = 0;
	data->map_data.width = 0;
}