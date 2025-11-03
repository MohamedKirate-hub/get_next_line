/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:00:22 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/03 17:48:33 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>


# define BUFFER_SIZE 42

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char     *ft_strncpy(char *dest, char *src, size_t size);
char    *ft_strdup(char *src);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strchr(const char *s, int c);

#endif