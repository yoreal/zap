/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:58:36 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 11:10:06 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void			ft_usage(void)
{
	ft_putendl("Usage: ./client -n <team> -p <port> [-h <hostname>]");
	ft_putendl("	-n nom d'equipe");
	ft_putendl("	-p port");
	ft_putendl("	-h nom de la machine par defaut c'est le localhost");
	exit(0);
}

void			ft_error(char *msg)
{
	ft_putendl(msg);
	exit(0);
}

void			ft_quit(t_client *c)
{
	ft_strdel(&c->host);
	ft_strdel(&c->team);
	if (split)
		ft_strdel2(&split);
	close(c->cs);
	exit(0);
}
