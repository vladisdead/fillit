/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:55:04 by mriley            #+#    #+#             */
/*   Updated: 2019/06/06 16:50:26 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	gig(char **solve)
{
	int i;

	i = 0;
	while (solve[i])
	{
		ft_putstr(solve[i]);
		ft_putchar('\n');
		i++;
	}
	ft_delete(solve, i);
}

int		pr1(t_tetri *mass, int x, int y, int i)
{
	if (mass->y[0] + y >= i || mass->x[0] + x >= i || mass->y[1] + y >= i ||
		mass->x[1] + x >= i || mass->y[2] + y >= i || mass->x[2] + x >= i ||
		mass->y[3] + y >= i || mass->x[3] + x >= i)
		return (1);
	else
		return (0);
}

int		pr2(char **solve, int x, int y, t_tetri *mass)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (solve[mass->y[i] + y][mass->x[i] + x] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		poisk(char **solve, char t)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (solve[i] != '\0')
	{
		while (solve[i][j] != '\0')
		{
			if (solve[i][j] == t)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		proverka3(t_tetri *mass, int x, int y, char **solve)
{
	t_tetri *mass1;

	mass1 = mass;
	if (!mass)
		return (0);
	solve = solving(mass, x, y, solve);
	while (mass)
	{
		if (poisk(solve, mass->c) == 1)
			return (0);
		mass = mass->right_next;
	}
	while (mass1)
	{
		if (poisk(solve, mass1->c) == 1)
			return (0);
		mass1 = mass1->left_next;
	}
	gig(solve);
	return (1);
}
