/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:33:51 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/19 00:54:27 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
void transaction(int p_y, int p_x, t_map tab)
{
	t_pixel     **map;
	t_mapsize   size;
	int         y;
	int         x;

	map = tab.map;
	size = tab.size;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			map[y][x].y += p_y;
			map[y][x].x += p_x;
		}
	}
	init(map, size);
}

int key_press(int keycode, void *param)
{
	printf("key = %d, %p, %d\n", keycode, param,);
	//t_map map = (t_map) *param;
	if (keycode == 53)
		exit(1);
	else if (keycode == 124)
	{
		//transaction(0, -1, map);
	}
	else if (keycode == 123)
	{
		//transaction(0, 1, map);
	}
	return (0);
}
