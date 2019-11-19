/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:52:50 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/19 00:54:30 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void del_map(t_pixel **map, t_mapsize size)
{
	int y;

	y = 0;
	while (y < size.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}


void draw(t_pixel start, t_pixel end, void *mlx_ptr, void *mlx_win)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	dx = end.x - start.x;
	dy = end.y - start.y;
	x = start.x;
	y = start.y;

	if (dx > dy)
	{
		p = 2 * dy - dx;
		while (x <= end.x)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, start.color);
			x++;
			if (p >= 0)
			{
				y = y + 1;
				p = p + 2 * dy - 2 * dx;		
			}
			else
				p = p + 2 * dy;

		}
	}
	else
	{
		p = 2 * dx - dy;
		while (y <= end.y)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, start.color);
			y++;
			if (p >= 0)
			{
				x = x + 1;
				p = p + 2 * dx - 2 * dy;		
			}
			else
				p = p + 2 * dx;
		}
	}
}

void init(t_pixel **map, t_mapsize size)
{
	void 		*mlx_ptr;
	void		*mlx_win;	
	int 		y;
	int 		x;
	t_map		m_map;

	m_map.map = map;
	m_map.size = size;
	y = 0;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 800, 800, "fdf");
	mlx_hook(mlx_win, 2, 0, key_press, (void *) &m_map);
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (x + 1 != size.x)
				draw(map[y][x], map[y][x + 1], mlx_ptr, mlx_win);
			if (y + 1 != size.y)
				draw(map[y][x], map[y + 1][x], mlx_ptr, mlx_win);

			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
}

int main(int argc, char **argv)
{
	int 		fd;
	t_pixel 	**map;
	t_mapsize 	size;


	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (check_map(fd, &size) == -1)
		ft_putendl("map is not valide.");
	else
		ft_putendl("map is valide");
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = get_map(fd, size);
	close(fd);

	init(map, size);

	del_map(map, size);
	return (0);
}
