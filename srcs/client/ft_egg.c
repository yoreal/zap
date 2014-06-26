/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_egg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 19:43:16 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 20:02:21 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"
#include "libft.h"

int		ft_egg(t_client *c, int i)
{
	char		*line;

	if (i > (int)rand() % 100 + 50)
	{
		line = NULL;
		ft_putendl_fd("fork", c->cs);
		get_next_line(c->cs, &line);
		if (ft_strcmp(line, "mort") == 0)
		{
			free(line);
			ft_quit(c);
		}
		free(line);
		i = 0;
	}
	return (i);
}
