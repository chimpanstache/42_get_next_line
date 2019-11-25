/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_previous.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:07:02 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/23 17:23:13 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
//#include "get_next_line_utils.c"

//1) Read mon fd dans mon buf, 
//1bis) En parallele strjoin line et buf
//1bis) En parallele check si \n dans mon line
//2) Si \n dans line, on strdup subbuf avec le residu de line
//2bis) On substr line pour enlever le residu
//3) Au prochain tour on add subbuf dans line avec strdup

/*static char		ft_free(char *tofree)
{
	free(tofree);
	tofree = NULL;
	return (-1);
}*/

static int 		ft_check_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	 return (-1);
}

int 			get_next_line(int fd, char **line)
{	
	char *buf;
	int nl;
	int ret;
	static char *rest;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	if (rest)
	{
		if (!(*line = ft_strdup(rest))) //pas besoin de tmp
			return (-1);				
	}
	if (!(buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0 || ft_check_nl(rest) >= 0)
	{
		buf[ret] = '\0';	
		if (!(*line = ft_strjoin(*line, buf))) //besoin de tmp
			return (-1);
		if ((nl = ft_check_nl(*line)) >= 0)
		{
			free(rest);
			if (!(rest = ft_strdup(*line + nl + 1)))
				return (-1);
			if (!(*line = ft_substr(*line, 0, nl))) ///pas besoin de tmp
				return (-1);
			free(buf);
			return (1);
		}
	}
	/*if (ret == 0)
		rest[0] = '\0';*/
	return (ret < 0 ? -1 : 0);
}

int 	main()
{
	char *line;
	int fd;
	int	ret;

	line = NULL;
	fd = open("smth.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
		printf("%d|%s\n", ret, line);
	printf("%d|%s\n", ret, line);
	return (0);
}