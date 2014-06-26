/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_resources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:09:56 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 18:24:47 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

static void	ft_get_resources(char *till, int *q)
{
	int		i;
	char	**s;

	i = -1;
	s = ft_strsplit(till, ' ');
	while (s[++i])
	{
		if (ft_strcmp("linemate", s[i]) == 0)			
			q[0] += 1;
		if (ft_strcmp("deraumere", s[i]) == 0)
			q[1] += 1;
		if (ft_strcmp("sibur", s[i]) == 0)
			q[2] += 1;
		if (ft_strcmp("mendiane", s[i]) == 0)
			q[3] += 1;
		if (ft_strcmp("phiras", s[i]) == 0)
			q[4] += 1;
		if (ft_strcmp("thystame", s[i]) == 0)
			q[5] += 1;
	}
	ft_strdel2(&s);
}

static int	ft_check_till(t_client *cl, int *q)
{
	if (cl->lvl == 1 && q[0] == 1)
		return (1);
	if (cl->lvl == 2 && q[0] == 1 && q[1] == 1 && q[2] == 1)
		return (1);
	if (cl->lvl == 3 && q[0] == 2 && q[2] == 1 && q[4] == 2)
		return (1);
	if (cl->lvl == 4 && q[0] == 1 && q[1] == 1 && q[2] == 2 && q[4] == 1)
		return (1);
	if (cl->lvl == 5 && q[0] == 1 && q[1] == 2 && q[2] == 1 && q[3] == 3)
		return (1);
	if (cl->lvl == 6 && q[0] == 1 && q[1] == 2 && q[2] == 3 && q[4] == 1)
		return (1);
	if (cl->lvl == 7 && q[0] == 2 && q[1] == 2 && q[2] == 2 && q[3] == 2
		&& q[4] == 2 && q[5] == 1)
		return (1);
	return (0);
}

void		ft_check_resources(t_client *cl)
{
	static int	q[6] = {0};

	ft_memset(q, 0, 6);
	ft_voir(cl);
	ft_get_resources(cl->split[0], q);
	if (ft_check_till(cl, q) == 1)
		ft_incantation(cl);
	else
	{
		q[0] = cl->stock.linemate;
		q[1] = cl->stock.deraumere;
		q[2] = cl->stock.sibur;
		q[3] = cl->stock.mendiane;
		q[4] = cl->stock.phiras;
		q[5] = cl->stock.thystame;
		if (ft_check_till(cl, q) == 1)
		{
			ft_put_on_till(cl);
			ft_incantation(cl);
		}
	}
}
