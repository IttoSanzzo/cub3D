/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_rect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 00:41:03 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 11:56:41 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cbd_rect(int color, int c[2], int s[2])
{
	static t_data	*data;
	int				i;
	int				j;

	if (data == NULL)
		data = cb_get_data(NULL);
	i = c[1] - 1;
	while (++i < c[1] + s[1])
	{
		j = c[0] - 1;
		while (++j < c[0] + s[0])
			cb_ipp(&data->img, color, j, i);
	}
}
