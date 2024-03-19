/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdaignea <gdaignea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:31:20 by gautier           #+#    #+#             */
/*   Updated: 2024/03/19 16:29:43 by gdaignea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"

# define SIZE 64

typedef struct s_img
{
	int		size;
	void	*wall;
	void	*ground;
	void	*pl_down;
	void	*pl_up;
	void	*pl_right;
	void	*pl_left;
	void	*pl_up_p;
	void	*pl_down_p;
	void	*pl_left_p;
	void	*pl_right_p;
	void	*portal_clsd;
	void	*portal_opnd;
	void	*demon_eye;
	void	*win_img;
	void	*pl_win;
}	t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map_data
{
	char			**map;
	unsigned int	nb_column;
	unsigned int	nb_row;
	int				c_count;
	int				e_count;
	int				p_count;
	int				c_collected;
	int				width;
	int				heigth;
	t_pos			p_pos;
	t_pos			e_pos;
}	t_map_data;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			nb_moves;
	t_map_data	map_data;
	t_img		img;
}	t_data;

/* PARSING 1 */
void	map_parsing(char **av, t_data *data);
char	**read_map(char **av);
void	is_map_rectangle(t_data *data);
void	check_walls_and_char(t_data *data);

/* PARSING 2 */
void	check_counts(t_data *data);
void	init_player_and_exit_pos(t_data data);
void	flood_map(char **map, t_pos pos);
int		check_path(char **map);
void	is_path_valid(char **av, t_data *data);

/* ERROR */
void	ft_error_1(t_data *data, int flag);
void	ft_error_2(t_data *data, int flag);

/* GNL */
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char *s2);

/* DISPLAY MAP */
void	*convert_img(t_data *data, char *path);
void	display_img(t_data *data, void *img, int y, int x);
void	put_img_to_map(t_data *data);
void	display_map(t_data *data);
void	set_img(t_data *data);

/* HANDLE EVENTS 1 */
int		close_window(t_data *data);
int		handle_events(int keycode, t_data *data);

/* HANDLE EVENTS 2 */
void	game_success(t_data *data);
void	display_nb_moves(t_data *data);
void	display_black_rectangle(t_data *data);

/* INIT STRUCTURE */
void	init_map_data(t_data *data);

/* FT_FREE */
int		close_window(t_data *data);
void	free_tab(char **tab);

#endif