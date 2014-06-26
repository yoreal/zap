/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 11:10:49 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 11:16:23 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_prend(t_client cl, char *stuff)
{
	char		*line;

	line = NULL;
	ft_putstr_fd("prend ", cl.cs);
	ft_putendl_fd(stuff, cl.cs);
	get_next_line(cl.cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(cl);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int		ft_pose(t_client cl, char *stuff)
{
	char		*line;

	line = NULL;
	ft_putstr_fd("pose ", cl.cs);
	ft_putendl_fd(stuff, cl.cs);
	get_next_line(cl.cs, &line);
	if (ft_strcmp(line, "mort") == 0)
		ft_quit(cl);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}
