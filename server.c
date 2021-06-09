/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 16:39:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_handle_signal(int signal)
{
	static int	bit;
	static char	byte;
	static char	*str;

	signal(signal, SIGBLK
	if (signal == SIGUSR1)
		byte += (1 << bit);
	if (signal == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	bit++;
	if (bit == 8)
	{
		str = ft_append_character(str, byte);
		if (!byte)
		{
			write(1, str, ft_strlen(str));
			free(str);
			str = 0;
			bit = 0;
			byte = 0;
		}
	}
	if (signal == SIGINT)
		exit(0);
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1);
	return (0);
}
