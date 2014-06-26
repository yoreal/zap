/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvl_goron.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlemort <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 14:30:03 by mlemort           #+#    #+#             */
/*   Updated: 2014/06/25 16:43:16 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

void			ft_lvl_goron(t_game *game, SDL_Rect *s, SDL_Rect *d, int i)
{
	s->w = LVL_SIZE_W;
	s->h = LVL_SIZE_H;
	d->x += ((TILES_SIZE_W - LVL_SIZE_W) / 2);
	d->y -= LVL_SIZE_H;
	d->h = LVL_SIZE_H;
	d->w = LVL_SIZE_W;
	if (game->client[i].lvl == 1)
		SDL_RenderCopy(game->renderer, game->textures[14], s, d);
	else if (game->client[i].lvl == 2)
		SDL_RenderCopy(game->renderer, game->textures[15], s, d);
	else if (game->client[i].lvl == 3)
		SDL_RenderCopy(game->renderer, game->textures[16], s, d);
	else if (game->client[i].lvl == 4)
		SDL_RenderCopy(game->renderer, game->textures[17], s, d);
	else if (game->client[i].lvl == 5)
		SDL_RenderCopy(game->renderer, game->textures[18], s, d);
	else if (game->client[i].lvl == 6)
		SDL_RenderCopy(game->renderer, game->textures[19], s, d);
	else if (game->client[i].lvl == 7)
		SDL_RenderCopy(game->renderer, game->textures[20], s, d);
	else if (game->client[i].lvl == 8)
		SDL_RenderCopy(game->renderer, game->textures[21], s, d);
}
