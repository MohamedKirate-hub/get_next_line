/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:09:22 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/04 14:18:42 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char    *ft_strchr(const char *s, int c)
{
        char    *str;
        size_t  i;
        size_t  str_len;

        str = (char *)s;
        str_len = ft_strlen(str);
        i = 0;
        if (c == '\0')
                return (str + str_len);
        if (str_len == 1 && str[0] != (unsigned char)c)
                return (0);
        while (str[i])
        {
                if (str[i] == (unsigned char)c)
                        break ;
                i++;
        }
        if (str_len == i)
                return (0);
        return (str + i);
}
char *ft_strdup(char *src)
{
        int     i;
        int     len;
        char    *copy;

        i = 0;
        len = ft_strlen(src);
        copy = malloc(sizeof(char) * (len + 1));
        while (src[i])
        {
                copy[i] = src[i];
                i++;
        }
        copy[i]= '\0';
        return (copy);
}
char    *ft_strjoin(char *s1, char *s2)
{
        size_t  i;
        size_t  s1_len;
        size_t  s2_len;
        char    *new_str;

        if (s1 == NULL && s2 == NULL)
                return (NULL);
        if (s1 == NULL)
                return (ft_strdup(s2));
        if (s2 == NULL)
                return (ft_strdup(s1));
        s1_len = ft_strlen(s1);
        s2_len = ft_strlen(s2);
        new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
        if (!new_str)
                return (NULL);
        ft_strncpy(new_str, s1, s1_len);
        i = 0;
        while (i < s2_len)
        {
                new_str[s1_len + i] = s2[i];
                i++;
        }
        return (new_str[s1_len + i] = '\0', new_str);
}
char    *ft_substr(char *s, unsigned int start, size_t len)
{
        size_t  i;
        size_t  st;
        size_t  s_len;
        char    *substr;

        if (s == NULL)
                return (NULL);
        st = (size_t)start;
        s_len = ft_strlen(s);
        if (len > s_len - st)
                len = s_len - st;
        substr = malloc(sizeof(char) * (len + 1));
        if (!substr)
                return (NULL);
        i = 0;
        while (i < len && st < s_len)
        {
                substr[i++] = s[st++];
        }
        substr[i] = '\0';
        return (substr);
}