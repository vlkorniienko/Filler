/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 10:25:55 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/10 10:26:00 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	change_map(t_f *p, int i, int j)
{
	if ((i + 1) < p->x && p->ar[j][i + 1] == '.')
		p->ar[j][i + 1] = JI + ((JI == -1) ? 2 : 1);
	if ((i - 1) >= 0 && p->ar[j][i - 1] == '.')
		p->ar[j][i - 1] = JI + ((JI == -1) ? 2 : 1);
	if ((j + 1) < p->y && p->ar[j + 1][i] == '.')
		p->ar[j + 1][i] = JI + ((JI == -1) ? 2 : 1);
	if ((j - 1) >= 0 && p->ar[j - 1][i] == '.')
		p->ar[j - 1][i] = JI + ((JI == -1) ? 2 : 1);
	if ((j - 1) >= 0 && (i - 1) >= 0 && p->ar[j - 1][i - 1] == '.')
		p->ar[j - 1][i - 1] = JI + ((JI == -1) ? 2 : 1);
	if ((j - 1) >= 0 && (i + 1) < p->x && p->ar[j - 1][i + 1] == '.')
		p->ar[j - 1][i + 1] = JI + ((JI == -1) ? 2 : 1);
	if ((j + 1) < p->y && (i - 1) >= 0 && p->ar[j + 1][i - 1] == '.')
		p->ar[j + 1][i - 1] = JI + ((JI == -1) ? 2 : 1);
	if ((j + 1) < p->y && (i + 1) < p->x && p->ar[j + 1][i + 1] == '.')
		p->ar[j + 1][i + 1] = JI + ((JI == -1) ? 2 : 1);
}

void	write_field_back(t_f *p)
{
	int i;
	int j;

	j = p->y - 1;
	while (j)
	{
		i = p->x - 1;
		while (i)
		{
			if (JI != '.' && JI > -2)
				change_map(p, i, j);
			i--;
		}
		j--;
	}
}

void	write_field(t_f *p)
{
	int i;
	int j;

	j = 0;
	while (j < p->y)
	{
		i = 0;
		while (i < p->x)
		{
			if (JI != '.' && JI > -2)
				change_map(p, i, j);
			i++;
		}
		j++;
	}
	write_field_back(p);
}

void	put_numbers(t_f *p)
{
	int i;
	int j;

	j = 0;
	while (j < p->y)
	{
		i = 0;
		while (i < p->x)
		{
			if (p->ar[j][i] == 'X' || p->ar[j][i] == 'x')
				p->ar[j][i] = (p->p_n == 1) ? -1 : -2;
			if (p->ar[j][i] == 'O' || p->ar[j][i] == 'o')
				p->ar[j][i] = (p->p_n == 1) ? -2 : -1;
			i++;
		}
		j++;
	}
	write_field(p);
	find_star(p);
	put_first_star(p);
}

void	write_figure(t_f *p)
{
	int i;

	i = 0;
	p->fig = (char **)malloc(sizeof(char *) * (p->fy + 1));
	p->res = 0;
	while (i < p->fy)
	{
		get_next_line(0, &(p->line));
		p->fig[i] = ft_strdup(p->line);
		free(p->line);
		i++;
	}
	if (p->p_n == -1)
	{
		while (*(p->f_line) != 'p')
			p->f_line++;
		p->f_line++;
		p->p_n = ft_atoi(p->f_line);
		free(p->f_line - 10);
	}
}
