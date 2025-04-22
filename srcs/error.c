/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:20:29 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 11:54:48 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_free_map(char **map, int fd)
{
	int	i;

	i = 0;
	if (fd)
		close(fd);
	if (map)
	{
		while (map[i])
			free(map[i++]);
		free(map);
	}
	return (NULL);
}

int	ft_puterror(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_finish(t_vars vars)
{
	ft_free_imgs(vars);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	ft_free_map(vars.map, 0);
	free(vars.mlx);
}

void	ft_free_imgs2(t_vars vars)
{
	if (vars.imgs.bad4)
		mlx_destroy_image(vars.mlx, vars.imgs.bad4);
	if (vars.imgs.bad5)
		mlx_destroy_image(vars.mlx, vars.imgs.bad5);
	if (vars.imgs.bad6)
		mlx_destroy_image(vars.mlx, vars.imgs.bad6);
	if (vars.imgs.bad7)
		mlx_destroy_image(vars.mlx, vars.imgs.bad7);
	if (vars.imgs.bad8)
		mlx_destroy_image(vars.mlx, vars.imgs.bad8);
	if (vars.imgs.bad9)
		mlx_destroy_image(vars.mlx, vars.imgs.bad9);
	if (vars.imgs.bad10)
		mlx_destroy_image(vars.mlx, vars.imgs.bad10);
	if (vars.imgs.bad11)
		mlx_destroy_image(vars.mlx, vars.imgs.bad11);
}

void	ft_free_imgs(t_vars vars)
{
	if (vars.imgs.wall)
		mlx_destroy_image(vars.mlx, vars.imgs.wall);
	if (vars.imgs.floor)
		mlx_destroy_image(vars.mlx, vars.imgs.floor);
	if (vars.imgs.item)
		mlx_destroy_image(vars.mlx, vars.imgs.item);
	if (vars.imgs.front)
		mlx_destroy_image(vars.mlx, vars.imgs.front);
	if (vars.imgs.exit)
		mlx_destroy_image(vars.mlx, vars.imgs.exit);
	if (vars.imgs.back)
		mlx_destroy_image(vars.mlx, vars.imgs.back);
	if (vars.imgs.left)
		mlx_destroy_image(vars.mlx, vars.imgs.left);
	if (vars.imgs.right)
		mlx_destroy_image(vars.mlx, vars.imgs.right);
	if (vars.imgs.bad1)
		mlx_destroy_image(vars.mlx, vars.imgs.bad1);
	if (vars.imgs.bad2)
		mlx_destroy_image(vars.mlx, vars.imgs.bad2);
	if (vars.imgs.bad3)
		mlx_destroy_image(vars.mlx, vars.imgs.bad3);
	ft_free_imgs2(vars);
}
