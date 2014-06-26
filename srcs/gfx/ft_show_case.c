/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoreal <yoreal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 15:48:26 by yoreal            #+#    #+#             */
/*   Updated: 2014/06/25 16:21:00 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

/*
static void	ft_fill_empty(t_game *g)
{
	SDL_Rect	src;
	SDL_Rect	dst;

	src.x = 0;
	src.y = 0;
	src.h = MAP_SIZE_H;
	src.w = MAP_SIZE_W;
	dst.x = g->width * MAP_SIZE_W;
	dst.y = 360;
	dst.h = (g->height * MAP_SIZE_H) - 360;
	dst.w = 240;
	SDL_RenderCopy(g->renderer, g->textures[23], &src, &dst);
}

void		ft_show_case(t_game *g)
{
	SDL_Rect	src;
	SDL_Rect	dst;

	src.x = 0;
	src.y = 0;
	src.h = 360;
	src.w = 240;
	dst.x = g->width * MAP_SIZE_W;
	dst.y = 0;
	dst.h = 360;
	dst.w = 240;
	SDL_RenderCopy(g->renderer, g->textures[22], &src, &dst);
	ft_fill_empty(g);
}
*/

static void	ft_fill_empty(t_game *g)
{
	SDL_Rect	src;
	SDL_Rect	dst;

	src.x = 0;
	src.y = 0;
	src.h = MAP_SIZE_H;
	src.w = MAP_SIZE_W;
	dst.x = 576;
	dst.y = g->height * MAP_SIZE_H;
	dst.h = 150;
	dst.w = (g->width * MAP_SIZE_W) - 576;
	SDL_RenderCopy(g->renderer, g->textures[23], &src, &dst);
}

void		ft_show_case(t_game *g)
{
	SDL_Rect	src;
	SDL_Rect	dst;

	src.x = 0;
	src.y = 0;
	src.h = 240;
	src.w = 576;
	dst.x = 0;
	dst.y = g->height * MAP_SIZE_H;
	dst.h = 150;
	dst.w = 576;
	SDL_RenderCopy(g->renderer, g->textures[22], &src, &dst);
	ft_fill_empty(g);
}
