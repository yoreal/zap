/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:03:08 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 14:50:03 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"
#include "libft.h"

int		ft_expulse(t_client *c)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("expulse", c->cs);
	get_next_line(c->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(c);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}
