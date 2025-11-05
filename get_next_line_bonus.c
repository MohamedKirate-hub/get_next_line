/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:33:12 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/05 08:11:52 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, size_t size)
{
        size_t  i;

        i = 0;
        while (i < size)
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

char	*ft_save_storage(char **storage)
{
    char *temp;
    char *result;
    int i;

    i = 0;
    if (!*storage || !storage)
        return (NULL);
    while ((*storage)[i] != '\0' && (*storage)[i] != '\n')
        i++;
    if ((*storage)[i] == '\n')
        i++;
    result = ft_substr((*storage), 0, i);
    if (!result)
        return (NULL);
    temp = ft_strdup((*storage) + i);
    free(*storage);
    (*storage) = temp;
    return (result);
}
char	*ft_check_read_storage(char **storage)
{
    if (!storage || !*storage)
        return (NULL);
    if (**storage == '\0')
    {
        free(*storage);
        *storage = NULL;
        return (NULL);
    }
    return *storage;
}

char	*get_next_line_bonus(int fd)
{
    char *data;
	static char *storage[ARRAY_MAX];
    char *temp;
    int read_size;
    
	data = (char *)malloc(BUFFER_SIZE + 1);
    if (fd < 0 || BUFFER_SIZE <= 0 || !data)
        return (NULL);
    if (!storage[fd])
        storage[fd] =  ft_strdup("");
    while (!ft_strchr(storage[fd], '\n'))
    {
        read_size = read(fd, data, BUFFER_SIZE);
        if (read_size <= 0)
            return (ft_check_read_storage(&storage[fd]));
        data[read_size] = '\0';
    	temp = ft_strjoin(storage[fd], data);
        free(storage[fd]);
        storage[fd] = temp;
    }
    if (!storage[fd])
        return (free(storage[fd]),storage[fd] = NULL, NULL);
    return (free(data), ft_save_storage(&storage[fd]));
}