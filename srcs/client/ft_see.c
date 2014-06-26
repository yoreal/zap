/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:27:44 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 10:42:13 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_voir(t_client *cl)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("voir", cl->cs);
	get_next_line(cl->cs, &line);
	if (cl->split != NULL)
		ft_strdel2(&cl->split);
	cl->split = ft_strsplit(line);
	free(line);
}
