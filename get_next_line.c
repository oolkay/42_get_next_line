/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:39:42 by oolkay            #+#    #+#             */
/*   Updated: 2022/10/22 17:18:02 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_read_line(char *carrier_line)
{
	char	*temp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (carrier_line[i] != '\0' && carrier_line[i] != '\n')
		i++;
	if (!carrier_line[i])
	{
		free(carrier_line);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(carrier_line) - i));
	if (!temp)
		return (NULL);
	i++;
	while (carrier_line[i + j] != '\0')
	{
		temp[j] = carrier_line[i + j];
		j++;
	}
	free(carrier_line);
	temp[j] = '\0';
	return (temp);
}

char	*get_return_line(char *carrier_line)
{
	int		i;
	char	*temp;

	i = 0;
	while (carrier_line[i] != '\n' && carrier_line[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (carrier_line[i] != '\n' && carrier_line[i] != '\0')
	{
		temp[i] = carrier_line[i];
		i++;
	}
	if (carrier_line[i] == '\n')
	{
		temp[i] = carrier_line[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*get_read_line(int fd, char *carrier_line)
{
	char	*temp;
	int	rbyte;

	rbyte = 1;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (0);
	while (!ft_strchr(carrier_line, '\n') && rbyte != 0)
	{
		rbyte = read(fd, temp, BUFFER_SIZE);
		if (rbyte == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[rbyte] = '\0';
		carrier_line = ft_strjoin(carrier_line, temp);
	}
	free(temp);
	return (carrier_line);
}

char	*get_next_line(int fd)
{
	static char	*carrier_line;
	char		*return_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	carrier_line = get_read_line(fd, carrier_line);
	if (!carrier_line)
		return (NULL);
	return_line = get_return_line(carrier_line);
	carrier_line = del_read_line(carrier_line);
	return (return_line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd = open("deneme.txt", O_RDONLY);
	char *s;
	int i = 0;
	while (i < 12)
	{
		s = get_next_line(fd);
		printf("%s\n",s);
		i++;
	}
}*/
