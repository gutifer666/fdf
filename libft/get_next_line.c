/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:36:07 by frgutier          #+#    #+#             */
/*   Updated: 2023/01/09 09:29:42 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*clean_accumulator(char *accumulator)
{
	char	*new_accumulator;
	int		i;
	size_t	len;

	i = 0;
	while (accumulator[i] != '\n' && accumulator[i])
		i++;
	if (accumulator[i] != '\0' && accumulator[i + 1] != '\0')
	{
		new_accumulator = (char *)malloc(ft_strlen_g(accumulator) - i);
		if (new_accumulator == NULL)
			return (NULL);
		len = ft_strlen_g(accumulator) - i - 1;
		ft_strlcpy_g(new_accumulator, accumulator + i + 1, len);
		free (accumulator);
		return (new_accumulator);
	}
	free (accumulator);
	return (NULL);
}

char	*extract_line(char *accumulator)
{
	int		i;
	char	*line;

	i = 0;
	while (accumulator[i] != '\n' && accumulator[i])
		i++;
	if (!accumulator[i])
		line = (char *)malloc(i + 1);
	else
		line = (char *)malloc(i + 2);
	if (line == NULL)
		return (NULL);
	if (!accumulator[i])
		ft_strlcpy_g(line, accumulator, i);
	else
		ft_strlcpy_g(line, accumulator, i + 1);
	return (line);
}

char	*read_file(int fd, char *accumulator)
{
	char	*buff;
	ssize_t	bytes_read;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_g(&accumulator[ft_strlen_g(accumulator) - bytes_read],
			'\n') && bytes_read)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if ((bytes_read == 0 && accumulator == NULL) || bytes_read < 0)
		{
			if (accumulator)
				free (accumulator);
			free (buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		accumulator = add_to_accumulator(accumulator, buff);
	}
	free (buff);
	return (accumulator);
}

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulator = read_file(fd, accumulator);
	if (accumulator == NULL)
		return (NULL);
	line = extract_line(accumulator);
	accumulator = clean_accumulator(accumulator);
	return (line);
}
