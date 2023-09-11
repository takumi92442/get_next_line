/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takumi <takumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:06:15 by takumi            #+#    #+#             */
/*   Updated: 2023/09/11 22:30:05 by takumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *makeline(int fd,char *buff, char *save)
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
            if(save == NULL)
                return (NULL);   
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

static char * get_line_after_newline(char* buff)
{
    int n_number;
    char* self;
    
    n_number = 0;
    while(buff[n_number] != '\0')
    {
        if(buff[n_number] == '\n')
            break;
        n_number++;
    }
    self = ft_substr(buff, n_number + 1, ft_strlen(buff) - n_number);
    if(self == NULL)
        return (NULL);
    if(self[0] == '\0')
    {
        free(self);
        return (NULL);
    }
    return (self);   
}

static char * get_line_before_newline(char *buff)
{
    char *buffer;
    int n_number;
    
    n_number = 0;
    while(buff[n_number] != '\0')
    {
        if(buff[n_number] == '\n')
            break;
        n_number++;
    }
    buffer = ft_substr(buff, 0, n_number + 1);
    return (buffer);
}

char *get_next_line(int fd)
{
    char *buff;
    char *line;
    char *buff2;
    static char *save[OPEN_MAX];

    if(fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX <= fd)
        return NULL;
    buff = malloc(sizeof(char)* (BUFFER_SIZE + 1));
    if(buff == NULL)
        return NULL;
    line = makeline(fd, buff, save[fd]);
    free(buff);
    if(line != NULL){
        save[fd] = get_line_after_newline(line);
        buff2 = get_line_before_newline(line);
        free(line);
        return (buff2);
    }
    return (line);
}

#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <fcntl.h>
// int main()
// {
//     int fd;
//     int fd2;
//     int i = 1;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     fd2 = open("test2.txt", O_RDONLY);
//     while ((line = get_next_line(fd)) ){
//         printf("%d === %s", i, line);
//         free(line);
//         i++;
//     }
//     return (0);
// }

// int main()
// {
//     int fd;
//     int fd2;
//     int i = 1;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     fd2 = open("test2.txt", O_RDONLY);
//     while (i <= 10 ){
//         line = get_next_line(fd);
//         printf("%d === %s", i, line);
//         free(line);
//         line = get_next_line(fd2);
//         printf("%d === %s", i, line);
//         free(line);
//         i++;
//     }
//     return (0);
// }