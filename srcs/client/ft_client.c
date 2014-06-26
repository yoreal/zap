/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 10:53:26 by jgranet           #+#    #+#             */
/*   Updated: 2014/06/26 13:06:54 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "libft.h"

void			ft_client(t_client *c)
{
	ft_voir(c);
	ft_inventaire(c);
	while (42)
	{
		ft_avance(c);
	}
}
