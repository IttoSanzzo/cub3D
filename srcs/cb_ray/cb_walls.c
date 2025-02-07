/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:06:14 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 18:36:31 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_get_tx(t_inf *inf, t_wall *wall)
{
	if (inf->disth < inf->distv)
	{
		wall->tx = (int)(inf->rx / 2.0) % 32;
		if (inf->ra < PI)
			wall->tx = 31 - wall->tx;
	}
	else
	{
		wall->tx = (int)(inf->ry / 2.0) % 32;
		if (inf->ra > PL && inf->ra < PR)
			wall->tx = 31 - wall->tx;
	}
}

void	cb_walls(t_ray *ray, t_inf *inf, t_wall *wall)
{
	cb_upt_r(&wall->ca, ray->pva - inf->ra);
	inf->dist *= cos(wall->ca);
	wall->lineh = (MAP_S * WALL_S) / inf->dist;
	wall->ty_st = 32.0 / (float)wall->lineh;
	wall->ty_of = 0;
	if (wall->lineh > WALL_S)
	{
		wall->ty_of = (wall->lineh - WALL_S) / 2.0;
		wall->lineh = WALL_S;
	}
	wall->lineo = WALL_O - (wall->lineh >> 1);
	wall->ty = wall->ty_of * wall->ty_st;
	cb_get_tx(inf, wall);
	wall->y = -1;
	while (++wall->y < wall->lineh)
	{
		inf->color = cb_gpc(inf->text, (int)wall->tx, (int)wall->ty);
		cbd_point(inf->color, 8, inf->r * 8 + 4, wall->y + wall->lineo);
		wall->ty += wall->ty_st;
	}
}
