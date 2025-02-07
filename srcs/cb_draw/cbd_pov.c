/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_pov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:53:39 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 13:46:37 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cbd_pov(void)
{
	static t_data	*data;
	static t_ray	*ray;

	if (ray == NULL)
	{
		data = cb_get_data(NULL);
		ray = &data->ray;
	}
	cbd_dotp(cb_rgb(255, 255, 0), 8, ray->pvx, ray->pvy);
	cbd_line(cb_rgb(255, 255, 0), 3, (int [2]){ray->pvx, ray->pvy},
		(int [2]){ray->pvx + ray->pdx * 5, ray->pvy + ray->pdy * 5});
}
