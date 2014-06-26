/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:27:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 17:51:12 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "client.h"

void		ft_voir(t_client *cl)
{
	char	*line;
	char	*tmp;

	line = NULL;
	ft_putendl_fd("voir", cl->cs);
	get_next_line(cl->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(cl);
	if (cl->split != NULL)
		ft_strdel2(&cl->split);
	tmp = ft_strsub(line, 1, ft_strlen(line) - 2);
	cl->split = ft_strsplit(tmp, ',');
	free(line);
	free(tmp);
}
