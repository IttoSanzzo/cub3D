/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_parse_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:40:55 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/25 12:22:29 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_fc_split(char ***parse)
{
	int		i;
	char	**temp;

	if (ft_tablen(parse[0]) > 4)
		cb_error(ERR_MSS_IEL);
	temp = ft_tabdup(*parse + 1);
	ft_nfreetab(parse);
	i = ft_tablen(temp);
	while (--i > 0)
		ft_sujoin(&temp[i - 1], temp[i]);
	if (temp[0][ft_strlen(temp[0]) - 1] == ',')
	{
		ft_nfreetab(&temp);
		cb_error(ERR_MSS_IEL);
	}
	*parse = ft_split(temp[0], ',');
	ft_nfreetab(&temp);
	if (ft_tablen(parse[0]) < 3)
		cb_error(ERR_MSS_IEL);
}

static void	cb_set_fc_rgb(int rgb[3], int *lock, char ***parse)
{
	int	i;
	int	y;

	if (!parse[0][1])
		cb_error(ERR_MSS_MEV);
	if (*lock)
		cb_error(ERR_MSS_DEL);
	*lock = 1;
	cb_fc_split(parse);
	i = -1;
	while (parse[0][++i])
	{
		y = -1;
		if (parse[0][i][0] == '+')
			y++;
		while (parse[0][i][++y])
			if (!ft_isdigit(parse[0][i][y]))
				cb_error(ERR_MSS_IRV);
		rgb[i] = ft_atoi(parse[0][i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			cb_error(ERR_MSS_IRV);
	}
}

static void	cb_set_xpm(char **tx_s, char **parse)
{
	if (*tx_s)
		cb_error(ERR_MSS_DEL);
	if (!*parse)
		cb_error(ERR_MSS_MEV);
	if (parse[1])
		cb_error(ERR_MSS_IEL);
	if (!ft_check_ext(*parse, "xpm"))
		cb_error(ERR_MSS_XPM);
	if (ft_check_file(*parse))
		cb_error(ERR_MSS_TNF);
	*tx_s = ft_strdup(*parse);
}

static void	cb_set_element(t_textures *tx, char ***parse)
{
	if (!ft_strncmp(parse[0][0], "NO", 3))
		cb_set_xpm(&tx->no_t, *parse + 1);
	else if (!ft_strncmp(parse[0][0], "EA", 3))
		cb_set_xpm(&tx->ea_t, *parse + 1);
	else if (!ft_strncmp(parse[0][0], "SO", 3))
		cb_set_xpm(&tx->so_t, *parse + 1);
	else if (!ft_strncmp(parse[0][0], "WE", 3))
		cb_set_xpm(&tx->we_t, *parse + 1);
	else if (!ft_strncmp(parse[0][0], "F", 2))
		cb_set_fc_rgb(tx->f_cl, &tx->f_lock, parse);
	else if (!ft_strncmp(parse[0][0], "C", 2))
		cb_set_fc_rgb(tx->c_cl, &tx->c_lock, parse);
	else
		cb_error(ERR_MSS_IEL);
	ft_nfreetab(parse);
}

void	cb_parse_elements(t_data *data)
{
	int	i;

	i = -1;
	while (data->parse.elements[++i])
	{
		data->parse.temp = ft_split(data->parse.elements[i], ' ');
		cb_set_element(&data->tx, &data->parse.temp);
	}
}
