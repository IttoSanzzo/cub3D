/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:31:47 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 12:08:27 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_texture_init(t_data *data)
{
	data->tx.f_lock = 0;
	data->tx.c_lock = 0;
	data->tx.f_cl[0] = 0;
	data->tx.f_cl[1] = 0;
	data->tx.f_cl[2] = 0;
	data->tx.c_cl[0] = 0;
	data->tx.c_cl[1] = 0;
	data->tx.c_cl[2] = 0;
	data->tx.no_t = NULL;
	data->tx.ea_t = NULL;
	data->tx.so_t = NULL;
	data->tx.we_t = NULL;
	data->ray.assets.f_cl = 0;
	data->ray.assets.c_cl = 0;
	data->ray.assets.no_t.ptr = NULL;
	data->ray.assets.ea_t.ptr = NULL;
	data->ray.assets.so_t.ptr = NULL;
	data->ray.assets.we_t.ptr = NULL;
}

static void	cb_ray_init(t_data *data)
{
	data->ray.layout = NULL;
	data->ray.map = NULL;
	data->ray.umap = NULL;
	data->ray.mlx = 0;
	data->ray.mly = 0;
	data->ray.pvx = 0;
	data->ray.pvy = 0;
	data->ray.pdx = 0;
	data->ray.pdy = 0;
	data->ray.pva = -1;
	data->ray.inf.color = ICOL;
	data->ray.inf.distl = 0;
}

static void	cb_parse_init(t_data *data)
{
	data->parse.elements = NULL;
	data->parse.istream = NULL;
	data->parse.import = NULL;
	data->parse.layout = NULL;
	data->parse.temp = NULL;
}

void	cb_base_init(t_data *data)
{
	data->img.ptr = NULL;
	data->mlx.con = NULL;
	data->mlx.win = NULL;
	data->ray.keys.k_w = 0;
	data->ray.keys.k_a = 0;
	data->ray.keys.k_s = 0;
	data->ray.keys.k_d = 0;
	data->ray.keys.k_l = 0;
	data->ray.keys.k_r = 0;
	cb_parse_init(data);
	cb_get_data(data);
	cb_texture_init(data);
	cb_ray_init(data);
}
