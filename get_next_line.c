/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkirate <mkirate@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:00:09 by mkirate           #+#    #+#             */
/*   Updated: 2025/11/02 09:52:47 by mkirate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char    *get_next_line_v1(int fd)
{
    static char data[BUFFER_SIZE];
    static int offset;
    static int read_size;
    char *storage;
    int i;

    offset = 0;
    i = offset;
    

}