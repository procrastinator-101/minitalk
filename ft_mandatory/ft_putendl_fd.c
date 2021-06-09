/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:15:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 10:16:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_putendl_fd(char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
	write(fd, "\n", 1);
}
