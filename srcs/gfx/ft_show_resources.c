/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_resources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 10:01:05 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/25 16:22:06 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static SDL_Texture	*ft_pick_number(t_game *g, int t)
{
	if (t == 1)
		return (g->textures[14]);
	else if (t == 2)
		return (g->textures[15]);
	else if (t == 3)
		return (g->textures[16]);
	else if (t == 4)
		return (g->textures[17]);
	else if (t == 5)
		return (g->textures[18]);
	else if (t == 6)
		return (g->textures[19]);
	else if (t == 7)
		return (g->textures[20]);
	else if (t == 8)
		return (g->textures[21]);
	return (NULL);
}

static SDL_Texture	*ft_find_resource(t_game *g, int x, int y, int i)
{
	SDL_Texture		*tmp;

	tmp = NULL;
	if (i == 1)
		tmp = ft_pick_number(g, g->map[y][x].food);
	else if (i == 2)
		tmp = ft_pick_number(g, g->map[y][x].linemate);
	else if (i == 3)
		tmp = ft_pick_number(g, g->map[y][x].deraumere);
	else if (i == 4)
		tmp = ft_pick_number(g, g->map[y][x].sibur);
	else if (i == 5)
		tmp = ft_pick_number(g, g->map[y][x].mendiane);
	else if (i == 6)
		tmp = ft_pick_number(g, g->map[y][x].phiras);
	else if (i == 7)
		tmp = ft_pick_number(g, g->map[y][x].thystame);
	return (tmp);
}
/*
static void			ft_put_number(t_game *g, int y, int x, int i)
{
	SDL_Rect		src;
	SDL_Rect		dst;
	SDL_Texture		*tmp;

	tmp = NULL;
	src.x = 0;
	src.y = 0;
	src.h = LVL_SIZE_H;
	src.w = LVL_SIZE_W;
	dst.x = g->width * MAP_SIZE_W + 115;
	dst.y = (73 - LVL_SIZE_H) + ((i -  1) * 16);
	dst.h = LVL_SIZE_H;
	dst.w = LVL_SIZE_W;
	if ((tmp = ft_find_resource(g, x, y, i)) != NULL)
		SDL_RenderCopy(g->renderer, tmp, &src, &dst);
	src.x = 0;
	src.y = 0;
	src.h = MAP_SIZE_H;
	src.w = MAP_SIZE_W;
	dst.x = x * MAP_SIZE_W;
	dst.y = y * MAP_SIZE_H;
	dst.h = MAP_SIZE_H;
	dst.w = MAP_SIZE_W;
	SDL_RenderCopy(g->renderer, g->textures[24], &src, &dst);
}
*/
static void			ft_put_number(t_game *g, int y, int x, int i)
{
	SDL_Rect		src;
	SDL_Rect		dst;
	SDL_Texture		*tmp;

	tmp = NULL;
	src.x = 0;
	src.y = 0;
	src.h = LVL_SIZE_H;
	src.w = LVL_SIZE_W;
	dst.x = 500;
	dst.y = g->height * MAP_SIZE_H + (22 - LVL_SIZE_H) + ((i -  1) * 19);
	dst.h = LVL_SIZE_H;
	dst.w = LVL_SIZE_W;
	if ((tmp = ft_find_resource(g, x, y, i)) != NULL)
		SDL_RenderCopy(g->renderer, tmp, &src, &dst);
	src.x = 0;
	src.y = 0;
	src.h = MAP_SIZE_H;
	src.w = MAP_SIZE_W;
	dst.x = x * MAP_SIZE_W;
	dst.y = y * MAP_SIZE_H;
	dst.h = MAP_SIZE_H;
	dst.w = MAP_SIZE_W;
	SDL_RenderCopy(g->renderer, g->textures[24], &src, &dst);
}

void				ft_show_resources(t_game *g, SDL_Event *event, int opt)
{
	int			i;

	i = 0;
	if (opt == 1)
	{
		g->x = event->button.x / MAP_SIZE_W;
		g->y = event->button.y / MAP_SIZE_H;
	}
	if (g->x < g->width)
	{
		ft_show_case(g);
		while (++i <= 7)
			ft_put_number(g, g->y, g->x, i);
	}
}
