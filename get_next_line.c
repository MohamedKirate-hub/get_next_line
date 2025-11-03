/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:00:09 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/03 12:47:26 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char data[5000];
    char *storage;
    int i;
    static int offset;
    static int read_size;
    int len;

    offset = 0;
    read_size = 0;
    if (offset >= read_size)
        read_size = read(fd, data, BUFFER_SIZE);
    i = offset;
    while (i < read_size && data[i] != '\n')
        i++;
    len = i;
    storage = (char *)malloc(sizeof(char) * (len + 1));
    if (!storage)
        return (NULL);
    ft_strncpy(storage, data + offset, len);
    if (i < read_size && data[i] != '\n')
    {
        storage[len] = '\n';
        storage[len + 1] = '\0';
        offset = len + 1;
        return (storage);
    }
    else
    {
        offset = len;
        char *new_storage = get_next_line(fd);
        if (!new_storage)
            return (NULL);
        char *result = ft_strjoin(storage, new_storage);
        free(storage);
        free(new_storage);
        return (result);
    }
}
