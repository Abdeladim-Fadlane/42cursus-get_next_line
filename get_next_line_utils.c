/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:32:57 by afadlane          #+#    #+#             */
/*   Updated: 2022/11/15 17:58:02 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*p;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = 0;
	free(s1);
	return (p);
}

char	*ft_strchr(char *p, int c)
{
	int		i;

	if (!p)
		return (NULL);
	i = 0;
	while (p[i] != (char)c && p[i] != '\0')
		i++;
	if (p[i] == (char)c)
		return (&p[i]);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(ft_strlen(s1) + 1);
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
