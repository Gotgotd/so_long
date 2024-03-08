/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:09:25 by gautier           #+#    #+#             */
/*   Updated: 2024/03/04 16:36:05 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error(int flag)
{
	if (flag == 1)
	{
		perror("Argument invalid. Please provide a single .ber file");
		exit(1);
	}
	if (flag == 2)
	{
		perror("error\nMap must be surrounded by walls");
		exit (1);
	}
	if (flag == 3)
	{
		perror("error\nMap must contain only '1', '0', 'C', 'E' or 'P' characters");
		exit (1);
	}
	if (flag == 4)
	{
		perror("error\nExit and all collectibles must be reachable in the map");
		exit (1);
	}

}

void	ft_error_count(int flag)
{
	if (flag == 0)
	{
		perror("error\nmap must contain at least 1 collectible 'C'");
		exit (1);
	}
	if (flag == 1)
	{
		perror("error\nmap must contain strictly 1 exit 'E'");
		exit(1);
	}
	if (flag == 2)
	{
		perror("error\nmap must contain strictly 1 start position 'P'");
		exit (1);
	}
}