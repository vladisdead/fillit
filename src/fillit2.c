/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:59:30 by mriley            #+#    #+#             */
/*   Updated: 2019/06/06 16:51:02 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	**solveotkat(t_tetri *mass, char **solve)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!mass)
		return (solve);
	while (solve[i] != '\0')
	{
		while (solve[i][j] != '\0')
		{
			if (solve[i][j] == mass->c)
				solve[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (solve);
}

t_tetri	*koordin(t_tetri *mass, char **solve)
{
	t_tetri *tr;
	int		i;
	int		j;
	int		f;

	f = 0;
	i = 0;
	j = 0;
	tr = (t_tetri*)malloc(sizeof(t_tetri));
	while (solve[i] != '\0')
	{
		while (solve[i][j] != '\0')
		{
			if (solve[i][j] == mass->c)
			{
				tr->x[f] = j;
				tr->y[f++] = i;
			}
			j++;
		}
		j = 0;
		i++;
	}
	solve = solveotkat(mass, solve);
	return (tr);
}

void	ft_delete(char **solve, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		free(solve[i]);
		i++;
	}
	free(solve);
}

char	**nee(int i)
{
	char	**solve;
	int		y;

	y = 0;
	solve = (char**)malloc(sizeof(char*) * (i + 1));
	if (solve == NULL)
		return (NULL);
	solve[i] = 0;
	while (y++ < i)
	{
		solve[y - 1] = ft_strnew(i);
		if (solve[y - 1] == NULL)
		{
			ft_delete(solve, y - 1);
			return (NULL);
		}
		ft_memset(solve[y - 1], '.', i);
	}
	return (solve);
}

char	**solving(t_tetri *mass1, int x, int y, char **solve)
{
	int r;
	int i;

	i = ft_strlen(solve[y]);
	r = -1;
	while (r++ < 3)
		solve[mass1->y[r] + y][mass1->x[r] + x] = mass1->c;
	return (solve);
}
