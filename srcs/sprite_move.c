/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:19:12 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 12:13:56 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_bad_down(t_vars *vars, int y, int x)
{
	if (vars->map[y + 1][x] == 'P')
	{
		ft_putstr_fd("Game over\nThe monster killed you\n", 1);
		mlx_loop_end(vars->mlx);
	}
	vars->map[y + 1][x] = 'M';
	vars->map[y][x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor,
		x * 64, y * 64);
}

void	ft_move_bad_up(t_vars *vars, int y, int x)
{
	if (vars->map[y - 1][x] == 'P')
	{
		ft_putstr_fd("Game over\nThe monster killed you\n", 1);
		mlx_loop_end(vars->mlx);
	}
	vars->map[y - 1][x] = 'M';
	vars->map[y][x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor,
		x * 64, y * 64);
}

void	ft_move_bad_left(t_vars *vars, int y, int x)
{
	if (vars->map[y][x - 1] == 'P')
	{
		ft_putstr_fd("Game over\nThe monster killed you\n", 1);
		mlx_loop_end(vars->mlx);
	}
	vars->map[y][x - 1] = 'M';
	vars->map[y][x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor,
		x * 64, y * 64);
}

void	ft_move_bad_right(t_vars *vars, int y, int x)
{
	if (vars->map[y][x + 1] == 'P')
	{
		ft_putstr_fd("Game over\nThe monster killed you\n", 1);
		mlx_loop_end(vars->mlx);
	}
	vars->map[y][x + 1] = 'M';
	vars->map[y][x] = '0';
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor,
		x * 64, y * 64);
}

int	init_vars(char **argv, t_vars *vars)
{
	vars->map = get_map(argv[1]);
	if (!vars->map)
		return (ft_puterror("Wrong map"));
	if ((ft_strlen(vars->map[0]) - 1) * 64 > 1920
		|| ft_gethigh(vars->map) * 64 > 1080)
		return (ft_free_map(vars->map, 0),
			ft_puterror("Map too big for this screen"));
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_free_map(vars->map, 0), ft_puterror("Can't initialise mlx"));
	vars->win = mlx_new_window(vars->mlx, ((ft_strlen(vars->map[0]) - 1) * 64),
			ft_gethigh(vars->map) * 64, "SOOOOOOOOOOOOO_LOOOOOONG");
	if (!vars->win)
		return (ft_free_map(vars->map, 0), ft_puterror("Can't open window"));
	return (0);
}
