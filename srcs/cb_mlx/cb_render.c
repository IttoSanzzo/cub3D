/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:57:53 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 12:46:49 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	cb_render(t_data *data)
{
	cbd_rect(data->ray.assets.c_cl, (int [2]){0, 0},
		(int [2]){W_WIDE, W_HIGH / 2});
	cbd_rect(data->ray.assets.f_cl, (int [2]){0, W_HIGH / 2},
		(int [2]){W_WIDE, W_HIGH / 2});
	cb_check_moves(&data->ray);
	cb_calc_rays(data);
	mlx_put_image_to_window(data->mlx.con, data->mlx.win, data->img.ptr, 0, 0);
	return (0);
}
