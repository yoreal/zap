/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_incantation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:04:42 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 18:05:45 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "client.h"

static int	ft_check_lvl(t_client *cl, int nb)
{
	if (cl->lvl == 2 && nb >= 1)
		return (1);
	if (cl->lvl == 3 && nb >= 1)
		return (1);
	if (cl->lvl == 4 && nb >= 3)
		return (1);
	if (cl->lvl == 5 && nb >= 3)
		return (1);
	if (cl->lvl == 6 && nb >= 5)
		return (1);
	if (cl->lvl == 7 && nb >= 5)
		return (1);
	return (0);
}

static int	ft_check_cogoron(t_client *cl)
{
	int		nb_goron;
	char	**split;
	int		i;

	i = 0;
	nb_goron = 0;
	if (cl->lvl == 1)
		return (1);
	ft_voir(cl);
	split = ft_strsplit(cl->split[0], ' ');
	while (split[i])
	{
		if (ft_strcmp("goron", ft_strtrim(split[i])) == 0)
			nb_goron++;
		i++;
	}
	ft_strdel2(&split);
	if (ft_check_lvl(cl, nb_goron) == 1)
		return (1);
	return (0);
}

static void	ft_free_tool(char **line, char **line2, char ***split)
{
	if (*line != NULL)
		free(*line);
	if (*line2 != NULL)
		free(*line2);
	if (*line != NULL)
		ft_strdel2(split);
}

void		ft_incantation(t_client *cl)
{
	char	*line;
	char	*line2;
	char	**split;

	line = NULL;
	line2 = NULL;
	split = NULL;
	if (ft_check_cogoron(cl) == 1)
	{
		ft_putendl_fd("incantation", cl->cs);
		get_next_line(cl->cs, &line);
		if (ft_strcmp(line, "elevation en cours") == 0)
		{
			while (split == NULL || (ft_strcmp(split[0], "niveau") != 0)
				  || (ft_strcmp(split[1], "actuel") != 0))
			{
				if (split != NULL)
					ft_strdel2(&split);
				get_next_line(cl->cs, &line2);
				split = ft_strsplit(line2, ' ');	
			}
		}
		cl->lvl = ft_atoi(split[2]);
		ft_free_tool(&line, &line2, &split);
	}
}
