/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookfuncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:02:32 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 19:39:44 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_hook(int x, int y, t_win *win)
{
	if (!win->par->js_stop)
	{
		win->par->real = (x * 0.002) - 1;
		win->par->nreal = (y * 0.0016) - 0.8;
		put_image(win);
	}
	return (0);
}

void	check_keys(int kc, t_win *w)
{
	if (kc == 19 || kc == 18)
	{
		w->par = (kc == 19) ? &w->pars[1] : &w->pars[0];
		w->func = (kc == 19) ? &jspix : &mspix;
	}
	else if (kc == 20 || kc == 21)
	{
		w->par = (kc == 20) ? &w->pars[2] : &w->pars[4];
		w->func = (kc == 20) ? &bsspix : &nfpix;
	}
	else if (kc == 22 || kc == 23)
	{
		w->par = (kc == 22) ? &w->pars[4] : &w->pars[5];
		w->func = (kc == 22) ? &mn1pix : &mn2pix;
	}
	else if (kc == 69 || kc == 78)
		(kc == 69) ? mouse_focus(w, 500, 400, 1.1) : mouse_focus(w, 500, 400, 0.9);
	else if (kc == 24 || kc == 27)
		w->par->depth += (kc == 24) ? 50 : -50;
	else if (kc == 126 || kc == 125)
		w->par->centy += (kc == 125) ? 0.1 / w->par->zoom : -.1 / w->par->zoom;
	else if (kc == 123 || kc == 124)
		w->par->centx += (kc == 124) ? 0.1 / w->par->zoom : -.1 / w->par->zoom;
	else if (kc == 34)
		w->par->info = (w->par->info == 1) ? 0 : 1;
}

int		key_hook(int kc, t_win *w)
{
	if (kc == 53)
		exit(0);
	else if (kc == 35)
		w->par->js_stop = (w->par->js_stop == 1) ? 0 : 1;
	else if (kc == 15 || kc == 3)
		w->par->rph += (kc == 15) ? .2 : -.2;
	else if (kc == 17 || kc == 5)
		w->par->gph += (kc == 17) ? .2 : -.2;
	else if (kc == 16 || kc == 4)
		w->par->bph += (kc == 16) ? .2 : -.2;
	else if (kc == 38 || kc == 46)
		w->par->rfr += (kc == 38) ? .05 : -.05;
	else if (kc == 40 || kc == 43)
		w->par->gfr += (kc == 40) ? .05 : -.05;
	else if (kc == 37 || kc == 47)
		w->par->bfr += (kc == 37) ? .05 : -.05;
	else
		check_keys(kc, w);
	put_image(w);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *w)
{
	if (x > 0 && y > 0)
	{
		if (button == 5)
		{
			mouse_focus(w, x, y, 1.1);
		}
		else if (button == 4)
		{
			mouse_focus(w, x, y, 0.9);
		}
	}
	put_image(w);
	return (0);
}

int		check_args(int ac, char **av)
{
	int	i;

	if (ac > 0)
	{
		i = -1;
		while (av[++i])
			if (av[i][0] < '0' || av[i][0] > '5' || av[i][1] != 0)
				return (1);
	}
	return (0);
}
