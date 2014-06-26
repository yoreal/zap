/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:53:26 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 17:13:58 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"


//return 1, 2, ou 3 pour avance, droite, gauche
int			ft_move(t_client *c)
{	
	static int	tab[4] = {0};

/*
	ft_putstr("tab[0] = ");
	ft_putnbr(tab[0]);
	ft_putstr(" tab[1] = ");
	ft_putnbr(tab[1]);
	ft_putstr(" tab[2] = ");
	ft_putnbr(tab[2]);
	ft_putstr(" tab[3] = ");
	ft_putnbr(tab[3]);
	ft_putchar('\n');
*/
	
	/*	tab[0] = 0; //mode
	tab[1] = 0; //avance
	tab[2] = 0; //droite
	tab[3] = 0; //gauche
*/	if (tab[0] == 0)
	{
		if (tab[1] < c->y)
		{
			ft_putendl("titi");
			tab[1]++;
			return (1);
		}
		else
		{
			ft_putendl("lol");
			tab[1] = 0;
			tab[2] = 1;
			tab[0] = 1;
			return (2);
		}
	}
	else if (tab[0] == 1)
	{
		if (tab[2] == 1)
		{
			tab[2] = 0;
			tab[1]++;
			return (1);
		}
		else if (tab[1] < 1)
		{
			tab[1]++;
			return (1);
		}
		else if (tab[1] == 1)
		{
			tab[1] = 0;
			tab[2] = 1;
			tab[0] = 2;
			return (2);
		}
	}
	else if (tab[0] == 2)
	{
		if (tab[2] == 1)
		{
			tab[2] = 0;
			tab[1]++;
			return (1);
		}
		else if (tab[1] < c->y)
		{
			tab[1]++;
			return (1);
		}
		else
		{
			tab[1] = 0;
			tab[3] = 1;
			tab[0] = 3;
			return (3);
		}
	}
	else if (tab[0] == 3)
	{
		if (tab[3] == 1)
		{
			tab[3] = 0;
			tab[1]++;
			return (1);
		}
		else if (tab[1] < 1)
		{
			tab[1]++;
			return (1);
		}
		else if (tab[1] == 1)
		{
			tab[1] = 0;
			tab[3] = 1;
			tab[0] = 4;
			return (3);
		}
	}
	else if (tab[0] == 4)
	{
		if (tab[3] == 1)
		{
			tab[3] = 0;
			tab[1]++;
			return (1);
		}
		else if (tab[1] < c->y)
		{
			tab[1]++;
			return (1);
		}
		else
		{
			tab[1] = 0;
			tab[2] = 1;
			tab[0] = 1;
			return (2);
		}
	}
	return (0);
}

void			ft_client(t_client *c)
{
//	ft_putendl("fork");
//	ft_fork(c);
//	ft_putendl("fin fork");
//	ft_voir(c);
//	ft_inventaire(c);
	int		ret;

//	if (c->nb_co > 0)
//		ft_fork(c);
	while (42)
	{
		ret = ft_move(c);
		if (ret == 1)
		{
			ft_putnbr(1);
			ft_putchar('\n');
			ft_avance(c);
		}
		if (ret == 2)
		{
			ft_putnbr(2);
			ft_putchar('\n');
			ft_droite(c);
		}
		if (ret == 3)
		{
			ft_putnbr(3);
			ft_putchar('\n');
			ft_gauche(c);
		}

//		ft_putnbr(ft_move(c));
//		ft_putchar('\n');
	}
}
