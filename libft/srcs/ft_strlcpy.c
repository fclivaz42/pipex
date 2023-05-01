/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:20:11 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:58:44 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t sus)
{
	size_t	us;

	us = 0;
	if (sus == 0)
	{
		return (ft_strlen(src));
	}
	while (src[us] && us + 1 < sus)
	{
		dst[us] = src[us];
		us++;
	}
	dst[us] = 0;
	return (ft_strlen(src));
}
