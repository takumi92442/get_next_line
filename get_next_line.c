/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:06:15 by takumi            #+#    #+#             */
/*   Updated: 2023/09/07 00:25:59 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *makeline(int fd,char *buff, char *save)
{
    char* buff_save;
    int judge;
    judge = 1;
    while(judge != 0)
    {
        judge = read(fd, buff, BUFFER_SIZE);
        if(judge == -1)
            return NULL;
        if(judge == 0)
            break;
        buff[judge] = '\0';
        if(save == NULL)
        {
            save = malloc(sizeof(char) * 1);
            save[0] = '\0';
        }
        buff_save = save;
        save = ft_strjoin(buff_save, buff);
        free(buff_save);
        if(ft_strchr(buff,'\n') != NULL)
            break;
    }
    return (save);
}

char * asd(char* buff)
{
    char *buffer;
    int n_number;
    char* self;
    
    n_number = 0;
    while(buff[n_number] != '\0')
    {
        if(buff[n_number] == '\n')
            break;
        n_number++;
    }
    buffer = ft_substr(buff, 0, n_number);
    self = ft_substr(buff, n_number + 1, ft_strlen(buff) - n_number);
    // free(buff);
    // buff = buffer;
    buff[n_number +1] = '\0';
    return (self);   
}


char *get_next_line(int fd)
{
    char *buff;
    char *line;
    static char *save[OPEN_MAX];

    if(fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX <= fd)
        return NULL;
    buff = malloc(sizeof(char)* (BUFFER_SIZE + 1));
    if(buff == NULL)
        return NULL;
    line = makeline(fd, buff, save[fd]);
    free(buff);
    if(line != NULL)
        save[fd] = asd(line);
    return (line);
}

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd;
    int i = 1;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd))> 0){
        printf("%d === %s", i, line);
        free(line);
        i++;
    }
    return (0);
}
