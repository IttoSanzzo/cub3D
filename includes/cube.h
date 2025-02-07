/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:14:14 by marcosv2          #+#    #+#             */
/*   Updated: 2024/04/24 12:51:16 by marcosv2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

/// Includes
# include "../libft/includes/libft.h"
# include "./cb_macros.h"
# include "./cb_structs.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"

//// cb_main
int		main(int ac, char *av[]);
void	cb_base_init(t_data *data);
void	cb_exit(int exit_value);

//// cb_parse
void	cb_arguments(t_data *data, char *file);
void	cb_base_format_import(t_data *data);
void	cb_parse_elements(t_data *data);
void	cb_parse_map(t_data *data);
void	cb_layout_to_map(char **tab, t_ray *ray);

//// cb_mlx
void	cb_mlx_init(t_data *data);
void	cb_mlx_events_init(t_data *data, t_mlx *mlx);
int		cb_render(t_data *data);

//// cb_ray
void	cb_check_moves(t_ray *ray);
void	cb_calc_rays(t_data *data);
void	cb_walls(t_ray *ray, t_inf *inf, t_wall *wall);

//// cb_utils
t_data	*cb_get_data(t_data *data);
void	cb_error(char *error);
float	cb_dist(float ax, float ay, float bx, float by);
void	cb_upt_r(float *r, float upt);
int		cb_gpc(t_img *img, int x, int y);

//// cb_draw
int		cb_rgb(int r, int g, int b);
void	cb_ipp(t_img *img, int color, int x, int y);
void	cbd_clrc(int color);
void	cbd_rect(int color, int c[2], int s[2]);
void	cbd_dotp(int color, int size, int x, int y);
void	cbd_point(int color, int size, int x, int y);
void	cbd_line(int color, int width, int s[2], int e[2]);
void	cbd_sline(int color, int width, int s[2], int e[2]);
void	cbd_pov(void);
void	cbd_map(void);

#endif