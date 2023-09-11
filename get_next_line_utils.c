/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:19:52 by takumi            #+#    #+#             */
/*   Updated: 2023/09/07 01:06:00 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(s == NULL)
		return (i);
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	size_t			t;

	i = 0;
	t = ft_strlen(src);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t;
	char	*ptr;
	char	*buff;
    
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buff = ptr;
	t = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(sizeof(char) * t);
	if (!ptr)
		return (NULL);
    while(*s1 != '\0')
        *ptr++ = *s1++;
    while(*s2 != '\0')
        *ptr++ = *s2++;
	*ptr = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (len != 0)
	{
		s_len = ft_strlen(s);
		if (s_len < start)
			len = 0;
		if (s_len - start < len)
			len = s_len - start;
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}