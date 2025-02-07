/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_base_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:01:31 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 09:52:07 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	cb_part_elements(t_data *data, int y)
{
	char	*hold;

	hold = data->parse.import[y];
	data->parse.import[y] = NULL;
	data->parse.elements = ft_tabdup(data->parse.import);
	data->parse.import[y] = hold;
}

static void	cb_part(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->parse.import[++y])
	{
		x = 0;
		while (data->parse.import[y][x] && data->parse.import[y][x] == ' ')
			x++;
		if (!ft_isdigit(data->parse.import[y][x]))
			continue ;
		data->parse.layout = ft_tabdup(data->parse.import + y);
		cb_part_elements(data, y);
		return ;
	}
	cb_error(ERR_MSS_NVM);
}

void	cb_base_format_import(t_data *data)
{
	cb_part(data);
	cb_parse_elements(data);
	cb_parse_map(data);
}
