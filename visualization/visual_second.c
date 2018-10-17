/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_second.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 10:48:44 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/30 16:31:28 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v.h"

void	write_players(t_w *p)
{
	mlx_string_put(p->mlx_ptr, p->wnd_ptr, 150, 600, 0x6699ff, "Player 1");
	mlx_string_put(p->mlx_ptr, p->wnd_ptr, 150, 650, 0xffff4d, "Player 2");
}

int		hadle_imput_key(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		change(int n, char c, t_w *p)
{
	if (c == 'x')
		return ((WIDTH / 2) + (n - p->x / 2) * p->k);
	else if (c == 'y')
		return ((HEIGHT / 2) + (n - p->y / 2) * p->k);
	else
		return (0);
}

void	put_vova(t_w *p, int j, int i)
{
	int		k;
	int		l;

	k = change(j, 'y', p);
	while (k < change(j + 1, 'y', p))
	{
		mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, change(i, 'x', p), k, 0xd9d9d9);
		k++;
	}
	l = change(i, 'x', p);
	while (l < change(i + 1, 'x', p))
	{
		mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, l, change(j, 'y', p), 0xd9d9d9);
		l++;
	}
}

void	put_pixel(t_w *p, int j, int i)
{
	if (p->ar[j][i] == '.')
	{
		put_vova(p, j, i);
		return ;
	}
	p->kk = change(j, 'y', p);
	while (p->kk < change(j + 1, 'y', p))
	{
		p->l = change(i, 'x', p);
		while (p->l < change(i + 1, 'x', p))
		{
			if (p->ar[j][i] == 'X')
				mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, p->l, p->kk, 0xffff4d);
			else if (p->ar[j][i] == 'x')
				mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, p->l, p->kk, 0xffdd99);
			else if (p->ar[j][i] == 'O')
				mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, p->l, p->kk, 0x6699ff);
			else if (p->ar[j][i] == 'o')
				mlx_pixel_put(p->mlx_ptr, p->wnd_ptr, p->l, p->kk, 0x9966ff);
			p->l++;
		}
		p->kk++;
	}
	put_vova(p, j, i);
}
