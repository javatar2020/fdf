/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:33:51 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/10 18:59:34 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_pixel start, t_pixel end, void *mlx_ptr, void *mlx_win)
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;

	dx = abs(end.x - start.x);
	sx = start.x < end.x ? 1 : -1;
	dy = abs(end.y - start.y);
	sy = start.y < end.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, start.x, start.y, start.color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
	}
}

void	draw(t_map data)
{
	int y;
	int x;

	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	y = 0;
	while (y < data.size.y)
	{
		x = 0;
		while (x < data.size.x)
		{
			if (x + 1 != data.size.x)
				bresenham(data.map[y][x], data.map[y][x + 1],
						data.mlx_ptr, data.mlx_win);
			if (y + 1 != data.size.y)
				bresenham(data.map[y][x], data.map[y + 1][x],
						data.mlx_ptr, data.mlx_win);
			x++;
		}
		y++;
	}
}
