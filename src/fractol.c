/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:25:45 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/16 18:15:38 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thfun(void *v)
{
	int				x;
	int				y;
	int				lim;
	t_forthreads	*tft;

	tft = (t_forthreads*)v;
	y = (tft->y == 0) ? 0 : tft->y - 1;
	lim = tft->w->height / 4 + tft->y;
	while (++y < lim)
	{
		x = -1;
		while (++x < tft->w->width)
			tft->w->func(x, y, tft->w);
	}
	pthread_exit(NULL);
}

void	threads_manage(t_win *w)
{
	int				i;
	t_forthreads	tft[4];

	i = -1;
	while (++i < 4)
	{
		tft[i].w = w;
		tft[i].y = i * w->height / 4;
		pthread_create(&tft[i].tid, NULL, &thfun, (void*)&tft[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(tft[i].tid, NULL);
}

int		exit_buttons(void)
{
	exit(1);
	return (0);
}

void	put_image(t_win *w)
{
	w->img = mlx_new_image(w->mlx, w->width, w->height);
	w->imgdat = mlx_get_data_addr(w->img, &w->bspp, &w->ls,
			&w->endian);
	w->imdat = (int*)w->imgdat;
	threads_manage(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	if (w->par->info)
		info_insert(w);
	mlx_destroy_image(w->mlx, w->img);
	mlx_hook(w->win, 17, 0, exit_buttons, w);
	mlx_key_hook(w->win, &key_hook, w);
	mlx_mouse_hook(w->win, &mouse_hook, w);
	if (w->par->julia)
		mlx_hook(w->win, 6, 0, &move_hook, w);
}

int		main(int ac, char **av)
{
	if (ac < 2 || ac > 7 || check_args(ac - 1, av + 1))
	{
		ft_putendl("usage:	arg1 [arg2 arg3 arg4 arg5 arg6]");
		ft_putendl("	0 - Mandelbrot Set;");
		ft_putendl("	1 - Julia Set");
		ft_putendl("	2 - Burning Ship Set");
		ft_putendl("	3 - 1st Newton fractal");
		ft_putendl("	4 - 2nd Newton fractal");
		ft_putendl("	5 - 3rd Newton fractal");
	}
	else if (ac == 2)
		fractal(ft_atoi(av[1]));
	else
		forkit(ac, av + 1);
	return (0);
}
