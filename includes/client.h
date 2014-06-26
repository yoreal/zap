/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:07:55 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 11:30:09 by yoreal           ###   ########.fr       */
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
	char		**split;
	t_stock		stock;
}				t_client;

void			ft_usage(void);
void			ft_error(char *msg);
void			ft_quit(t_client *c);
void			ft_check_args(char **argv, t_client *c);
void			ft_client(t_client *c);

void			ft_voir(t_client *cl);
void			ft_inventaire(t_client *cl);
int				ft_avance(t_client *cl);
int				ft_droite(t_client *cl);
int				ft_gauche(t_client *cl);
int				ft_prend(t_client *cl, char *stuff);
int				ft_pose(t_client *cl, char *stuff);



#endif
