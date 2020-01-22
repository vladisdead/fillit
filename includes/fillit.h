/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:43:14 by mriley            #+#    #+#             */
/*   Updated: 2019/06/06 16:49:58 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef	struct		s_tetri
{
	int				x[4];
	int				y[4];
	char			c;
	int				prior;
	struct s_tetri	*left_next;
	struct s_tetri	*right_next;
}					t_tetri;

t_tetri				*fnew(t_tetri **mass);
int					fillit(t_tetri *mass, int i);
int					countetri(char *str);
void				coordtetri(t_tetri **tmp, char *str);
t_tetri				*savetetri(char *str);
char				*savestr(int fd);
void				truecoord(t_tetri *tmp);
int					validtetr(char *stock, int j);
int					validchar(char *stock, int j);
int					check_str(char *stock);
void				prior(t_tetri *str);
t_tetri				*sort(t_tetri *unsort);
int					proverka3(t_tetri *mass, int x, int y, char **solve);
int					poisk(char **solve, char t);
int					pr2(char **solve, int x, int y, t_tetri *mass);
int					pr1(t_tetri *mass, int x, int y, int i);
void				gig(char **solve);
char				**solveotkat(t_tetri *mass, char **solve);
t_tetri				*koordin(t_tetri *mass, char **solve);
void				ft_delete(char **solve, int y);
char				**nee(int i);
char				**solving(t_tetri *mass1, int x, int y, char **solve);
int					minx(t_tetri *mass);
int					miny(t_tetri *mass);
int					*init(void);
void				ft_znak(int *y, int u, t_tetri *per);
int					ft_recurs(t_tetri *mass, int i, char **solve, int *y);
int					fillit(t_tetri *mass, int i);
void				deltetri1(t_tetri *alst);
char				*newstr(char *str, int i);
char				*mystrsub(char const *s, unsigned int start, size_t len);

#endif
