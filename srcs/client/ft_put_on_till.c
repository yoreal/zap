/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_on_till.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 17:10:55 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 17:24:49 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		ft_put_on_till4(t_client *cl)
{
	if (cl->lvl == 7)
	{
		cl->stock.linemate -= 2;
		ft_pose(cl, "linemate");
		cl->stock.deraumere -= 2;
		ft_pose(cl, "deraumere");
		cl->stock.sibur -= 2;
		ft_pose(cl, "sibur");
		cl->stock.mendiane  -= 2;
		ft_pose(cl, "mendiane");
		cl->stock.phiras -= 2;
		ft_pose(cl, "phiras");
		cl->stock.thystame--;
		ft_pose(cl, "thystame");
	}
}

static void		ft_put_on_till3(t_client *cl)
{
	if (cl->lvl == 6)
	{
		cl->stock.linemate--;
		ft_pose(cl, "linemate");
		cl->stock.deraumere -= 2;
		ft_pose(cl, "deraumere");
		cl->stock.sibur -= 3;
		ft_pose(cl, "sibur");
		cl->stock.phiras--;
		ft_pose(cl, "phiras");
	}
	else
		ft_put_on_till4(cl);
}

static void		ft_put_on_till2(t_client *cl)
{
	if (cl->lvl == 4)
	{
		cl->stock.linemate--;
		ft_pose(cl, "linemate");
		cl->stock.deraumere--;
		ft_pose(cl, "deraumere");
		cl->stock.sibur -= 2;
		ft_pose(cl, "sibur");
		cl->stock.phiras--;
		ft_pose(cl, "phiras");
	}
	else if (cl->lvl == 5)
	{
		cl->stock.linemate--;
		ft_pose(cl, "linemate");
		cl->stock.deraumere -= 2;
		ft_pose(cl, "deraumere");
		cl->stock.sibur--;
		ft_pose(cl, "sibur");
		cl->stock.mendiane -= 3;
		ft_pose(cl, "mendiane");
	}
	else
		ft_put_on_till3(cl);
}

void		ft_put_on_till(t_client *cl)
{
	if (cl->lvl == 1)
	{
		cl->stock.linemate--;
		ft_pose(cl, "linemate");
	}
	else if (cl->lvl == 2)
	{
		cl->stock.linemate--;
		ft_pose(cl, "linemate");
		cl->stock.deraumere--;
		ft_pose(cl, "deraumere");
		cl->stock.sibur--;
		ft_pose(cl, "sibur");
	}
	else if (cl->lvl == 3)
	{
		cl->stock.linemate -= 2;
		ft_pose(cl, "linemate");
		cl->stock.deraumere--;
		ft_pose(cl, "deraumere");
		cl->stock.mendiane -= 2;
		ft_pose(cl, "mendiane");
	}
	else
		ft_put_on_till2(cl);
}
