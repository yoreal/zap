/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_enw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 17:39:04 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/25 19:46:20 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

static void	ft_put_enw(t_game *g, int i, int j, int num_cli)
{
	ft_putstr_fd("enw ", g->cls[i].cs);
	ft_putnbr_fd(j, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(num_cli, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->eggs[j].x, g->cls[i].cs);
	ft_putchar_fd(' ', g->cls[i].cs);
	ft_putnbr_fd(g->eggs[j].y, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}

void		ft_graph_enw(t_game *g, int num_cli)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < MAX_CLI)
	{
		if (g->eggs[j].active == 1 && g->eggs[j].cl.cs == g->cls[num_cli].cs
			&& g->eggs[j].x == g->cls[num_cli].x
			&& g->eggs[j].y == g->cls[num_cli].y)
			{
				while (i < MAX_CLI && g->cls[i].cs)
				{
					if (g->cls[i].graph == 1)
						ft_put_enw(g, i, j, num_cli);
					i++;
				}
				break ;
			}
		j++;
	}
}

