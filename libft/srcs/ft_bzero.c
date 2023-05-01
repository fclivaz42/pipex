/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:15:00 by fclivaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:55:23 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned long int	x;
	char				*str;

	x = 0;
	str = s;
	while (x != len)
	{
		str[x] = 0;
		x++;
	}
}
