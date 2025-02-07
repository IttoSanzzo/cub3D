/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:52:21 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 19:27:39 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_horir_find(t_ray *ray, t_inf *inf)
{
	inf->disth = DS_DEF;
	inf->hx = ray->pvx;
	inf->hy = ray->pvy;
	while (inf->dof < MRD)
	{
		inf->mx = (int)(inf->rx) >> 6;
		inf->my = (int)(inf->ry) >> 6;
		inf->mp = inf->my * ray->mlx + inf->mx;
		if ((inf->mp >= 0 && inf->mp < ray->mlt - 1)
			&& inf->mp < ray->mlt && ray->umap[inf->mp] > 0)
		{
			inf->hx = inf->rx;
			inf->hy = inf->ry;
			inf->disth = cb_dist(ray->pvx, ray->pvy, inf->hx, inf->hy);
			inf->dof = MRD;
		}
		else
		{
			inf->rx += inf->xo;
			inf->ry += inf->yo;
			inf->dof += 1;
		}
	}
}

static void	cb_hori_ray(t_data *data, t_ray *ray, t_inf *inf)
{
	inf->dof = 0;
	inf->atan = -1 / tan(inf->ra);
	if (inf->ra == 0 || inf->ra == PI)
	{
		inf->rx = ray->pvx;
		inf->ry = ray->pvy;
		inf->dof = MRD;
	}
	if (inf->ra > PI)
	{
		inf->ry = ((((int)ray->pvy >> 6) << 6) - 0.0001);
		inf->rx = (ray->pvy - inf->ry) * inf->atan + ray->pvx;
		inf->yo = -MAP_S;
		inf->xo = -inf->yo * inf->atan;
		inf->htex = &data->ray.assets.so_t;
	}
	if (inf->ra < PI)
	{
		inf->ry = ((((int)ray->pvy >> 6) << 6) + MAP_S);
		inf->rx = (ray->pvy - inf->ry) * inf->atan + ray->pvx;
		inf->yo = MAP_S;
		inf->xo = -inf->yo * inf->atan;
		inf->htex = &data->ray.assets.no_t;
	}
	cb_horir_find(ray, inf);
}

static void	cb_vertr_find(t_ray *ray, t_inf *inf)
{
	inf->distv = DS_DEF;
	inf->vx = ray->pvx;
	inf->vy = ray->pvy;
	while (inf->dof < MRD)
	{
		inf->mx = (int)(inf->rx) >> 6;
		inf->my = (int)(inf->ry) >> 6;
		inf->mp = inf->my * ray->mlx + inf->mx;
		if ((inf->mp >= 0 && inf->mp < ray->mlt - 1)
			&& inf->mp < ray->mlt && ray->umap[inf->mp] > 0)
		{
			inf->vx = inf->rx;
			inf->vy = inf->ry;
			inf->distv = cb_dist(ray->pvx, ray->pvy, inf->vx, inf->vy);
			inf->dof = MRD;
		}
		else
		{
			inf->rx += inf->xo;
			inf->ry += inf->yo;
			inf->dof += 1;
		}
	}
}

static void	cb_vert_ray(t_data *data, t_ray *ray, t_inf *inf)
{
	inf->dof = 0;
	inf->ntan = -tan(inf->ra);
	if (inf->ra == PL || inf->ra == PR)
	{
		inf->rx = ray->pvx;
		inf->ry = ray->pvy;
		inf->dof = MRD;
	}
	if (inf->ra > PL && inf->ra < PR)
	{
		inf->rx = ((((int)ray->pvx >> 6) << 6) - 0.0001);
		inf->ry = (ray->pvx - inf->rx) * inf->ntan + ray->pvy;
		inf->xo = -MAP_S;
		inf->yo = -inf->xo * inf->ntan;
		inf->vtex = &data->ray.assets.ea_t;
	}
	if (inf->ra < PL || inf->ra > PR)
	{
		inf->rx = ((((int)ray->pvx >> 6) << 6) + MAP_S);
		inf->ry = (ray->pvx - inf->rx) * inf->ntan + ray->pvy;
		inf->xo = MAP_S;
		inf->yo = -inf->xo * inf->ntan;
		inf->vtex = &data->ray.assets.we_t;
	}
	cb_vertr_find(ray, inf);
}

void	cb_calc_rays(t_data *data)
{
	cb_upt_r(&data->ray.inf.ra, data->ray.pva - DR / 2 * (RAYS / 2));
	data->ray.inf.r = -1;
	data->ray.inf.index = -1;
	while (++data->ray.inf.r < RAYS)
	{
		cb_hori_ray(data, &data->ray, &data->ray.inf);
		cb_vert_ray(data, &data->ray, &data->ray.inf);
		if (data->ray.inf.disth < data->ray.inf.distv)
		{
			data->ray.inf.dist = data->ray.inf.disth;
			data->ray.inf.text = data->ray.inf.htex;
			data->ray.inf.rx = data->ray.inf.hx;
			data->ray.inf.ry = data->ray.inf.hy;
		}
		else
		{
			data->ray.inf.dist = data->ray.inf.distv;
			data->ray.inf.text = data->ray.inf.vtex;
		}
		if (++data->ray.inf.index == RAYS / 2)
			data->ray.inf.distl = data->ray.inf.dist;
		cb_walls(&data->ray, &data->ray.inf, &data->ray.wall);
		cb_upt_r(&data->ray.inf.ra, data->ray.inf.ra + DR / 2);
	}
}
