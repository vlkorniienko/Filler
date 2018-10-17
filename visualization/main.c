/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 06:13:11 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/30 17:05:26 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v.h"

void	write_map(t_w *p)
{
	int i;
	int j;

	j = 0;
	mlx_clear_window(p->mlx_ptr, p->wnd_ptr);
	write_players(p);
	while (j < p->y)
	{
		i = 0;
		while (i < p->x)
		{
			put_pixel(p, j, i);
			i++;
		}
		j++;
	}
	i = 0;
	while (change(0, 'y', p) + i++ < change(p->y, 'y', p))
		mlx_pixel_put(p->mlx_ptr, p->wnd_ptr,
				change(p->x, 'x', p), change(0, 'y', p) + i, 0xffffff);
	j = 0;
	while (change(0, 'x', p) + j++ < change(p->x, 'x', p))
		mlx_pixel_put(p->mlx_ptr, p->wnd_ptr,
				change(0, 'x', p) + j, change(p->y, 'y', p), 0xffffff);
	mlx_do_sync(p->mlx_ptr);
}

void	write_coordinates(t_w *p)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	free(line);
	if (!p->first)
		p->ar = (char **)malloc(sizeof(char *) * (p->y + 1));
	while (i < p->y)
	{
		get_next_line(0, &line);
		if (!p->first)
			p->ar[i] = ft_strdup(line + 4);
		else
			p->ar[i] = ft_strcpy(p->ar[i], line + 4);
		free(line);
		i++;
	}
	p->first++;
	p->ar[p->y] = NULL;
}

void	find_mlx_size(int j, int k, t_w *p)
{
	char	s[j];
	char	s2[k];
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (p->line[i] != ' ')
		i++;
	i++;
	while (p->line[i] != ' ')
		s[l++] = p->line[i++];
	s[l] = '\0';
	l = 0;
	while (p->line[i] != ':')
		s2[l++] = p->line[i++];
	s2[l] = '\0';
	p->y = ft_atoi(s);
	p->x = ft_atoi(s2);
}

void	write_window(t_w *p)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	p->line -= 7;
	while (p->line[i] <= '0' || p->line[i] >= '9')
		i++;
	while (p->line[i++] != ' ')
		j++;
	while (p->line[i++] != ':')
		k++;
	find_mlx_size(j, k, p);
	p->res = 0;
	p->mlx_ptr = mlx_init();
	p->wnd_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, "Filler");
	write_coordinates(p);
	p->k = fmin(WIDTH / (p->y + 5), HEIGHT / (p->x + 5));
	write_map(p);
}

int		main(void)
{
	t_w		*p;

	p = (t_w *)malloc(sizeof(t_w));
	p->first = 0;
	while (get_next_line(0, &(p->line)) > 0 && !ft_strstr(p->line, "Plateau"))
		free(p->line);
	free(p->line);
	write_window(p);
	while (get_next_line(0, &(p->line)) > 0)
	{
		if (ft_strstr(p->line, "Plateau"))
		{
			write_coordinates(p);
			write_map(p);
			mlx_hook(p->wnd_ptr, 2, 5, hadle_imput_key, p);
		}
		free(p->line);
	}
	system("say game over!");
	mlx_loop(p->mlx_ptr);
}
