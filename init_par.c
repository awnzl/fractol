/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:47:31 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 20:25:36 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mn1_fractal(t_win *w)
{
	w->pars[4].zoom = 1;
	w->pars[4].info = 1;
	w->pars[4].depth = 100;
	w->pars[4].real = 0;
	w->pars[4].nreal = 0;
	w->pars[4].julia = 0;
	w->pars[4].js_stop = 0;
	w->pars[4].rph = -0.4;
	w->pars[4].gph = 1.2;
	w->pars[4].bph = -0.2;
	w->pars[4].rfr = -0.15;
	w->pars[4].gfr = -0.05;
	w->pars[4].bfr = 0.1;
	w->pars[4].kx = 1.8;
	w->pars[4].ky = 1.44;
	w->pars[4].centx = 1.8 - w->pars[4].kx;
	w->pars[4].centy = 1.44 - w->pars[4].ky;
	w->pars[4].fr_name = "Newton Fractal";
	w->pars[5].zoom = 1;
	w->pars[5].info = 1;
	w->pars[5].depth = 100;
	w->pars[5].real = 0;
	w->pars[5].nreal = 0;
}

void	init_newton(t_win *w)
{
	w->pars[3].zoom = 1;
	w->pars[3].info = 1;
	w->pars[3].depth = 100;
	w->pars[3].real = 0;
	w->pars[3].nreal = 0;
	w->pars[3].julia = 0;
	w->pars[3].js_stop = 0;
	w->pars[3].rph = 12.6;
	w->pars[3].gph = 10.8;
	w->pars[3].bph = 4.8;
	w->pars[3].rfr = 0.05;
	w->pars[3].gfr = -0.15;
	w->pars[3].bfr = 0.15;
	w->pars[3].kx = 1.8;
	w->pars[3].ky = 1.44;
	w->pars[3].centx = 1.8 - w->pars[3].kx;
	w->pars[3].centy = 1.44 - w->pars[3].ky;
	w->pars[3].fr_name = "Newton Fractal";
	w->pars[5].julia = 0;
	w->pars[5].js_stop = 0;
	w->pars[5].rph = 5;
	w->pars[5].gph = -2.2;
	w->pars[5].bph = -5.8;
}

void	init_burningship_set(t_win *w)
{
	w->pars[2].zoom = 1;
	w->pars[2].info = 1;
	w->pars[2].depth = 100;
	w->pars[2].real = 0;
	w->pars[2].nreal = 0;
	w->pars[2].julia = 0;
	w->pars[2].js_stop = 0;
	w->pars[2].rph = 4.4;
	w->pars[2].gph = 4.4;
	w->pars[2].bph = 4.4;
	w->pars[2].rfr = 0.05;
	w->pars[2].gfr = -0.05;
	w->pars[2].bfr = -0.1;
	w->pars[2].kx = 1.8;
	w->pars[2].ky = 1.44;
	w->pars[2].centx = 1.8 - w->pars[2].kx - 0.5;
	w->pars[2].centy = 1.44 - w->pars[2].ky - 0.5;
	w->pars[2].fr_name = "Burning Ship set";
	w->pars[5].bfr = 0.15;
	w->pars[5].kx = 1.8;
	w->pars[5].ky = 1.44;
	w->pars[5].centx = 1.8 - w->pars[5].kx;
	w->pars[5].centy = 1.44 - w->pars[5].ky;
}

void	init_julia_set(t_win *w)
{
	w->pars[1].zoom = 1;
	w->pars[1].info = 1;
	w->pars[1].depth = 100;
	w->pars[1].real = -.606;
	w->pars[1].nreal = -.4992;
	w->pars[1].julia = 1;
	w->pars[1].js_stop = 0;
	w->pars[1].rph = 0;
	w->pars[1].gph = -2;
	w->pars[1].bph = -1;
	w->pars[1].rfr = 0.05;
	w->pars[1].gfr = 0.1;
	w->pars[1].bfr = -0.1;
	w->pars[1].kx = 2;
	w->pars[1].ky = 1.6;
	w->pars[1].centx = 2 - w->pars[1].kx;
	w->pars[1].centy = 1.6 - w->pars[1].ky;
	w->pars[1].fr_name = "Julia set";
	w->pars[5].fr_name = "Newton Fractal";
	w->pars[5].rfr = 0.2;
	w->pars[5].gfr = 0.25;
}

void	init_par(t_win *w)
{
	w->pars[0].zoom = 1;
	w->pars[0].info = 1;
	w->pars[0].depth = 100;
	w->pars[0].real = 0;
	w->pars[0].nreal = 0;
	w->pars[0].julia = 0;
	w->pars[0].js_stop = 0;
	w->pars[0].rph = 4;
	w->pars[0].gph = 4;
	w->pars[0].bph = 4;
	w->pars[0].rfr = 0.15;
	w->pars[0].gfr = 0.15;
	w->pars[0].bfr = 0.15;
	w->pars[0].kx = 1.5;
	w->pars[0].ky = 1.2;
	w->pars[0].centx = 1.5 - w->pars[0].kx - 0.75;
	w->pars[0].centy = 1.2 - w->pars[0].ky;
	w->pars[0].fr_name = "Mandelbrot set";
	init_julia_set(w);
	init_burningship_set(w);
	init_newton(w);
	init_mn1_fractal(w);
}
