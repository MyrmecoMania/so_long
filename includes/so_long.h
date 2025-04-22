/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:58:51 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 14:24:45 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_coor
{
	int		x;
	int		y;
}			t_coor;

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*front;
	void	*right;
	void	*left;
	void	*back;
	void	*item;
	void	*exit;
	void	*bad1;
	void	*bad2;
	void	*bad3;
	void	*bad4;
	void	*bad5;
	void	*bad6;
	void	*bad7;
	void	*bad8;
	void	*bad9;
	void	*bad10;
	void	*bad11;
}			t_imgs;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	t_imgs	imgs;
	int		moves;
	int		stage;
}			t_vars;

char		**get_map(char *filepath);
char		**ft_free_map(char **map, int fd);
int			ft_puterror(char *str);
int			ft_gethigh(char **map);
t_coor		get_coor(char **map, char c, int x, int y);
void		ft_move_down(t_vars *vars, t_coor p);
void		ft_move_up(t_vars *vars, t_coor p);
void		ft_move_right(t_vars *vars, t_coor p);
void		ft_move_left(t_vars *vars, t_coor p);
int			ft_isexit(char **map, int y, int x);
t_imgs		load_imgs(t_vars vars);
void		render_map(t_vars *vars);
int			end(t_vars *vars);
int			ft_pathfinder(char **map);
int			ft_ok(char **map, char f, int y, int x);
void		ft_free_imgs(t_vars vars);
void		ft_finish(t_vars vars);
void		ft_move_bad_right(t_vars *vars, int y, int x);
void		ft_move_bad_left(t_vars *vars, int y, int x);
void		ft_move_bad_up(t_vars *vars, int y, int x);
void		ft_move_bad_down(t_vars *vars, int y, int x);
int			ft_check_imgs(t_imgs imgs);
int			init_vars(char **argv, t_vars *vars);
void		ft_wich_char(char **map, int y, int x);
void		ft_write(t_vars *vars);
void		ft_pathfinder_init(char **map, t_coor c);
int			ft_ispathcomplete(char **map, int y, int x);

#endif
