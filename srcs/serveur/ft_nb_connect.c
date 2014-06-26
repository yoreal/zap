/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_connect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/25 12:25:46 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "serveur.h"
#include "libft.h"

int			ft_count_nb_co(t_game *g, int i)
{
	int		nb;
	int		j;

	nb = 0;
	j = 0;
	while (j < MAX_CLI && g->cls[j].cs)
	{
		if (g->cls[j].num_team == g->cls[i].num_team)
			nb++;
		j++;
	}
	return (nb);
}

void		ft_nb_connect(t_game *g, int i)
{
	int		nb;

	nb = ft_count_nb_co(g, i);
	ft_putnbr_fd(g->max_cli[g->cls[i].num_team] - nb, g->cls[i].cs);
	ft_putchar_fd('\n', g->cls[i].cs);
}
