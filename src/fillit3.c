/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:05:22 by mriley            #+#    #+#             */
/*   Updated: 2019/06/06 16:50:34 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		minx(t_tetri *mass)
{
	int i;
	int min;

	i = 1;
	min = mass->x[0];
	while (i < 4)
	{
		if (mass->x[i] < min)
			min = mass->x[i];
		i++;
	}
	free(mass);
	return (min);
}

int		miny(t_tetri *mass)
{
	int i;
	int min;

	i = 1;
	min = mass->y[0];
	while (i < 4)
	{
		if (mass->y[i] < min)
			min = mass->y[i];
		i++;
	}
	return (min);
}

void	ft_znak(int *y, int u, t_tetri *per)
{
	if (u == 1)
	{
		y[0] = 0;
		y[1] = 0;
	}
	else
	{
		y[0] = miny(per);
		y[1] = minx(per) + 1;
	}
}
