/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:56:43 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/01 17:34:15 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int hex_to_decimal(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res += pow(16, i) * (str[i] - '0');
		else
			res += pow(16, i) * (str[i] - 'A' + 10);
		i++;
	}
	return (res);
}

t_pixel new_pixel(int z, int color)
{
	t_pixel new;

	new.z = z;
	new.color = color;
	return (new);	
}

t_pixel get_z_color(char *tab, int n)
{
	int z;
	int color;

	tab[n] = '\0';
	z = ft_atoi(tab);
	color = hex_to_decimal(tab + (n + 3));
	
	return (new_pixel(z, color));
}

t_pixel filter(char *tab)
{
	t_pixel pixel;
	int n;

	if ((n = is_color(tab)) != -1)
		pixel = get_z_color(tab, n);
	else
		pixel = new_pixel(ft_atoi(tab), 0);
	return (pixel);	
}


t_pixel **get_map(int fd, t_map_len size)
{
	t_pixel **map;
	char **tab;
	char *line;
	int i;
	int j;

	i = 0;
	if (!(map = (t_pixel **)malloc(sizeof(t_pixel *) * size.y_len)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		if (!(map[i] = (t_pixel *)malloc(sizeof(t_pixel) * size.x_len)))
			return (NULL);
		j = 0;
		while (tab[j])
		{
			map[i][j] = filter(tab[j]);	
			j++;
		}
		i++;
	}
	return (map);
}
