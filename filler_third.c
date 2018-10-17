/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_third.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:07:35 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/13 16:07:37 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	write_coordin(t_f *p, int mi, int mj)
{
	if (!p->res || p->res >= p->distance)
	{
		p->res = p->distance;
		p->fin_x = mi;
		p->fin_y = mj;
	}
}

void	inizial(t_f *p, int *j, int *i)
{
	*j = p->st_y;
	*i = p->st_x;
	p->distance = 0;
	p->star_c = 0;
}

void	check_position(t_f *p, int mi, int mj)
{
	int	i;
	int j;

	inizial(p, &j, &i);
	while (j < p->fy)
	{
		while (i < p->fx)
		{
			if (p->fig[j][i] == '*')
			{
				if (mi + i >= p->x || mi + i < 0 || mj + j >= p->y
					|| mj + j < 0 || p->ar[mj + j][mi + i] == -1)
					return ;
				else if (p->ar[mj + j][mi + i] == -2)
					p->star_c++;
				else
					p->distance += p->ar[mj + j][mi + i];
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (p->star_c == 1)
		write_coordin(p, mi, mj);
}

void	put_first_star(t_f *p)
{
	int i;
	int j;

	j = 0;
	while (j < p->y)
	{
		i = 0;
		while (i < p->x)
		{
			check_position(p, i, j);
			i++;
		}
		j++;
	}
	ft_putnbr(p->fin_y);
	write(1, " ", 1);
	ft_putnbr(p->fin_x);
	ft_putchar('\n');
}

void	find_star(t_f *p)
{
	int j;
	int i;

	j = 0;
	while (j < p->fy)
	{
		i = 0;
		while (i < p->fx)
		{
			if (p->fig[j][i] == '*')
			{
				p->st_x = i;
				p->st_y = j;
				return ;
			}
			i++;
		}
		j++;
	}
}
