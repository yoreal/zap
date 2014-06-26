/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 09:50:50 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 09:57:43 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"

void		ft_usage(char *argv)
{
	
}

int			main(int argc, char **argv)
{
	t_game		g;
	char		*line;
	int			i;

	signal(SIGINT, exit);
	if (argc == 1)
		ft_usage(argv[0]);
}
