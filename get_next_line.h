/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:00:22 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/02 09:53:04 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <fcntl.h>
#include <stdlib.h>

# define BUFFER_SIZE 412

char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
char     *ft_strncpy(char *dest, char *src, size_t size);
char    *get_next_line_v1(int fd);

#endif