/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:32:00 by mriley            #+#    #+#             */
/*   Updated: 2019/06/06 16:50:52 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int		*init(void)
{
	int	*y;
	int	i;

	i = 0;
	y = (int*)malloc(5 * sizeof(int));
	if (y == NULL)
		return (NULL);
	while (i < 5)
	{
		y[i] = 0;
		i++;
	}
	return (y);
}

int		ft_recurs(t_tetri *mass, int i, char **solve, int *y)
{
	t_tetri			*per;

	while (mass)
	{
		if (pr1(mass, y[1], y[0], i) == 1 || pr2(solve, y[1], y[0], mass) == 1)
		{
			(y[1] >= i) ? y[(y[1] = 0)]++ : y[1]++;
			if (y[0] >= i && y[1] >= i)
			{
				if (!mass->left_next)
					return (0);
				per = koordin(mass->left_next, solve);
				mass = mass->left_next;
				ft_znak(y, 0, per);
			}
		}
		else
		{
			if (proverka3(mass, y[1], y[0], solve) == 1)
				return (1);
			mass = mass->right_next;
			ft_znak(y, 1, NULL);
		}
	}
	return (0);
}

int		fillit(t_tetri *mass, int i)
{
	char	**solve;
	int		*y;

	solve = nee(i);
	y = init();
	while (ft_recurs(mass, i, solve, y) == 0)
	{
		free(y);
		y = init();
		i++;
		ft_delete(solve, i);
		solve = nee(i);
	}
	free(y);
	return (1);
}

int		main(int argc, char **argv)
{
	int		df;
	char	*s;
	t_tetri *ss;

	if (argc < 2)
	{
		ft_putendl("error");
		return (0);
	}
	df = open(argv[1], O_RDONLY);
	s = savestr(df);
	if (s == NULL || !check_str(s))
	{
		ft_putendl("error");
		return (0);
	}
	ss = savetetri(s);
	free(s);
	truecoord(ss);
	ss->left_next = NULL;
	fillit(ss, 2);
	deltetri1(ss);
	return (1);
}
