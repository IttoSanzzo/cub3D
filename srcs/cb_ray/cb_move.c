/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:49:00 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:45 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_move(t_ray *ray, int vd, int hd)
{
	float	angle;
	float	fx;
	float	fy;
	int		xo;
	int		yo;

	angle = ray->pva + PI;
	if (ray->inf.distl < T_MLD)
	{
		fx = vd * M_MSL * cos(angle) + hd * M_MSL * sin(angle);
		fy = vd * M_MSL * sin(angle) - hd * M_MSL * cos(angle);
	}
	else
	{
		fx = vd * K_MSN * cos(angle) + hd * K_MSN * sin(angle);
		fy = vd * K_MSN * sin(angle) - hd * K_MSN * cos(angle);
	}
	xo = 1 * (fx > 0) + -1 * (fx < 0);
	yo = 1 * (fy > 0) + -1 * (fy < 0);
	if (ray->umap[(int)(ray->pvy / MAP_S) * ray->mlx
		+ (int)(ray->pvx + xo * M_WO) / MAP_S] == 0)
		ray->pvx += fx;
	if (ray->umap[(int)(ray->pvy + yo * M_WO) / MAP_S * ray->mlx
		+ (int)(ray->pvx / MAP_S)] == 0)
		ray->pvy += fy;
}

void	cb_check_moves(t_ray *ray)
{
	if (ray->keys.k_r == 1)
	{
		ray->pva += K_LSN + (K_LSL * (ray->inf.distl < T_LLD));
		if (ray->pva > 2 * PI)
			ray->pva -= 2 * PI;
		ray->pdx = cos(ray->pva) * 5;
		ray->pdy = sin(ray->pva) * 5;
	}
	if (ray->keys.k_l == 1)
	{
		ray->pva -= K_LSN + (K_LSL * (ray->inf.distl < T_LLD));
		if (ray->pva < 0)
			ray->pva += 2 * PI;
		ray->pdx = cos(ray->pva) * 5;
		ray->pdy = sin(ray->pva) * 5;
	}
	if (ray->keys.k_w + ray->keys.k_s != 0
		|| ray->keys.k_d + ray->keys.k_a != 0)
		cb_move(ray,
			ray->keys.k_s + ray->keys.k_w, ray->keys.k_d + ray->keys.k_a);
}
