/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:52:50 by kkhabour          #+#    #+#             */
/*   Updated: 2019/12/12 23:19:21 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_pixel **map, t_mapsize size)
{
	t_map	data;

	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, 800, 800, "fdf");
	data.map = map;
	data.size = size;
	data.is_pressed = 0;
	data.rotation = 0.523599;
	data.z = 1;
	data.zoom = (0.4 * 800) / data.size.x;
	mlx_hook(data.mlx_win, 2, 0, key_press, (void *)&data);
	mlx_hook(data.mlx_win, 4, 0, mouse_press, (void *)&data);
	mlx_hook(data.mlx_win, 5, 0, mouse_release, (void *)&data);
	mlx_hook(data.mlx_win, 6, 0, mouse_move, (void *)&data);
	draw(data);
	mlx_loop(data.mlx_ptr);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_pixel		**map;
	t_mapsize	size;

	if (argc != 2)
		exit_error(-1, EXIT_FAILURE, "Arguments error");
	fd = open(argv[1], O_RDONLY);
	check_map(fd, &size);
	fd = open(argv[1], O_RDONLY);
	map = get_map(fd, size);
	close(fd);
	init(map, size);
	del_map(map, size);
	return (0);
}
