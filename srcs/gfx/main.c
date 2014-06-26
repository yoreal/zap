/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 13:59:24 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/25 21:31:04 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "graphic.h"

static int			ft_connect(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;
	struct hostent		*host;

	sock = 0;
	if ((proto = getprotobyname("tcp")) == 0)
		ft_graphic_error("ERROR getprotobyname");
	if ((host = gethostbyname(addr)) == NULL)
		ft_graphic_error("ERROR gethostbyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		ft_graphic_error("ERROR socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	ft_memcpy(&(sin.sin_addr.s_addr), host->h_addr, host->h_length);
	if (connect(sock, (const struct sockaddr*)&sin, sizeof(sin)))
		ft_graphic_error("ERROR connect");
	return (sock);
}

static void			ft_game(t_game *game)
{
	char		*line;
	SDL_Event	event;

	while (get_next_line(game->sock, &line) > 0)
	{
		SDL_PollEvent(&event);
		if ((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
			|| (event.window.event == SDL_WINDOWEVENT_CLOSE))
			exit(0);
		ft_check_msg(game, line);
		SDL_RenderClear(game->renderer);
		draw_render(game);
		ft_show_case(game);
		ft_show_resources(game, &event, 0);
		if (event.type == SDL_MOUSEBUTTONUP)
			ft_show_resources(game, &event, 1);
		SDL_RenderPresent(game->renderer);
		free(line);
		line = NULL;
	}
}

int					main(int argc, char **argv)
{
	t_game			game;
	char			*line;
	int				nb_case;

	if (argc != 3)
		ft_graphic_usage();
	singleton(&game);
	game.sock = ft_connect(argv[1], ft_atoi(argv[2]));
	init_map(&game);
	init_time(&game);
	init_sdl(&game);
	atexit(cleanup);
	signal(SIGINT, exit);
	nb_case = game.width * game.height;
	while (nb_case-- && get_next_line(game.sock, &line))
	{
		ft_graph_bct(&game, line);
		free(line);
	}
	init_client(&game);
	init_egg(&game);
	ft_show_case(&game);
	ft_game(&game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
