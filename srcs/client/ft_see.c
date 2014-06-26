/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:27:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 11:22:22 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void		ft_voir(t_client *cl)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("voir", cl->cs);
	get_next_line(cl->cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(cl);
	if (cl->split != NULL)
		ft_strdel2(&cl->split);
	cl->split = ft_strsplit(line, ',');
	free(line);
}
