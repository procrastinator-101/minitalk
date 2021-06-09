/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 12:08:55 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 10:01:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}
