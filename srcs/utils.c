/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:48:09 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 12:09:56 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_coor	get_coor(char **map, char c, int x, int y)
{
	t_coor	r;

	r.x = x;
	r.y = y;
	while (map[r.y])
	{
		r.x = 0;
		while (map[r.y][r.x])
		{
			if (map[r.y][r.x] == c)
				return (r);
			r.x += 1;
		}
		r.y += 1;
	}
	if (map[r.y - 1][r.x - 1] != c)
	{
		r.x = 0;
		r.y = 0;
	}
	return (r);
}

int	ft_isexit(char **map, int y, int x)
{
	t_coor	t;

	if (map[y][x] == 'M')
		return (1);
	if (map[y][x] == 'E')
	{
		t = get_coor(map, 'C', 0, 0);
		if (t.x == 0 && t.y == 0)
			return (1);
		return (2);
	}
	return (0);
}

int	end(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

int	ft_gethigh(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	ft_write(t_vars *vars)
{
	char	*t;

	t = ft_itoa(vars->moves);
	ft_putstr_fd("MOVES: ", 1);
	ft_putnbr_fd(vars->moves, 1);
	ft_putstr_fd("\n", 1);
	mlx_string_put(vars->mlx, vars->win, (ft_strlen(vars->map[0]) * 64) / 4, 32,
		16777215, t);
	free(t);
}
