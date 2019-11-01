/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 01:52:50 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/01 17:34:18 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int fd;
	t_pixel **map;
	t_map_len size;

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
	return (0);
}
