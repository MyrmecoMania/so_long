/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:36:54 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 11:56:01 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_imgs2(t_vars vars, t_imgs *imgs)
{
	int		size;

	imgs->bad3 = mlx_xpm_file_to_image(vars.mlx, "textures/bad3.xpm", &size,
			&size);
	imgs->bad4 = mlx_xpm_file_to_image(vars.mlx, "textures/bad4.xpm", &size,
			&size);
	imgs->bad5 = mlx_xpm_file_to_image(vars.mlx, "textures/bad5.xpm", &size,
			&size);
	imgs->bad6 = mlx_xpm_file_to_image(vars.mlx, "textures/bad6.xpm", &size,
			&size);
	imgs->bad7 = mlx_xpm_file_to_image(vars.mlx, "textures/bad7.xpm", &size,
			&size);
	imgs->bad8 = mlx_xpm_file_to_image(vars.mlx, "textures/bad8.xpm", &size,
			&size);
	imgs->bad9 = mlx_xpm_file_to_image(vars.mlx, "textures/bad9.xpm", &size,
			&size);
	imgs->bad10 = mlx_xpm_file_to_image(vars.mlx, "textures/bad10.xpm", &size,
			&size);
	imgs->bad11 = mlx_xpm_file_to_image(vars.mlx, "textures/bad11.xpm", &size,
			&size);
}

t_imgs	load_imgs(t_vars vars)
{
	t_imgs	imgs;
	int		size;

	imgs.floor = mlx_xpm_file_to_image(vars.mlx, "textures/floor.xpm", &size,
			&size);
	imgs.wall = mlx_xpm_file_to_image(vars.mlx, "textures/wall.xpm", &size,
			&size);
	imgs.front = mlx_xpm_file_to_image(vars.mlx, "textures/front.xpm", &size,
			&size);
	imgs.back = mlx_xpm_file_to_image(vars.mlx, "textures/back.xpm", &size,
			&size);
	imgs.right = mlx_xpm_file_to_image(vars.mlx, "textures/right.xpm", &size,
			&size);
	imgs.left = mlx_xpm_file_to_image(vars.mlx, "textures/left.xpm", &size,
			&size);
	imgs.item = mlx_xpm_file_to_image(vars.mlx, "textures/item.xpm", &size,
			&size);
	imgs.exit = mlx_xpm_file_to_image(vars.mlx, "textures/exit.xpm", &size,
			&size);
	imgs.bad1 = mlx_xpm_file_to_image(vars.mlx, "textures/bad1.xpm", &size,
			&size);
	imgs.bad2 = mlx_xpm_file_to_image(vars.mlx, "textures/bad2.xpm", &size,
			&size);
	load_imgs2(vars, &imgs);
	return (imgs);
}

void	ft_choose_img(t_vars *vars, char c, int x, int y)
{
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.item, x, y);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.front, x, y);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.wall, x, y);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.floor, x, y);
	if (c == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->imgs.bad1, x, y);
}

void	render_map(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (vars->map[i])
	{
		j = 0;
		x = 0;
		while (vars->map[i][j])
		{
			ft_choose_img(vars, vars->map[i][j], x, y);
			x += 64;
			j++;
		}
		i++;
		y += 64;
	}
}

int	ft_check_imgs(t_imgs imgs)
{
	if (!imgs.floor || !imgs.wall || !imgs.front || !imgs.back || !imgs.right
		|| !imgs.left || !imgs.item || !imgs.exit || !imgs.bad1 || !imgs.bad2
		|| !imgs.bad3 || !imgs.bad4 || !imgs.bad5 || !imgs.bad6 || !imgs.bad7
		|| !imgs.bad8 || !imgs.bad9 || !imgs.bad10 || !imgs.bad11)
		return (1);
	return (0);
}
