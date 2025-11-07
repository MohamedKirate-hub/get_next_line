/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:00:09 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/07 08:06:19 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
    char	*result;
	
    if (!storage || !*storage)
        return (NULL);
    if (**storage == '\0')
    {
        free(*storage);
        *storage = NULL;
        return (NULL);
    }
	result = ft_strdup(*storage);
	free(*storage);
	*storage = NULL;
    return result;
}

char	*get_next_line(int fd)
{
    char *data;
	static char *storage;
    char *temp;
    int read_size;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	data = (char *)malloc(BUFFER_SIZE + 1);
    if (!data)
        return (NULL);
    if (!storage)
        storage =  ft_strdup("");
    while (!ft_strchr(storage, '\n'))
    {
        read_size = read(fd, data, BUFFER_SIZE);
        if (read_size <= 0)
            return (free(data), ft_check_read_storage(&storage));
        data[read_size] = '\0';
    	temp = ft_strjoin(storage, data);
        free(storage);
        storage = temp;
    }
    if (!storage)
        return (free(storage),storage = NULL, NULL);
    return (free(data), ft_save_storage(&storage));
}
