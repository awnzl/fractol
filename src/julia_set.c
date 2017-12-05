/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:29:57 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/15 20:22:09 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	jspix(double px, double py, t_win *win)
{
	int		iter;
	t_frtl	z;
	double	r2;
	double	i2;

	iter = -1;
	z.cx = win->par->real;
	z.cy = win->par->nreal;
	z.real = px / win->width * (win->par->kx * 2) +
		win->par->centx - win->par->kx;
	z.imag = py / win->height * (win->par->ky * 2) +
		win->par->centy - win->par->ky;
	while (((r2 = z.real * z.real) +
			(i2 = z.imag * z.imag)) <= 4 && ++iter < win->par->depth)
	{
		z.imag = 2 * z.real * z.imag + z.cy;
		z.real = r2 - i2 + z.cx;
	}
	win->imdat[(int)(px + py * win->width)] = (iter == win->par->depth) ?
		0 : get_col(ci(z, iter), win);
}

void	julia_set(int i)
{
	t_win	win;

	win.par = &win.pars[i];
	init_par(&win);
	wininit(&win);
	win.func = &jspix;
	put_image(&win);
	mlx_loop(win.mlx);
}
