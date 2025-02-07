/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:28:26 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 12:36:17 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cbd_horl(t_img *img, int color, int y, int x[2])
{
	while (x[0] <= x[1])
		cb_ipp(img, color, x[0]++, y);
}

void	cbd_verl(t_img *img, int color, int x, int y[2])
{
	while (y[0] <= y[1])
		cb_ipp(img, color, x, y[0]++);
}

static void	cbdld(t_img *img, t_cbr *cbr)
{
	cbr->err = cbr->dx - cbr->dy;
	while (cbr->x0 != cbr->x1 || cbr->y0 != cbr->y1)
	{
		if (cbr->y0 != cbr->y1)
			cbd_horl(img, cbr->color, cbr->y0,
				(int [2]){cbr->x0 - cbr->wd / 2, cbr->x0 + (cbr->wd - 1) / 2});
		if (cbr->x0 != cbr->x1)
			cbd_verl(img, cbr->color, cbr->x0,
				(int [2]){cbr->y0 - cbr->wd / 2, cbr->y0 + (cbr->wd - 1) / 2});
		cbr->es = 2 * cbr->err;
		if (cbr->es > -cbr->dy)
		{
			cbr->err -= cbr->dy;
			cbr->x0 += cbr->sx;
		}
		if (cbr->es < cbr->dx)
		{
			cbr->err += cbr->dx;
			cbr->y0 += cbr->sy;
		}
	}
}

void	cbd_line(int color, int width, int s[2], int e[2])
{
	static t_data	*data = NULL;
	t_cbr			cbr;

	if (data == NULL)
		data = cb_get_data(NULL);
	cbr.color = color;
	cbr.x0 = s[0];
	cbr.y0 = s[1];
	cbr.x1 = e[0];
	cbr.y1 = e[1];
	cbr.wd = width;
	if (cbr.wd == 0)
		return ;
	cbr.dx = abs(e[0] - s[0]);
	cbr.dy = abs(e[1] - s[1]);
	if (s[0] < e[0])
		cbr.sx = 1;
	else
		cbr.sx = -1;
	if (s[1] < e[1])
		cbr.sy = 1;
	else
		cbr.sy = -1;
	cbdld(&data->img, &cbr);
}
