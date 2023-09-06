/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:19:52 by takumi            #+#    #+#             */
/*   Updated: 2023/09/06 14:50:04 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *makeline(int fd)
{
    char* buff[BUFFER_SIZE];
    read(fd, buff, BUFFER_SIZE);
    return (buff);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t;
	char	*ptr;
    
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * t);
	if (!ptr)
		return (NULL);
    while(*s1 != "\n")
        *ptr++ = *s1++;
    while(*s2 != "\n")
        *ptr++ = *s2++;
	return (ptr);
}

