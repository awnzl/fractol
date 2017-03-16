/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_focus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avenzel <avenzel@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:55:02 by avenzel           #+#    #+#             */
/*   Updated: 2017/03/15 17:06:41 by avenzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mouse_focus(t_win *w, double mousex, double mousey, double mult)
{
	double xmaxmin[2];
	double ymaxmin[2];

	w->par->zoom = w->par->zoom / mult;
	mousex = mousex / w->width * (w->par->kx * 2) +
		w->par->centx - w->par->kx;
	mousey = mousey / w->height * (w->par->ky * 2) +
		w->par->centy - w->par->ky;
	xmaxmin[0] = (w->par->centx - w->par->kx) * mult + mousex * (1 - mult);
	xmaxmin[1] = (w->par->centx + w->par->kx) * mult + mousex * (1 - mult);
	ymaxmin[0] = (w->par->centy - w->par->ky) * mult + mousey * (1 - mult);
	ymaxmin[1] = (w->par->centy + w->par->ky) * mult + mousey * (1 - mult);
	w->par->kx = (xmaxmin[1] - xmaxmin[0]) / 2;
	w->par->ky = (ymaxmin[1] - ymaxmin[0]) / 2;
	w->par->centx = (xmaxmin[1] - w->par->kx);
	w->par->centy = (ymaxmin[1] - w->par->ky);
}
