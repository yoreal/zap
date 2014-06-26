/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:18:01 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/26 10:29:48 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_avance(t_client cl)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("avance", cl.cs);
	get_next_line(cl.cs, &line);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

int		ft_droite(t_client cl)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("droite", cl.cs);
	get_next_line(cl.cs, &line);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}

int		ft_gauche(t_client cl)
{
	char	*line;

	line = NULL;
	ft_putendl_fd("gauche", cl.cs);
	get_next_line(cl.cs, &line);
	if (ft_strcmp(line, "ok") == 0)
	{
		free(line);
		return (1);
	}
	return (0);
}
