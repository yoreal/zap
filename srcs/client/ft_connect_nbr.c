/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:07:28 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 19:53:16 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"
#include "libft.h"

void		ft_connect_nbr(t_client *c)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("connect_nbr", c->cs);
	get_next_line(c->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(c);
	c->nb_co = ft_atoi(line);
	free(line);
}
