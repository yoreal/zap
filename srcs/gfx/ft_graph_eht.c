/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_eht.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 16:03:35 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/25 09:35:36 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "libft.h"

void		ft_graph_eht(t_game *game, char *line)
{
	char	**tab;

	if ((tab = ft_strsplit(line, ' ')) == NULL)
		ft_graphic_error("parse error -> tab in ft_graph_eht");
	game->egg[ft_atoi(tab[1])].active = 0;
	ft_strdel2(&tab);
}
