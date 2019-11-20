/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:45:29 by ehafidi           #+#    #+#             */
/*   Updated: 2019/11/19 15:14:54 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

void			    *ft_memcpy(void *dest, const void *src, size_t n);
size_t			    ft_strlen(const char *str);
char			    *ft_substr(char const *s, unsigned int start, size_t len);
char			    *ft_strjoin(char const *s1, char const *s2);
char			    *ft_strdup(const char *s);
int 	            get_next_line(int fd, char **line);

#endif