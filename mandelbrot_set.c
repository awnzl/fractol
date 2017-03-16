/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:29:29 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 18:46:53 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check_mndl(double q, t_frtl z)
{
	if ((q * (q + (z.cx - 0.25)) < (z.cy * z.cy) / 4) ||
			(z.cx * z.cx + 2 * z.cx + 1 + z.cy * z.cy < 0.0625))
		return (1);
	return (0);
}

void	mspix(double px, double py, t_win *w)
{
	int		iter;
	double	r2;
	double	i2;
	t_frtl	z;

	z.cx = px / w->width * (w->par->kx * 2) + w->par->centx - w->par->kx;
	z.cy = py / w->height * (w->par->ky * 2) + w->par->centy - w->par->ky;
	z.real = 0;
	z.imag = 0;
	iter = -1;
	if (check_mndl(((z.cx * z.cx - 0.5 * z.cx + 0.0625) + z.cy * z.cy), z))
		w->imdat[(int)(px + py * w->width)] = 0;
	else
	{
		while (((r2 = z.real * z.real) +
					(i2 = z.imag * z.imag)) <= 4 && ++iter < w->par->depth)
		{
			z.imag = 2 * z.real * z.imag + z.cy;
			z.real = r2 - i2 + z.cx;
		}
		w->imdat[(int)(px + py * w->width)] = (iter == w->par->depth) ? 0 :
			get_col(ci(z, iter), w);
	}
}

void	wininit(t_win *win)
{
	win->width = 1000;
	win->height = 800;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height,
			win->par->fr_name);
}

void	mandelbrot_set(int i)
{
	t_win	win;

	win.par = &win.pars[i];
	init_par(&win);
	wininit(&win);
	win.func = &mspix;
	put_image(&win);
	mlx_loop(win.mlx);
}
