/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:07:02 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/20 17:30:56 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"
 
static char		ft_free(char **line)
{
	free(*line);
	return (-1);
}

static int 		ft_check_nl(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	 return (-1);
}

int 			get_next_line(int fd, char **line)
{	
	char buf[BUFFER_SIZE + 1];
	int nl;
	int ret;
	static char *subbuf;

	if (subbuf)
	{
		if (!(*line = ft_strdup(subbuf)))
			return (ft_free(line));
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if(!(*line = ft_strjoin(*line, buf)))
			return (ft_free(line));
		if ((nl = ft_check_nl(*line)) >= 0)
		{
			if (!(subbuf = ft_strdup(*line + nl + 1)))
			{
				free(subbuf);
				return (-1);
			}
			if (!(*line = ft_substr(*line, 0, nl)))
				return (ft_free(line));
			return (1);
		}
	}
	return (0);
}

int 	main()
{
	char *line;
	int fd;

	fd = open("shakeitoff", O_RDONLY);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	return (0);
}