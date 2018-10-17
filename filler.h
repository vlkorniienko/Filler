/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:01:10 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/08 17:53:02 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdio.h>
# include "libft/incs/libft.h"
# include <unistd.h>
# include <stdlib.h>
# define JI p->ar[j][i]

typedef struct	s_f
{
	int			i;
	int			x;
	int			y;
	int			fy;
	int			fx;
	char		*line;
	char		*f_line;
	char		*size;
	char		**fig;
	char		**ar;
	int			pl;
	int			fd;
	char		counter;
	int			p_n;
	int			st_x;
	int			st_y;
	int			res;
	short int	fin_x;
	short int	fin_y;
	short int	star_c;
	short int	pos_c;
	int			distance;
}				t_f;

void			write_figure(t_f *p);
void			put_numbers(t_f *p);
void			find_star(t_f *p);
void			put_first_star(t_f *p);
void			write_coordin(t_f *p, int m_i, int m_j);

#endif
