/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:38:41 by cmicha            #+#    #+#             */
/*   Updated: 2019/06/06 16:46:39 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*fnew(t_tetri **mass)
{
	t_tetri		*a;
	t_tetri		*new;

	a = *mass;
	new = (t_tetri*)malloc(sizeof(t_tetri));
	a->right_next = new;
	new->left_next = a;
	new->right_next = NULL;
	return (new);
}

int			validtetr(char *str, int j)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (i + j < 20 + j)
	{
		if (str[i + j] == '#')
		{
			if ((i + j + 1) < (20 + j) && str[i + j + 1] == '#')
				count++;
			if ((i + j - 1) >= (0 + j) && str[i + j - 1] == '#')
				count++;
			if ((i + j + 5) < (20 + j) && str[i + j + 5] == '#')
				count++;
			if ((i + j - 5) >= (0 + j) && str[i + j - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}

int			validchar(char *str, int j)
{
	int dash;
	int dot;
	int newline;
	int i;

	i = 0;
	dash = 0;
	dot = 0;
	newline = 0;
	while (i + j < 20 + j && str[i + j] != '\0')
	{
		if (str[i + j] == '#')
			dash++;
		if (str[i + j] == '.')
			dot++;
		if (str[i + j] == '\n')
			newline++;
		i++;
	}
	if (dash == 4 && dot == 12 && newline == 4)
		return (1);
	return (0);
}

int			check_str(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (!(validtetr(str, j) && validchar(str, j)))
			return (0);
		i = 19;
		if (str[i + j] == '\n' && str[i + j + 1] == '\0')
			return (1);
		if (str[i + j] == '\n' && str[i + j + 1] == '\n'
				&& (str[i + j + 2] == '.' || str[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}
