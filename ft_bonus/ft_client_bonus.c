/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:45:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 11:45:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	main(int argc, char **argv)
{
	int	pid;
	int	error;

	if (argc > 3)
	{
		ft_putstr_fd("Truncated characters\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (argc < 3)
	{
		ft_putstr_fd("Not enough arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi_check(argv[1], &error);
	if (pid < 0 || error)
	{
		ft_putstr_fd("Incorrect pid\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_transmit_string(pid, argv[2]);
	return (0);
}
