/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:30:00 by oolkay            #+#    #+#             */
/*   Updated: 2022/10/22 14:41:56 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (0);
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	if ((unsigned char)c == '\0')
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	while (s1[++i] != '\0')
		newstr[i] = s1[i];
	while (s2[++j] != '\0')
		newstr[i + j] = s2[j];
	free(s1);
	newstr[i + j] = '\0';
	return (newstr);
}
