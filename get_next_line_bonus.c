/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:04:28 by afadlane          #+#    #+#             */
/*   Updated: 2022/11/14 10:53:06 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*get_first_line(char *d)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!d[0])
		return (NULL);
	while (d[i] != '\n' && d[i])
		i++;
	ptr = malloc(i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (d[i] && d[i] != '\n')
	{
		ptr[j] = d[i];
		i++;
		j++;
	}
	if (d[i] == '\n')
		ptr[j++] = '\n';
	ptr[j] = '\0';
	return (ptr);
}

char	*get_save_line(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	ptr = ft_strdup(s + i + 1);
	free(s);
	return (ptr);
}

char	*get_line(int fd, char *container)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!ft_strchr(container, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			free(container);
			return (NULL);
		}
		buff[i] = '\0';
		container = ft_strjoin(container, buff);
	}
	free(buff);
	return (container);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container[fd] = get_line(fd, container[fd]);
	if (!container[fd])
		return (NULL);
	buff = get_first_line(container[fd]);
	container[fd] = get_save_line(container[fd]);
	return (buff);
}
