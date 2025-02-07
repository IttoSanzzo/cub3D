/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:16:43 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/23 12:37:36 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_free_mlx(t_assets *assets, t_mlx *mlx, t_img *img)
{
	if (assets->no_t.ptr)
		mlx_destroy_image(mlx->con, assets->no_t.ptr);
	if (assets->ea_t.ptr)
		mlx_destroy_image(mlx->con, assets->ea_t.ptr);
	if (assets->so_t.ptr)
		mlx_destroy_image(mlx->con, assets->so_t.ptr);
	if (assets->we_t.ptr)
		mlx_destroy_image(mlx->con, assets->we_t.ptr);
	if (img->ptr)
		mlx_destroy_image(mlx->con, img->ptr);
	if (mlx->win)
		mlx_destroy_window(mlx->con, mlx->win);
	if (mlx->con)
	{
		mlx_destroy_display(mlx->con);
		free(mlx->con);
	}
}

static void	cb_free_all(t_data *data)
{
	ft_nfreetab(&(data->parse.elements));
	ft_nfreestr(&(data->parse.istream));
	ft_nfreetab(&(data->parse.import));
	ft_nfreetab(&(data->parse.layout));
	ft_nfreetab(&(data->parse.temp));
	ft_nfreeitab(&(data->ray.layout));
	ft_nfreeitab(&(data->ray.map));
	ft_nfree((void *)&(data->ray.umap));
	ft_nfreestr(&(data->tx.no_t));
	ft_nfreestr(&(data->tx.ea_t));
	ft_nfreestr(&(data->tx.so_t));
	ft_nfreestr(&(data->tx.we_t));
	cb_free_mlx(&data->ray.assets, &data->mlx, &data->img);
}

void	cb_exit(int exit_value)
{
	cb_free_all(cb_get_data(NULL));
	exit (exit_value);
}
