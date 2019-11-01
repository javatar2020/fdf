/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:22:45 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/01 17:34:24 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./GNL/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map_len
{
	int y_len;
	int x_len;
}				t_map_len;

typedef struct s_pixel
{
	int	z;
	int color;
}				t_pixel;

int		check_map(int fd, t_map_len *size);
int		is_color(char *line);
int 	tab_len(char **tab);
t_pixel **get_map(int fd, t_map_len size);
#endif
