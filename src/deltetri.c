/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:30:47 by cmicha            #+#    #+#             */
/*   Updated: 2019/06/06 16:50:08 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			countetri(char *str)
{
	int		i;
	int		result;

	result = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			result++;
		i++;
	}
	return (result / 4);
}

void		deltetri1(t_tetri *alst)
{
	t_tetri *a;

	while (alst != NULL)
	{
		a = alst;
		alst = alst->right_next;
		free(a);
	}
}

char		*mystrsub(char const *s, unsigned int start, size_t len)
{
	char			*substr;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (s)
		if (substr)
		{
			ft_memcpy(substr, (s + start), len);
			substr[len] = 0;
			return (substr);
		}
	return (0);
}
