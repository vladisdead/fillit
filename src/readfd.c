/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:30:30 by cmicha            #+#    #+#             */
/*   Updated: 2019/06/06 16:47:52 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		coordtetri(t_tetri **tmp, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*tmp)->x[j] = i % 5;
			(*tmp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
	free(str);
}

t_tetri		*savetetri(char *str)
{
	int		c_tetri;
	int		add21;
	char	c;
	t_tetri *stock;
	t_tetri *tmp;

	add21 = 0;
	c = 'A';
	c_tetri = countetri(str);
	if (!(stock = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	tmp = stock;
	while (c_tetri > 0)
	{
		coordtetri(&tmp, mystrsub(str, 0 + add21, 20));
		tmp->c = c++;
		c_tetri--;
		if (c_tetri > 0)
		{
			tmp->right_next = fnew(&tmp);
			tmp = tmp->right_next;
		}
		add21 += 21;
	}
	return (stock);
}

void		truecoord(t_tetri *tmp)
{
	int i;

	i = 0;
	while (tmp != NULL)
	{
		while (tmp->y[0] != 0 && tmp->y[1] != 0 &&
				tmp->y[2] != 0 && tmp->y[3] != 0)
		{
			tmp->y[0] = tmp->y[0] - 1;
			tmp->y[1] = tmp->y[1] - 1;
			tmp->y[2] = tmp->y[2] - 1;
			tmp->y[3] = tmp->y[3] - 1;
		}
		while (tmp->x[0] != 0 && tmp->x[1] != 0 &&
				tmp->x[2] != 0 && tmp->x[3] != 0)
		{
			tmp->x[0] = tmp->x[0] - 1;
			tmp->x[1] = tmp->x[1] - 1;
			tmp->x[2] = tmp->x[2] - 1;
			tmp->x[3] = tmp->x[3] - 1;
		}
		tmp = tmp->right_next;
	}
}

char		*savestr(int fd)
{
	int		f;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	f = read(fd, &c, 1);
	if (f < 0)
		return (NULL);
	if (f == 1)
	{
		str = (char *)malloc(sizeof(char) * 600);
		while (f != '\0')
		{
			str[i] = c;
			i++;
			f = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	return (str);
}
