/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:22:45 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/19 00:46:46 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./GNL/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include "./minilibx/mlx.h"


typedef struct 	s_mapsize
{
	int 		y;
	int 		x;
}				t_mapsize;

typedef struct 	s_pixel
{
	int 		y;
	int 		x;
	int			z;
	int 		color;
}				t_pixel;

typedef struct 	s_map
{
	t_pixel 	**map;
	t_mapsize	size;
}				t_map;


void 			init(t_pixel **map, t_mapsize size);
void 			transaction(int p_y, int p_x, t_map tab);
int 			key_press(int keycode, void *param);
int				check_map(int fd, t_mapsize *size);
int				is_color(char *line);
int 			tab_len(char **tab);
void 			del_tab(char **tab, char *line);
t_pixel 		**get_map(int fd, t_mapsize size);

#endif
