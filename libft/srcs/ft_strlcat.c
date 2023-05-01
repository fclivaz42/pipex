/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:20:11 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:58:39 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t sus)
{
	size_t	among;
	size_t	us;

	us = 0;
	while (dst[us] != 0 && us < sus)
		us++;
	among = us;
	while (src[us - among] && us + 1 < sus)
	{
		dst[us] = src[us - among];
		us++;
	}
	if (among < us)
		dst[us] = 0;
	return (among + ft_strlen(src));
}
