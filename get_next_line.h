/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:28:37 by whan              #+#    #+#             */
/*   Updated: 2020/11/19 16:14:19 by whan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*strjoin(char *dst, char *src);
int		check_newline(char **draw, char **line);
void	finish(char **line);
int		get_next_line(int fd, char **line);
