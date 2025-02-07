/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:03:14 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/17 23:11:02 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	cb_error(char *error)
{
	ft_putendl_fd(ERR_MSS_N, STDERR);
	ft_putendl_fd(error, STDERR);
	cb_exit(1);
}
