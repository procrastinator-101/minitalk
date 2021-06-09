/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 11:45:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_handle_signal(int signal)
{
	static int	bit;
	static char	byte;
	static char	*str;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		str = ft_append_character(str, byte);
		if (!str)
		{
			ft_putstr_fd("Memory allocation failure\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		if (!byte)
		{
			ft_putendl_fd(str, STDOUT_FILENO);
			free(str);
			str = 0;
		}
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, ft_handle_signal);
	signal(SIGUSR2, ft_handle_signal);
	while (1)
		;
	return (0);
}
