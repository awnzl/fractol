/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:29:43 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/15 17:26:25 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bsspix(double px, double py, t_win *win)
{
	int		iter;
	double	r2;
	double	i2;
	t_frtl	z;

	z.cx = px / win->width * (win->par->kx * 2) +
		win->par->centx - win->par->kx;
	z.cy = py / win->height * (win->par->ky * 2) +
		win->par->centy - win->par->ky;
	z.real = 0;
	z.imag = 0;
	iter = -1;
	while (((r2 = z.real * z.real) +
				(i2 = z.imag * z.imag)) <= 4 && ++iter < win->par->depth)
	{
		z.imag = 2 * ABS(z.real) * ABS(z.imag) + z.cy;
		z.real = r2 - i2 + z.cx;
	}
	win->imdat[(int)(px + py * win->width)] = (iter == win->par->depth) ?
		0 : get_col(iter, win);
}

void	burning_ship_set(int i)
{
	t_win	win;

	win.par = &win.pars[i];
	init_par(&win);
	wininit(&win);
	win.func = &bsspix;
	put_image(&win);
	mlx_loop(win.mlx);
}
