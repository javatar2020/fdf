/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 00:41:48 by kkhabour          #+#    #+#             */
/*   Updated: 2019/11/01 17:15:36 by kkhabour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int is_color(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return (i);
		i++;
	}
	return (-1);
}

int is_alldigits(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int color_format(char *line, int p)
{
	int i;

	i = 0;
	if ((p == 0) || (line[p + 1] != '0') || (line[p + 2] != 'x') || 
			(ft_strlen(line + p) != 9))
		return (-1);
	while(i < p)
	{
		if (ft_isdigit(line[i]) == 0)
			return (-1);
		i++;
	}
	i = p + 3;
	while (line[i])
	{
		if (((line[i] >= '0') && (line[i] <= '9')) ||
				((line[i] >= 'A') && (line[i] <= 'F')))
			i++;
		else
			return (-1);
	}
	return (1);
}

int tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void del_tab(char **tab, char *line)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(line);
}

int check_value(char **tab)
{
	int i;
	int n;

	i = 0;
	while (tab[i])
	{
		if ((n = is_color(tab[i])) != -1)
		{
			if (color_format(tab[i], n) == -1)
				return (-1);
		}
		else
		{
			if (is_alldigits(tab[i]) == 0)
				return (-1);
		}
		i++;
	}
	return (1);
}

int check_map(int fd, t_map_len *size)
{
	char **map;
	char *line;
	int n;

	size->y_len = 0;
	n = -1;
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strsplit(line, ' ');
		if (n == -1)
			n = tab_len(map);
		if (n != tab_len(map) || check_value(map) == -1)
		{
			del_tab(map, line);
			return (-1);
		}
		size->y_len++;
		del_tab(map, line);
	}
	size->x_len = n;
	return (1);
}












