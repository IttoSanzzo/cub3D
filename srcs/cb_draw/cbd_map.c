/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:15:26 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 11:57:08 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cbd_map(void)
{
	static t_data	*data;
	int				x;
	int				y;
	int				xo;
	int				yo;

	if (data == NULL)
		data = cb_get_data(NULL);
	y = -1;
	while (++y < data->ray.mly)
	{
		x = -1;
		while (++x < data->ray.mlx)
		{
			xo = x * MAP_S;
			yo = y * MAP_S;
			if (data->ray.map[y][x] == 0)
				cbd_rect(cb_rgb(1, 1, 1), (int [2]){xo + 1, yo + 1},
					(int [2]){MAP_S - 1, MAP_S - 1});
			else if (data->ray.map[y][x] == 1)
				cbd_rect(cb_rgb(255, 255, 255), (int [2]){xo + 1, yo + 1},
					(int [2]){MAP_S - 1, MAP_S - 1});
		}
	}
}
