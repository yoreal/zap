/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_broadcast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:10:18 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 14:14:29 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "client.h"
#include "libft.h"

void		ft_broadcast(t_client *c, char *msg)
{
	char	*line;

	line = NULL;
	ft_putstr_fd("broadcast ", c->cs);
	ft_putendl_fd(msg, c->cs);
	get_next_line(c->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(c);
	free(line);
}
