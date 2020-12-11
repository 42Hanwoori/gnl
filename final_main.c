/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:26:17 by whan              #+#    #+#             */
/*   Updated: 2020/11/23 11:26:22 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 20

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

int		submit_and_trim(int i, int j, char **draw, char **line)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (i + 1));
	while (i > ++j)
		tmp[j] = (*draw)[j];
	tmp[i] = 0;
	*line = tmp;
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

int		check_nl_and_exe(char **draw, char **line)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (*draw != 0 && (*draw)[i])
	{
		if ((*draw)[i] == 10)
			return (submit_and_trim(i, j, draw, line));
		i++;
	}
	return (0);
}

int	finish(char **line)
{
	*line = (char *)malloc(sizeof(char) * 1);
	(*line)[0] = 0;
	return (0);
}

int		all_read(char *draw, char **line)
{
	if (draw == 0 || *draw == 0)
		return (finish(line));
	*line = strjoin(*line, draw);
	free(draw);
	draw = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*draw;
	char		buf[BUFFER_SIZE + 1];
	int			res;
	int			i;

	if(BUFFER_SIZE <= 0)
		return(-1);
	*line = 0;
	while(1)
	{
		if (draw != 0 && check_nl_and_exe(&draw, line))
			return (1);
		i = -1;
		while (buf[++i])
			buf[i] = 0;
		res = read(fd, buf, BUFFER_SIZE);
		if (res < 0)
			return (-1);
		buf[res] = 0;
		if (res == 0)
			return(all_read(draw, line));
		draw = strjoin(draw, buf);
	}
}
			// 
			//if (draw == 0 || *draw == 0)
			//	return (finish(line));;
			//else if (!strnl(draw))
			// 	*line = strjoin(*line, draw);
			// 	*draw = 0;
			// 	return (0);
			// }
// int		main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		a;

// 	line = 0;
// 	fd = open("c:/0gnl/war_machine/tests/64_line", O_RDONLY);
// 	while ((a = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}///////////////////////
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
// 	return 0;
// }

int		main(void)
{
    int     fd;
    int     ret;
    char    *line;

    fd = open("c:/0gnl/war_machine/tests/line.txt", O_RDONLY);
    if (fd == -1)
        return (-1);
    ret = 1;
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        if (1)
            printf("%s\n", line);
        free(line);
    }
    get_next_line(fd, &line);
    if (1)
        printf("%s\n", line);
    free(line);
    close(fd);
}