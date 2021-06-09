/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transmit_string_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 11:45:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

static void	ft_send_signal(int pid, int signal)
{
	int	ret;

	ret = kill(pid, signal);
	if (!ret)
		return ;
	ft_putstr_fd("the sending of some signal failed\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_transmit_string(int pid, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (++j < 8)
		{
			if (str[i] & (1 << j))
				ft_send_signal(pid, SIGUSR1);
			else
				ft_send_signal(pid, SIGUSR2);
			usleep(SLEEP_TIME);
		}
	}
	j = -1;
	while (++j < 8)
	{
		ft_send_signal(pid, SIGUSR2);
		usleep(SLEEP_TIME);
	}
}
