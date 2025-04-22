/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enorie <enorie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:50:08 by enorie            #+#    #+#             */
/*   Updated: 2024/01/17 12:15:32 by enorie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_bad(t_vars *vars, int y, int x)
{
	int	r;

	r = rand() % 1000;
	if (r < 250 && (vars->map[y + 1][x] == '0' || vars->map[y + 1][x] == 'P'))
		ft_move_bad_down(vars, y, x);
	if (r < 500 && (vars->map[y][x + 1] == '0' || vars->map[y][x + 1] == 'P')
		&& vars->map[y][x] == 'M')
		ft_move_bad_right(vars, y, x);
	if (r < 750 && (vars->map[y - 1][x] == '0' || vars->map[y - 1][x] == 'P')
		&& vars->map[y][x] == 'M')
		ft_move_bad_up(vars, y, x);
	if (r < 1000 && (vars->map[y][x - 1] == '0' || vars->map[y][x - 1] == 'P')
		&& vars->map[y][x] == 'M')
		ft_move_bad_left(vars, y, x);
}

int	move(int keycode, t_vars *vars)
{
	t_coor	p;

	p = get_coor(vars->map, 'P', 0, 0);
	if (keycode == 's')
		ft_move_down(vars, p);
	if (keycode == 'a')
		ft_move_left(vars, p);
	if (keycode == 'w')
		ft_move_up(vars, p);
	if (keycode == 'd')
		ft_move_right(vars, p);
	if (keycode == 65307)
		mlx_loop_end(vars->mlx);
	return (0);
}

int	ft_put_img(t_vars *vars, void *img)
{
	int	i[2];

	i[0] = 0;
	while (vars->map[i[0]])
	{
		i[1] = 0;
		while (vars->map[i[0]][i[1]])
		{
			if (vars->map[i[0]][i[1]] == 'M')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, img,
					i[1] * 64, i[0] * 64);
				if (rand() % 11 == 1)
					ft_move_bad(vars, i[0], i[1]);
			}
			i[1]++;
		}
		i[0]++;
	}
	if (vars->stage == 55000)
		vars->stage = 0;
	return (0);
}

int	sprites(t_vars *vars)
{
	vars->stage += 1;
	if (vars->stage == 5000)
		return (ft_put_img(vars, vars->imgs.bad1));
	if (vars->stage == 10000)
		return (ft_put_img(vars, vars->imgs.bad2));
	if (vars->stage == 15000)
		return (ft_put_img(vars, vars->imgs.bad3));
	if (vars->stage == 20000)
		return (ft_put_img(vars, vars->imgs.bad4));
	if (vars->stage == 25000)
		return (ft_put_img(vars, vars->imgs.bad5));
	if (vars->stage == 30000)
		return (ft_put_img(vars, vars->imgs.bad6));
	if (vars->stage == 35000)
		return (ft_put_img(vars, vars->imgs.bad7));
	if (vars->stage == 40000)
		return (ft_put_img(vars, vars->imgs.bad8));
	if (vars->stage == 45000)
		return (ft_put_img(vars, vars->imgs.bad9));
	if (vars->stage == 50000)
		return (ft_put_img(vars, vars->imgs.bad10));
	if (vars->stage == 55000)
		return (ft_put_img(vars, vars->imgs.bad11));
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		return (ft_puterror("./so_long filepath"));
	vars.moves = 0;
	vars.stage = 0;
	if (init_vars(argv, &vars))
		return (1);
	mlx_hook(vars.win, 2, 1L << 0, move, &vars);
	mlx_hook(vars.win, 17, 0, end, &vars);
	vars.imgs = load_imgs(vars);
	if (ft_check_imgs(vars.imgs))
		return (ft_finish(vars),
			ft_puterror("Texture missing"));
	render_map(&vars);
	mlx_string_put(vars.mlx, vars.win, (ft_strlen(vars.map[0]) * 64) / 4, 32,
		16777215, "0");
	mlx_loop_hook(vars.mlx, sprites, &vars);
	mlx_loop(vars.mlx);
	ft_finish(vars);
	return (0);
}
