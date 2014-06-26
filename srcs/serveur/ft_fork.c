/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 16:34:22 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/25 09:12:08 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "serveur.h"
#include "libft.h"

static t_client	ft_new_egg(t_cmd *cmd, t_game *g)
{
	t_client	cl;

	cl.cs = g->cls[cmd->num_cli].cs;
	cl.lvl = 1;
	cl.graph = 0;
	cl.num_team = g->cls[cmd->num_cli].num_team;
	cl.resource.linemate = 0;
	cl.resource.deraumere = 0;
	cl.resource.sibur = 0;
	cl.resource.mendiane = 0;
	cl.resource.phiras = 0;
	cl.resource.thystame = 0;
	cl.resource.nourriture = 10;
	cl.dir = (rand() % 4) + 1;
	cl.x = g->cls[cmd->num_cli].x;
	cl.y = g->cls[cmd->num_cli].y;
	return (cl);
}

void			ft_fork(t_cmd *cmd, t_game *g)
{
	static int		i = 0;

	if (g->max_cli[g->cls[cmd->num_cli].num_team] > 13)
		g->eggs[i].active = 0;
	else
		g->eggs[i].active = 1;
	g->eggs[i].nb = i;
	g->eggs[i].x = g->cls[cmd->num_cli].x;
	g->eggs[i].y = g->cls[cmd->num_cli].y;
	g->eggs[i].cl = ft_new_egg(cmd, g);
	ft_add_node(g, ft_create_node(g, "birth", cmd->num_cli, i));
	i = (i == MAX_CLI - 1) ? 0 : i + 1;
	ft_putendl_fd("ok", cmd->fd);
	ft_graph_pfk(g, cmd->num_cli);
	ft_graph_enw(g, cmd->num_cli);
}
