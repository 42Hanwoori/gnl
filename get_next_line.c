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

int		check_newline(char **draw, char **line)
{

	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	while (*draw != 0 && (*draw)[i])
	{
		i++;
		if ((*draw)[i] == 10)
		{
			tmp = (char *)malloc(sizeof(char) * (i + 1));
			while (i > ++j)
				tmp[j] = (*draw)[j];
			tmp[i] = 0;
			*line = tmp;
			write(1, *line, i);
			j = ft_strlen(*draw) - i;
			tmp = (char *)malloc(sizeof(char) * j);
			j = 0;
			while ((*draw)[++i])
				tmp[j++] = (*draw)[i];
			tmp[j] = 0;
			free(*draw);
			*draw = tmp;
			return (1);
		}
	}
	return (0);
}
void	finish(char **line)
{
	free(*line);
	*line = (char *)malloc(sizeof(char) * 1);
	(*line)[0] = 0;
}

int		get_next_line(int fd, char **line)
{
	static char	*draw;
	char		buf[BUFFER_SIZE + 1];
	int			res;

	while(1)
	{
		if (draw != 0 && check_newline(&draw, line))
			return (1);
		res = read(fd, buf, BUFFER_SIZE);
		buf[BUFFER_SIZE] = 0;
		if (res == 0 && *draw == 0)
		{
			finish(line);			
			return (0);
		}
		draw = strjoin(draw, buf);
	}
}
