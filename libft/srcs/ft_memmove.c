/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:22:07 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:57:20 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (dest == src)
		return (dest);
	str1 = (char *)src;
	str2 = (char *)dest;
	if (!dest && !src)
		return (dest);
	if (src < dest)
		while (n--)
			str2[n] = str1[n];
	else
		while (n--)
			*str2++ = *str1++;
	return (dest);
}
