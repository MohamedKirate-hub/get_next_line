/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:31:16 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/05 08:11:01 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ulimit -n

#ifndef GET_NEXT_LINE_BONUS
#define GET_NEXT_LINE_BONUS

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define ARRAY_MAX 1024

#ifndef BUFFER_SIZE

#define BUFFER_SIZE 42

#endif

char	*get_next_line_bonus(int fd);
char    *ft_strjoin(char *s1, char *s2);
char     *ft_strncpy(char *dest, char *src, size_t size);
char    *ft_strdup(char *src);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strchr(const char *s, int c);

#endif