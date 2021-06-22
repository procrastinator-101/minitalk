/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_server_eot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:34:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:44:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	ft_manage_server_eot(char byte, t_text **text)
{
	static int	pid;
	static int	shift;

	pid = (pid << 8) | (unsigned char)byte;
	shift++;
	if (shift < 4)
		return (1);
	printf("the message from the client with pid : %d ", pid);
	printf("has been received\n");
	kill(pid, SIGUSR1);
	if (*text)
		write(STDOUT_FILENO, (*text)->buffer, (*text)->end);
	write(STDOUT_FILENO, "\n", 1);
	ft_text_harddel(text);
	return (0);
}
