/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:21:36 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/19 16:22:30 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

int 	main()
{
	char *line;
	int fd;

	fd = open("smth.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return (0);
}
