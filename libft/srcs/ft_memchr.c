/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:10:52 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:56:28 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (n == 0)
		return (0);
	while (i != n - 1)
	{
		if ((unsigned char)c == (unsigned char)*str)
			return (str);
	str++;
	i++;
	}
	if ((unsigned char)c == (unsigned char)*str)
		return (str);
	return (0);
}
