/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 06:14:38 by vkorniie          #+#    #+#             */
/*   Updated: 2018/08/30 16:34:23 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_H
# define V_H

# include "../libft/incs/libft.h"
# include "mlx.h"
# include <math.h>
# define WIDTH 1200
# define HEIGHT 700

typedef struct	s_w
{
	char		*line;
	int			x;
	int			y;
	int			res;
	void		*mlx_ptr;
	void		*wnd_ptr;
	char		**ar;
	double		k;
	int			first;
	int			kk;
	int			l;
}				t_w;

void			put_pixel(t_w *p, int j, int i);
int				change(int n, char c, t_w *p);
int				hadle_imput_key(int key);
void			write_players(t_w *p);

#endif
