/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:12:57 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 12:16:07 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_vars *vars, t_coor p)
{
	int	e;

	if (vars->map[p.y - 1][p.x] != '1')
	{
		e = ft_isexit(vars->map, p.y - 1, p.x);
		if (e == 1)
			mlx_loop_end(vars->mlx);
		if (e == 2)
		{
			ft_putstr_fd("Cannot exit, still collectibles on the map!\n", 1);
			return ;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall,
			ft_strlen(vars->map[0]) / 4 * 64, 0);
		vars->map[p.y][p.x] = '0';
		vars->map[p.y - 1][p.x] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor, p.x
			* 64, p.y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.back, p.x * 64,
			(p.y - 1) * 64);
		vars->moves += 1;
		ft_write(vars);
	}
}

void	ft_move_down(t_vars *vars, t_coor p)
{
	int	e;

	if (vars->map[p.y + 1][p.x] != '1')
	{
		e = ft_isexit(vars->map, p.y + 1, p.x);
		if (e == 1)
			mlx_loop_end(vars->mlx);
		if (e == 2)
		{
			ft_putstr_fd("Cannot exit, still collectibles on the map!\n", 1);
			return ;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall,
			ft_strlen(vars->map[0]) / 4 * 64, 0);
		vars->map[p.y][p.x] = '0';
		vars->map[p.y + 1][p.x] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor, p.x
			* 64, p.y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.front, p.x
			* 64, (p.y + 1) * 64);
		vars->moves += 1;
		ft_write(vars);
	}
}

void	ft_move_left(t_vars *vars, t_coor p)
{
	int	e;

	if (vars->map[p.y][p.x - 1] != '1')
	{
		e = ft_isexit(vars->map, p.y, p.x - 1);
		if (e == 1)
			mlx_loop_end(vars->mlx);
		if (e == 2)
		{
			ft_putstr_fd("Cannot exit, still collectibles on the map!\n", 1);
			return ;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall,
			ft_strlen(vars->map[0]) / 4 * 64, 0);
		vars->map[p.y][p.x] = '0';
		vars->map[p.y][p.x - 1] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor, p.x
			* 64, p.y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.left, (p.x - 1)
			* 64, p.y * 64);
		vars->moves += 1;
		ft_write(vars);
	}
}

void	ft_move_right(t_vars *vars, t_coor p)
{
	int	e;

	if (vars->map[p.y][p.x + 1] != '1')
	{
		e = ft_isexit(vars->map, p.y, p.x + 1);
		if (e == 1)
			mlx_loop_end(vars->mlx);
		if (e == 2)
		{
			ft_putstr_fd("Cannot exit, still collectibles on the map!\n", 1);
			return ;
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall,
			ft_strlen(vars->map[0]) / 4 * 64, 0);
		vars->map[p.y][p.x] = '0';
		vars->map[p.y][p.x + 1] = 'P';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor, p.x
			* 64, p.y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.right, (p.x
				+ 1) * 64, p.y * 64);
		vars->moves += 1;
		ft_write(vars);
	}
}
