/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:13:52 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 10:55:19 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

void			ft_fill_client(char **argv, int i, t_client *c)
{
	if (ft_strcmp(argv[i], "-n") == 0 && ft_strcmp(argv[i + 1], "GRAPHIC") != 0)
		c->team = ft_strdup(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-p") == 0)
		c->port = ft_atoi(argv[i + 1]);
	else if (ft_strcmp(argv[i], "-h") == 0)
		c->host = ft_strdup(argv[i + 1]);
	else
		ft_error("ERROR bad argument.");
}

void			ft_check_args(char **argv, t_client *c)
{
	int			i;

	i = 1;
	if (argv[i][0] != '-')
		ft_error("ERROR bad argument.");
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i + 1] && argv[i + 1][0] != '-')
		{
			ft_fill_client(argv, i, c);
			i += 2;
		}
		else
			ft_error("ERROR bad argument.");
	}
}
