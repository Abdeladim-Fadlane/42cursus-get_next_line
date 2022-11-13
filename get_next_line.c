/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:04:28 by afadlane          #+#    #+#             */
/*   Updated: 2022/11/13 17:23:53 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char *get_first_line(char *d)
{
    char *ptr;
    int i = 0;
    int j =0;
    
    if(!d[0])
        return (NULL);
     while(d[i] != '\n' && d[i])
       i++;
    ptr = malloc(i + 2);
    if(!ptr)
        return NULL;
    i = 0;
    while(d[i] && d[i] != '\n')
    {
        ptr[j] = d[i];
        i++;
        j++;
    }
    if (d[i] == '\n')
        ptr[j] = '\n';
    j++;
    ptr[j] = '\0';
    return (ptr);
}

char *get_save_line(char *s)
{
    char *ptr ;
    int i = 0;
    if(!s)
        return(NULL);
    while(s[i] != '\n' && s[i] )//GET BYTE AFTER /N
        i++;
    if(s[i] == '\0')
    {
        free(s);
        return (NULL);
    }
    ptr = ft_strdup(s + i + 1);
    free(s);
    return(ptr);
}

char *get_line(int fd, char *container)
{
    char *buff;
    int i ;

    i = 1;
    buff = malloc(BUFFER_SIZE + 1);//GET ALL LENGHT OF BUFFERIZE
    buff[0] = 0;
    if(!buff)
        return NULL;
    while(!ft_strchr(container,'\n') && i != 0)
    {
        i = read(fd,buff,BUFFER_SIZE);
        if(i == -1 )
        {
            free(buff);
            free(container);
            return(NULL);
        }
        buff[i] = '\0';
        container = ft_strjoin(container,buff);
    }
    free (buff); 
    return(container);
}
    
char *get_next_line(int fd)
{
    static char  *container;
    char *buff;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    container = get_line(fd,container);
    if(!container)
        return (NULL);
    buff = get_first_line(container);
    container = get_save_line(container);
    return (buff);
}

int main()
{
    //int fd = open("test.txt" ,O_RDWR);
    printf("%s", get_next_line(0));
    // printf("\n%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));

}