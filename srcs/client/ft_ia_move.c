/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 17:23:34 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 17:39:50 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int		ft_move_1(t_client *c, int *tab)
{
	if (tab[1] < c->y)
	{
		tab[1]++;
		return (1);
	}
	else
	{
		tab[1] = 0;
		tab[2] = 1;
		tab[0] = 1;
		return (2);
	}
	return (0);
}

int		ft_move_2(int *tab)
{
	if (tab[2] == 1)
	{
		tab[2] = 0;
		tab[1]++;
		return (1);
	}
	else if (tab[1] < 1)
	{
		tab[1]++;
		return (1);
	}
	else if (tab[1] == 1)
	{
		tab[1] = 0;
		tab[2] = 1;
		tab[0] = 2;
		return (2);
	}
	return (0);
}

int		ft_move_3(t_client *c, int *tab)
{
	if (tab[2] == 1)
	{
		tab[2] = 0;
		tab[1]++;
		return (1);
	}
	else if (tab[1] < c->y)
	{
		tab[1]++;
		return (1);
	}
	else
	{
		tab[1] = 0;
		tab[3] = 1;
		tab[0] = 3;
		return (3);
	}
	return (0);
}

int		ft_move_4(int *tab)
{
	if (tab[3] == 1)
	{
		tab[3] = 0;
		tab[1]++;
		return (1);
	}
	else if (tab[1] < 1)
	{
		tab[1]++;
		return (1);
	}
	else if (tab[1] == 1)
	{
		tab[1] = 0;
		tab[3] = 1;
		tab[0] = 4;
		return (3);
	}
	return (0);
}

int		ft_move_5(t_client *c, int *tab)
{
	if (tab[3] == 1)
	{
		tab[3] = 0;
		tab[1]++;
		return (1);
	}
	else if (tab[1] < c->y)
	{
		tab[1]++;
		return (1);
	}
	else
	{
		tab[1] = 0;
		tab[2] = 1;
		tab[0] = 1;
		return (2);
	}
	return (0);
}
