/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 06:53:43 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 16:13:08 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cb_mlx_win_init(t_mlx *mlx, t_img *img)
{
	mlx->con = mlx_init();
	if (!mlx->con)
		cb_error(ERR_MSS_XINIT);
	mlx->win = mlx_new_window(mlx->con,
			W_WIDE, W_HIGH, W_NAME);
	if (!mlx->win)
		cb_error(ERR_MSS_XINIT);
	img->ptr = mlx_new_image(mlx->con,
			W_WIDE, W_HIGH);
	if (!img->ptr)
		cb_error(ERR_MSS_XINIT);
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->line_len, &img->endian);
}

static void	cb_xpm_to_img(void *con, char *xpm, t_img *img)
{
	img->ptr = mlx_xpm_file_to_image(con, xpm,
			&img->sx, &img->sy);
	if (!img->ptr)
		cb_error(ERR_MSS_FXPM);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_len, &img->endian);
}

static void	cb_assets_init(void *con, t_textures *tx, t_assets *assets)
{
	assets->f_cl = cb_rgb(tx->f_cl[0], tx->f_cl[1], tx->f_cl[2]);
	assets->c_cl = cb_rgb(tx->c_cl[0], tx->c_cl[1], tx->c_cl[2]);
	cb_xpm_to_img(con, tx->no_t, &assets->no_t);
	cb_xpm_to_img(con, tx->ea_t, &assets->ea_t);
	cb_xpm_to_img(con, tx->so_t, &assets->so_t);
	cb_xpm_to_img(con, tx->we_t, &assets->we_t);
}

void	cb_mlx_init(t_data *data)
{
	cb_mlx_win_init(&data->mlx, &data->img);
	cb_mlx_events_init(data, &data->mlx);
	cb_assets_init(data->mlx.con, &data->tx, &data->ray.assets);
}
