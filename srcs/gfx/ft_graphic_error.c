/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkorimba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 15:35:09 by rkorimba          #+#    #+#             */
/*   Updated: 2014/06/15 16:57:37 by mlemort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_graphic_usage(void)
{
	ft_putendl("Usage: ./bin/gfx <hostname> <port>");
	exit(EXIT_FAILURE);
}

void	ft_graphic_error(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}
