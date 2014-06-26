/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_stone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 15:37:50 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/25 20:54:05 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static int		ft_rand_q(int *q, int i)
{
	int		res;

	res = (int)(rand() % q[i] + 1);
	q[i] -= res;
	return (res);
}

static void		ft_dispatch(t_game *g, int *q, int y)
{
	int		x;

	while (q[0] + q[1] + q[2] + q[3] + q[4] + q[5] > 0)
	{
		x = ft_rand(g->width);
		y = ft_rand(g->height);
		if (q[0] > 0)
			g->map[y][x].linemate += ft_rand_q(q, 0);
		else if (q[1] > 0)
			g->map[y][x].deraumere += ft_rand_q(q, 1);
		else if (q[2] > 0)
			g->map[y][x].sibur += ft_rand_q(q, 2);
		else if (q[3] > 0)
			g->map[y][x].phiras += ft_rand_q(q, 3);
		else if (q[4] > 0)
			g->map[y][x].mendiane += ft_rand_q(q, 4);
		else if (q[5] > 0)
			g->map[y][x].thystame += ft_rand_q(q, 5);
		ft_graph_bct(g, 0, x, y);
	}
}

void			ft_dispatch_stone(t_game *g, int cli)
{
	static int		q[6] = {0};

	if (g->cls[cli].lvl == 1 || g->cls[cli].lvl == 2)
		ft_disp_lvl_1_to_2(q, g, g->cls[cli].lvl, cli);
	else if (g->cls[cli].lvl == 4 || g->cls[cli].lvl == 3)
		ft_disp_lvl_3_to_4(q, g, g->cls[cli].lvl, cli);
	else if (g->cls[cli].lvl == 6 || g->cls[cli].lvl == 5)
		ft_disp_lvl_5_to_6(q, g, cli, g->cls[cli].lvl);
	else if (g->cls[cli].lvl == 7)
		ft_disp_lvl_7(q, g, cli);
	ft_dispatch(g, q, -1);
}
