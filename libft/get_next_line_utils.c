/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 08:56:23 by frgutier          #+#    #+#             */
/*   Updated: 2022/12/20 08:55:31 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(const char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_g(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i <= ft_strlen_g(s))
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy_g(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen_g(src));
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen_g(src));
}

char	*add_to_accumulator(char *accumulator, char *buff)
{
	size_t	size;
	size_t	size_accumulator;
	size_t	size_buff;
	char	*new_accumulator;

	if (accumulator == NULL)
	{
		accumulator = (char *)malloc(1);
		if (accumulator == NULL)
			return (NULL);
		*accumulator = '\0';
	}
	size_accumulator = ft_strlen_g(accumulator);
	size_buff = ft_strlen_g(buff);
	size = size_accumulator + size_buff;
	new_accumulator = (char *)malloc(size + 1);
	if (new_accumulator == NULL)
		return (NULL);
	ft_strlcpy_g(new_accumulator, accumulator, size_accumulator);
	ft_strlcpy_g(new_accumulator + size_accumulator, buff, size_buff);
	free (accumulator);
	return (new_accumulator);
}
