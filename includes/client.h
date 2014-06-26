/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:07:55 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 10:26:38 by yoreal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

typedef struct	s_stock
{
	int			nourriture;
	int			linemate;
	int			deraumere;
	int			sibur;
	int			mendiane;
	int			phiras;
	int			thystame;
}				t_stock;

typedef struct	s_client
{
	int			cs;
	int			lvl;
	int			port;
	int			nb_co;
	char		*host;
	char		*team;
	t_stock		stock;
}				t_client;

void			ft_usage(void);
void			ft_error(char *msg);

int				ft_avance(t_client cl);
int				ft_droite(t_client cl);
int				ft_gauche(t_client cl);

#endif
