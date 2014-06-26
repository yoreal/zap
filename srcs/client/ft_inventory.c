/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inventory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:43:54 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 11:32:02 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "client.h"

static int		ft_get_quantity(char *ressource)
{
	char	**split;
	int		res;

	split = ft_strsplit(ressource, ' ');
	res = ft_atoi(ft_strtrim(split[1]));
	ft_strdel2(&split);
	return (res);
}

static void		ft_save_inv(t_client *cl, char **split)
{
	cl->nourriture = ft_get_quantity(split[0]);
	cl->linemate = ft_get_quantity(split[1]);
	cl->deraumere = ft_get_quantity(split[2]);
	cl->sibur = ft_get_quantity(split[3]);
	cl->mendiane = ft_get_quantity(split[4]);
	cl->phiras = ft_get_quantity(split[5]);
	cl->thystame = ft_get_quantity(split[6]);
}

void			ft_inventaire(t_client *cl)
{
	char	**split;
	char	*line;

	split = NULL;
	line = NULL;
	ft_putendl_fd("inventaire", cl->cs);
    get_next_line(cl->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(cl);
	split = ft_strsplit(line, ',');
	ft_save_inv(cl, split);
	free(line);
	ft_strdel2(&split);
}
