/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:20 by gautier           #+#    #+#             */
/*   Updated: 2024/03/13 14:31:34 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SO_LONG_H
# define	SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"

# define SHEET_HEIGTH 64
# define SHEET_WIDTH 64


typedef struct s_sheets
{
	int		width;
	int		heigth;
	void	*wall;
	void	*ground;
	void	*knight_down;
	void	*knight_up;
	void	*knight_right;
	void	*knight_left;
	void	*knight_up_portal;
	void	*knight_down_portal;
	void	*knight_left_portal;
	void	*knight_right_portal;
	void	*portal_closed;
	void	*portal_opened;
	void	*demon_eye;
	void	*win_sheet;
	void	*knight_win;
}	t_sheets;


typedef struct	s_indexes
{
	int	x;
	int	y;
}	t_indexes;

typedef struct	s_map_data
{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				C_count;
	int				E_count;
	int				P_count;
	int				C_collected;
	int				width;
	int				heigth;
	t_indexes		P_indexes;
	t_indexes		E_indexes;
}	t_map_data;

typedef struct	s_data 
{
	void	*mlx;
	void	*mlx_win;
	t_map_data	map_data;
	t_sheets	sheets;
}	t_data; 

/* PARSING 1 */
void	map_parsing(char **av, t_data *data);
char	**read_map(char **av);
void	is_map_rectangle(t_data *data);
void	check_walls_and_char(t_data *data);

/* PARSING 2 */
void	check_counts(t_data *data);
void	init_player_and_exit_pos(t_data data);
void	flood_map(char **map, t_indexes indexes);
int		check_path(char **map);
void	is_path_valid(char **av, t_data *data);

/* ERROR */
void	ft_error(t_data *data, int flag);
void	ft_error_count(t_data *data, int flag);

/* GNL */
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char *s2);

/* DISPLAY MAP */
void	display_map(t_data *data);
void	put_sheets_to_map(t_data *data);
void	set_sheets(t_data *data);

/* HANDLE EVENTS 1 */
int		close_window(t_data *data);
int		handle_events(int keycode, t_data *data);

/* HANDLE EVENTS 2 */
void	game_success(t_data *data);

/* INIT STRUCTURE */
void	init_map_data(t_data *data);

/* FT_FREE */
int		close_window(t_data *data);
void	free_tab(char **tab);

#endif