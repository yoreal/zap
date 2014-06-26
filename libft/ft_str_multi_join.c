/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multi_join.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgranet <jgranet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 21:03:02 by jgranet           #+#    #+#             */
/*   Updated: 2014/04/27 21:03:02 by jgranet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_get_len(va_list ap, int ac)
{
	int			i;
	int			len;
	va_list		cpy;

	va_copy(cpy, ap);
	i = 0;
	len = 0;
	while (i++ < ac)
		len += ft_strlen(va_arg(cpy, char*));
	len++;
	return (len);
}

static void		ft_copy(char *str, char *src, int *j)
{
	if (src)
	{
		while (*src)
		{
			str[*j] = *src;
			src++;
			(*j)++;
		}
	}
}

char			*ft_str_multi_join(int ac, ...)
{
	int			i;
	int			j;
	int			len;
	char		*str;
	va_list		ap;

	j = 0;
	i = 0;
	va_start(ap, ac);
	len = ft_get_len(ap, ac);
	str = (char*)malloc(sizeof(*str) * len);
	while (i++ < ac)
		ft_copy(str, va_arg(ap, char*), &j);
	str[j] = '\0';
	va_end(ap);
	return (str);
}
