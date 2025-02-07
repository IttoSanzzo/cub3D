/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 08:42:20 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 12:39:23 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	cb_close(int ret)
{
	cb_exit(ret);
	return (ret);
}

static int	cb_hand_keyr(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		data->ray.keys.k_l = 0;
	else if (keysym == XK_Right)
		data->ray.keys.k_r = 0;
	else if (keysym == XK_D || keysym == XK_d)
		data->ray.keys.k_d = 0;
	else if (keysym == XK_A || keysym == XK_a)
		data->ray.keys.k_a = 0;
	else if (keysym == XK_W || keysym == XK_w)
		data->ray.keys.k_w = 0;
	else if (keysym == XK_S || keysym == XK_s)
		data->ray.keys.k_s = 0;
	return (0);
}

static int	cb_hand_keyp(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		cb_close(0);
	else if (keysym == XK_Left)
		data->ray.keys.k_l = 1;
	else if (keysym == XK_Right)
		data->ray.keys.k_r = 1;
	else if (keysym == XK_D || keysym == XK_d)
		data->ray.keys.k_d = +1;
	else if (keysym == XK_A || keysym == XK_a)
		data->ray.keys.k_a = -1;
	else if (keysym == XK_W || keysym == XK_w)
		data->ray.keys.k_w = -1;
	else if (keysym == XK_S || keysym == XK_s)
		data->ray.keys.k_s = +1;
	return (0);
}

void	cb_mlx_events_init(t_data *data, t_mlx *mlx)
{
	mlx_hook(mlx->win, DestroyNotify, StructureNotifyMask, cb_close, 0);
	mlx_hook(mlx->win, KeyPress, KeyPressMask, cb_hand_keyp, data);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, cb_hand_keyr, data);
	mlx_loop_hook(mlx->con, cb_render, data);
}
