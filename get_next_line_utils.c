/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:17 by whan              #+#    #+#             */
/*   Updated: 2020/11/22 21:21:33 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

char	*strjoin(char *dst, char *src)
{
	char	*tmp;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(dst) + ft_strlen(src);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	while (dst && dst[i])
	{
		tmp[i] = dst[i];
		i++;
	}
	while (src[j])
		tmp[i++] = src[j++];
	tmp[i] = 0;
	if (dst)
		free(dst);
	dst = tmp;
	return dst;
}