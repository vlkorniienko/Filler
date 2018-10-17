/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_begin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:00:32 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/08 16:00:36 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_map_size(int j, int k, t_f *p)
{
	char	s[j];
	char	s2[k];
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (p->size[i] != ' ')
		i++;
	i++;
	while (p->size[i] != ' ')
		s[l++] = p->size[i++];
	s[l] = '\0';
	l = 0;
	while (p->size[i] != ':')
		s2[l++] = p->size[i++];
	s2[l] = '\0';
	p->y = ft_atoi(s);
	p->x = ft_atoi(s2);
}

void	check_map(t_f *p)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (p->size[i] <= '0' || p->size[i] >= '9')
		i++;
	while (p->size[i++] != ' ')
		j++;
	while (p->size[i++] != ':')
		k++;
	find_map_size(j, k, p);
}

void	make_array(t_f *p)
{
	int i;

	i = 0;
	get_next_line(0, &(p->line));
	free(p->line);
	p->ar = (char **)malloc(sizeof(char *) * (p->y + 1));
	while (i < p->y)
	{
		get_next_line(0, &(p->line));
		p->ar[i] = ft_strdup(p->line + 4);
		free(p->line);
		i++;
	}
	p->ar[p->y] = NULL;
}

void	read_figure(t_f *p)
{
	char *tmp;

	get_next_line(0, &(p->line));
	tmp = p->line;
	while (*(p->line) && *(p->line) != ' ')
		(p->line)++;
	p->fy = ft_atoi(p->line);
	while (*(p->line))
		p->line++;
	while (*(p->line) != ' ')
		p->line--;
	p->fx = ft_atoi(p->line);
	free(tmp);
	write_figure(p);
}

int		main(void)
{
	t_f *p;

	p = (t_f *)malloc(sizeof(t_f));
	p->i = 0;
	get_next_line(0, &(p->line));
	p->p_n = -1;
	p->f_line = ft_strdup(p->line);
	free(p->line);
	while (get_next_line(0, &(p->line)) == 1)
	{
		p->i++;
		if (p->i == 1)
		{
			p->size = ft_strdup(p->line);
			check_map(p);
		}
		make_array(p);
		read_figure(p);
		put_numbers(p);
	}
}
