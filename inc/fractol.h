/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:24:44 by avenzel           #+#    #+#             */
/*   Updated: 2017/12/05 20:41:50 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# define ABS(x) ((x < 0) ? -(x) : (x))

typedef struct		s_params
{
	double			zoom;
	double			mousex;
	double			mousey;
	double			kx;
	double			ky;
	double			centx;
	double			centy;
	int				info;
	int				depth;
	int				js_stop;
	double			real;
	double			nreal;
	int				julia;
	double			rph;
	double			gph;
	double			bph;
	double			rfr;
	double			gfr;
	double			bfr;
	char			*fr_name;
}					t_params;

typedef struct		s_win
{
	t_params		*par;
	t_params		pars[6];
	void			*mlx;
	void			*win;
	void			*img;
	char			*imgdat;
	int				*imdat;
	int				bspp;
	int				ls;
	int				endian;
	int				width;
	int				height;
	void			(*func)(double, double, struct s_win*);
}					t_win;

typedef struct		s_frtl
{
	double			real;
	double			imag;
	double			cx;
	double			cy;
}					t_frtl;

typedef struct		s_fthrds
{
	t_win			*w;
	int				y;
	pthread_t		tid;
}					t_forthreads;

union				u_col
{
	unsigned int	col;
	unsigned char	c[4];
};

void				fractal(int i);
void				wininit(t_win *win);
void				init_par(t_win *win);
void				forkit(int ac, char **av);
void				mandelbrot_set(int i);
void				mn1_fractal(int i);
void				mn2_fractal(int i);
void				newton_fractal(int i);
void				julia_set(int i);
void				burning_ship_set(int i);
void				put_image(t_win *w);
void				info_insert(t_win *w);
void				mn1pix(double px, double py, t_win *win);
void				mn2pix(double px, double py, t_win *win);
void				nfpix(double px, double py, t_win *win);
void				mspix(double px, double py, t_win *win);
void				jspix(double px, double py, t_win *win);
void				bsspix(double px, double py, t_win *win);
void				mouse_focus(t_win *w, double mx, double my, double mult);
int					check_args(int ac, char **av);
int					get_col(double n, t_win *w);
int					move_hook(int x, int y, t_win *win);
int					key_hook(int keycode, t_win *win);
int					mouse_hook(int button, int x, int y, t_win *win);
double				ci(t_frtl z, double i);


int					ft_atoi(const char *s);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);

#endif
