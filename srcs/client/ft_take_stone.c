/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_stone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:41:30 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 20:16:23 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

static void		ft_take_stone2(t_client *cl, char **split, int i)
{
	if (cl->stock.mendiane <= 1)
	{
		if (ft_strcmp("mendiane", split[i]) == 0)
			ft_prend(cl, "mendiane");
	}
	if (cl->stock.phiras <= 1)
	{
		if (ft_strcmp("phiras", split[i]) == 0)
			ft_prend(cl, "phiras");
	}
	if (cl->stock.thystame <= 1)
	{
		if (ft_strcmp("thystame", split[i]) == 0)
			ft_prend(cl, "thystame");
	}
}

void			ft_take_stone(t_client *cl)
{
	char	**split;
	int		i;

	i = -1;
	split = ft_strsplit(cl->split[0], ' ');
	ft_inventaire(cl);
	while (split[++i])
	{
		if (cl->stock.linemate <= 1)
		{
			if (ft_strcmp("linemate", split[i]) == 0)
				ft_prend(cl, "linemate");
		}
		if (cl->stock.deraumere <= 1)
		{
			if (ft_strcmp("deraumere", split[i]) == 0)
				ft_prend(cl, "deraumere");
		}
		if (cl->stock.sibur <= 1)
		{
			if (ft_strcmp("sibur", split[i]) == 0)
				ft_prend(cl, "sibur");
		}
		ft_take_stone2(cl, split, i);
	}
	ft_strdel2(&split);
}
