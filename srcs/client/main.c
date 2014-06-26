/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:50:50 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 10:49:09 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <stdlib.h>
#include "client.h"
#include "libft.h"

void		ft_create_serveur(t_client *c)
{
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct hostent		*host;

	if ((proto = getprotobyname("tcp")) == 0)
		ft_error("ERROR getprotobyname");
	if ((host = gethostbyname(c->host)) == NULL)
		ft_error("ERROR gethostbyname");
	if ((c->cs = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_error("ERROR socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(c->port);
	ft_memcpy(&(sin.sin_addr.s_addr), host->h_addr, host->h_length);
	if (connect(c->cs, (const struct sockaddr*)&sin, sizeof(sin)))
		ft_error("ERROR connect");
}

void		ft_init_cli(t_client *c)
{
	c->cs = 0;
	c->lvl = 1;
	c->stock.nourriture = 0;
	c->stock.linemate = 0;
	c->stock.deraumere = 0;
	c->stock.sibur = 0;
	c->stock.mendiane = 0;
	c->stock.phiras = 0;
	c->stock.thystame = 0;
	c->split = NULL;
}

int			main(int argc, char **argv)
{
	t_client	c;
	char		*line;
	int			i;

	signal(SIGINT, exit);
	if (argc == 1)
		ft_usage();
	ft_check_args(argv, &c);
	ft_create_serveur(&c);
	return (0);
}
