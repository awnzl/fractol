/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:29:57 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 18:52:30 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mn1pix(double px, double py, t_win *win)
{
	int		iter;
	t_frtl	z;
	t_frtl	t;
	double	a[3];

	iter = -1;
	a[2] = 1;
	z.real = px / win->width * (win->par->kx * 2) +
		win->par->centx - win->par->kx;
	z.imag = py / win->height * (win->par->ky * 2) +
		win->par->centy - win->par->ky;
	while (a[2] > 0.000001 && ++iter < win->par->depth)
	{
		t.real = z.real;
		t.imag = z.imag;
		a[0] = z.real * z.real;
		a[1] = z.imag * z.imag;
		a[2] = (a[0] + a[1]) * (a[0] + a[1]) * (z.real * z.imag);
		z.real = (2 * z.real * a[2] + a[0] - a[1]) / (3.0 * a[2]);
		z.imag = (2 * z.imag * (a[2] - t.real)) / (3.0 * a[2]);
		a[2] = (z.real - t.real) * (z.real - t.real) + (z.imag - t.imag) *
			(z.imag - t.imag);
	}
	win->imdat[(int)(px + py * win->width)] = (iter == win->par->depth) ?
		0 : get_col(ci(z, iter), win);
}

void	mn1_fractal(int i)
{
	t_win	win;

	win.par = &win.pars[i];
	init_par(&win);
	wininit(&win);
	win.func = &mn1pix;
	put_image(&win);
	mlx_loop(win.mlx);
}
