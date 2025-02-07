/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:43:41 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 11:48:27 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_pva_switch(char c, float *pva)
{
	if (c == 'N')
		*pva = PI + PI / 2;
	else if (c == 'E')
		*pva = 0;
	else if (c == 'S')
		*pva = PI / 2;
	else if (c == 'W')
		*pva = PI;
}

static void	cb_get_pov(char **map, float *pvx, float *pvy, float *pva)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_strchr(POV_ORIEN, map[y][x]))
			{
				if (*pva != -1)
					cb_error(ERR_MSS_MSP);
				cb_pva_switch(map[y][x], pva);
				*pvy = (y + 1) * MAP_S - (MAP_S / 2);
				*pvx = (x + 1) * MAP_S - (MAP_S / 2);
				map[y][x] = '0';
			}
		}
	}
	if (*pva == -1)
		cb_error(ERR_MSS_NSP);
}

static void	cb_check_map_chars(char **ray)
{
	int	y;
	int	x;

	y = -1;
	while (ray[++y])
	{
		x = -1;
		while (ray[y][++x])
		{
			if (!ft_strchr(MAP_VALID, ray[y][x]))
				cb_error(ERR_MSS_IMO);
		}
	}
}

static void	cb_map_trsl(t_ray *ray)
{
	int	y;
	int	x;
	int	yl;
	int	xl;
	int	i;

	yl = ray->mly + 1;
	xl = ray->mlx + 1;
	ray->map = ft_calloc(yl, sizeof(int *));
	ray->umap = ft_calloc((yl - 1) * (xl - 1) + 1, sizeof(int *));
	ray->mlt = ray->mly * ray->mlx;
	y = -1;
	while (++y < yl - 1)
		ray->map[y] = ft_calloc(xl, sizeof(int));
	y = -1;
	i = -1;
	while (++y < yl - 1)
	{
		x = -1;
		while (++x < xl - 1)
		{
			ray->map[y][x] = ray->layout[y + 1][x + 1];
			ray->umap[++i] = ray->layout[y + 1][x + 1];
		}
	}
}

void	cb_parse_map(t_data *data)
{
	cb_check_map_chars(data->parse.layout);
	cb_get_pov(data->parse.layout, &data->ray.pvx,
		&data->ray.pvy, &data->ray.pva);
	cb_layout_to_map(data->parse.layout, &data->ray);
	cb_map_trsl(&data->ray);
	data->ray.pdx = cos(data->ray.pva) * 5;
	data->ray.pdy = sin(data->ray.pva) * 5;
}
