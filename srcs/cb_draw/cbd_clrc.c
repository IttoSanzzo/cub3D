/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_clrc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:39:19 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 11:53:43 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cbd_clrc(int color)
{
	static t_data	*data;
	int				y;
	int				x;

	if (data == NULL)
		data = cb_get_data(NULL);
	y = -1;
	while (++y < W_HIGH)
	{
		x = -1;
		while (++x < W_WIDE)
			cb_ipp(&data->img, color, x, y);
	}
}
