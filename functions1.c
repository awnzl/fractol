/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:35:06 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 18:56:16 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_col(double n, t_win *w)
{
	union u_col	c;

	if (n == w->par->depth)
		return (0);
	c.c[0] = (sin(n * w->par->rfr + w->par->rph) * 127 + 128);
	c.c[1] = (sin(n * w->par->gfr + w->par->gph) * 127 + 128);
	c.c[2] = (sin(n * w->par->bfr + w->par->bph) * 127 + 128);
	c.c[3] = 0;
	return (c.col);
}

void	info_insert(t_win *w)
{
	mlx_string_put(w->mlx, w->win, 10, 5, 0xFFFFFF, "iterations: ");
	mlx_string_put(w->mlx, w->win, 130, 5, 0xFFFFFF, ft_itoa(w->par->depth));
}

double	ci(t_frtl z, double iter)
{
	return (iter + 1 - (log((log(sqrt(z.real * z.real +
								z.imag * z.imag)) / 2) / log(2)) / log(2)));
}

void	fractal(int i)
{
	void	(*f[6])(int);

	if (i > -1 && i < 6)
	{
		f[0] = &mandelbrot_set;
		f[1] = &julia_set;
		f[2] = &burning_ship_set;
		f[3] = &newton_fractal;
		f[4] = &mn1_fractal;
		f[5] = &mn2_fractal;
		f[i](i);
	}
}

void	forkit(int ac, char **av)
{
	pid_t	uid;

	if (ac > 0)
	{
		uid = fork();
		if (uid == 0)
			fractal(ft_atoi(av[ac - 1]));
		else
			forkit(ac - 1, av);
	}
}
