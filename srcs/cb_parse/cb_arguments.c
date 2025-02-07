/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_arguments.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:14:04 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 12:57:37 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_def_textures(t_data *data)
{
	if (data->tx.no_t == NULL)
		data->tx.no_t = ft_strdup(DEF_TX_NO);
	if (data->tx.ea_t == NULL)
		data->tx.ea_t = ft_strdup(DEF_TX_EA);
	if (data->tx.so_t == NULL)
		data->tx.so_t = ft_strdup(DEF_TX_SO);
	if (data->tx.we_t == NULL)
		data->tx.we_t = ft_strdup(DEF_TX_WE);
	if (data->tx.f_lock == 0)
	{
		data->tx.f_cl[0] = DEF_F_R;
		data->tx.f_cl[1] = DEF_F_G;
		data->tx.f_cl[2] = DEF_F_B;
	}
	if (data->tx.c_lock == 0)
	{
		data->tx.c_cl[0] = DEF_C_R;
		data->tx.c_cl[1] = DEF_C_G;
		data->tx.c_cl[2] = DEF_C_B;
	}
	data->ray.assets.c_cl = cb_rgb(data->tx.c_cl[0],
			data->tx.c_cl[1], data->tx.c_cl[2]);
	data->ray.assets.f_cl = cb_rgb(data->tx.f_cl[0],
			data->tx.f_cl[1], data->tx.f_cl[2]);
}

static void	cb_check_map_empty_lines(char *istream)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (istream[++i])
	{
		if (istream[i] == '\n' && istream[i + 1] == '\n' && flag)
			cb_error(ERR_MSS_MEL);
		if (istream[i] == '\n')
		{
			if (istream[i + 1] != '\n')
				i++;
			while (istream[i] == ' ' || istream[i] == '\t')
				i++;
			if (flag == 0 && ft_isdigit(istream[i]))
				flag = 1;
		}
	}
	if (istream[i - 2] == '\n')
		cb_error(ERR_MSS_MEL);
}

void	cb_arguments(t_data *data, char *file)
{
	if (!ft_check_ext(file, "cub"))
		cb_error(ERR_MSS_CUB);
	if (ft_check_file(file) == -1)
		cb_error(ERR_MSS_FNF);
	ft_ftos(file, &data->parse.istream);
	cb_check_map_empty_lines(data->parse.istream);
	data->parse.import = ft_split(data->parse.istream, '\n');
	cb_base_format_import(data);
	cb_def_textures(data);
}
