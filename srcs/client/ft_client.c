/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:53:26 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 19:51:44 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

int				ft_move(t_client *c)
{
	static int	tab[4] = {0};

	if (tab[0] == 0)
		return (ft_move_1(c, tab));
	else if (tab[0] == 1)
		return (ft_move_2(tab));
	else if (tab[0] == 2)
		return (ft_move_3(c, tab));
	else if (tab[0] == 3)
		return (ft_move_4(tab));
	else if (tab[0] == 4)
		return (ft_move_5(c, tab));
	return (0);
}

void			ft_client(t_client *c)
{
	int		ret;
	int		i;

	i = 0;
	if (c->nb_co > 0)
		ft_fork(c);
	while (42)
	{
		i = ft_egg(c, i);
		ft_prend(c, "nourriture");
		ft_check_resources(c);
		ret = ft_move(c);
		if (ret == 1)
			ft_avance(c);
		else if (ret == 2)
			ft_droite(c);
		else if (ret == 3)
			ft_gauche(c);
		ft_connect_nbr(c);
		if (c->nb_co > 0)
			ft_fork(c);
		i++;
	}
}
