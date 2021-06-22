/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:25:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:58:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_handle_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("the message has been successfully sent\n", STDOUT_FILENO);
	else
		ft_manage_error(EMTF);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;
	int	error;

	if (argc > 3)
		ft_manage_error(ETC);
	else if (argc < 3)
		ft_manage_error(EMA);
	pid = ft_atoi_check(argv[1], &error);
	if (pid < 0 || error)
		ft_manage_error(EIP);
	signal(SIGUSR1, ft_handle_signal);
	i = -1;
	while (argv[2][++i])
		ft_send_byte(pid, argv[2][i]);
	ft_manage_client_eot(pid);
	while (1)
		;
	return (0);
}
