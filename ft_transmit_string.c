/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmit_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:30:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 16:39:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	ft_send_signal(int pid, int signal)
{
	int	ret;

	ret = kill(pid, signal);
	if (!ret)
		return ;
	printf("the sending of some signal failed\n");
	exit(EXIT_FAILURE);
}

void	ft_transmit_string(int pid, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 8;
		while (--j >= 0)
		{
			if (str[i] & (1 << j))
				ft_send_signal(pid, SIGUSR1);
			else
				ft_send_signal(pid, SIGUSR2);
			printf("j = %d\n", j);
		}
	}
	j = 8;
	while (--j >= 0)
		ft_send_signal(pid, SIGUSR2);
}
