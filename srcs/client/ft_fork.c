/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:16:43 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 19:30:43 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "client.h"
#include "libft.h"

static void	ft_get_arg(char ***arg, t_client *c)
{
	char	*port;

	port = ft_itoa(c->port);
	(*arg)[0] = ft_strdup(c->path);
	(*arg)[1] = ft_strdup("-n");
	(*arg)[2] = ft_strdup(c->team);
	(*arg)[3] = ft_strdup("-p");
	(*arg)[4] = port;
	(*arg)[5] = ft_strdup("-h");
	(*arg)[6] = ft_strdup(c->host);
	(*arg)[7] = NULL;
	free(port);
}

void		ft_fork(t_client *c)
{
	char	**arg;
	pid_t	son;
	extern char	**environ;

	ft_putstr("fork\n");
	if ((arg = (char**)malloc(sizeof(char*) * 8)) == NULL)
		ft_quit(c);
	ft_memset(arg, 0, sizeof(arg));
	ft_get_arg(&arg, c);

	int		i = 0;
	while (arg[i])
	{
		ft_putendl(arg[i]);
		i++;
	}


	son = fork();
	ft_putendl(c->path);
	if (son == 0)
	{
		ft_putendl("execve");
		execve("./bin/client", arg, environ);
		perror("ERROR EXECVE");
		ft_putendl("execve fail");
	}
//	ft_strdel2(&arg);
}
