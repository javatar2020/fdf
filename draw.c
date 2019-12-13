/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:33:51 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/14 00:10:58 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_pixel start, t_pixel end, void *mlx_ptr, void *mlx_win)
{
	t_bresenham data;

	data.dx = abs(end.x - start.x);
	data.sx = start.x < end.x ? 1 : -1;
	data.dy = abs(end.y - start.y);
	data.sy = start.y < end.y ? 1 : -1;
	data.err = (data.dx > data.dy ? data.dx : -data.dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, start.x, start.y, start.color);
		if (start.x == end.x && start.y == end.y)
			break ;
		data.e2 = data.err;
		if (data.e2 > -data.dx)
		{
			data.err -= data.dy;
			start.x += data.sx;
		}
		if (data.e2 < data.dy)
		{
			data.err += data.dx;
			start.y += data.sy;
		}
	}
}

void	draw(t_map data)
{
	int y;
	int x;

	mlx_clear_window(data.mlx_ptr, data.mlx_win);
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 10, 0xFFFFFF, "p");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 30, 0xFFFFFF, "i");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 50, 0xFFFFFF, "+");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 70, 0xFFFFFF, "-");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 90, 0xFFFFFF, "up");
	mlx_string_put(data.mlx_ptr, data.mlx_win, 10, 110, 0xFFFFFF, "down");
	y = -1;
	while (++y < data.size.y)
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
	}
}
