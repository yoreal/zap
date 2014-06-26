/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_ebo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 15:09:21 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/25 19:26:47 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serveur.h"
#include "libft.h"

void		ft_graph_ebo(t_game *g, int nb_egg)
{
	int		i;

	i = -1;
	while (++i < MAX_CLI && g->cls[i].cs)
	{
		if (g->cls[i].graph == 1)
		{
			ft_putstr_fd("ebo ", g->cls[i].cs);
			ft_putnbr_fd(nb_egg, g->cls[i].cs);
			ft_putchar_fd('\n', g->cls[i].cs);
		}
	}
}
