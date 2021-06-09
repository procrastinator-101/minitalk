/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_server_eot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:21:08 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 14:02:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

int	ft_manage_server_eot(t_text *text, char byte)
{
	int				error;
	static int		shift;
	static uint32_t	adler32;

	alder32 = (adler32 << 8) | byte;
	shift++;
	if (shift < 4)
		return (OTR);
	if (text)
		tmp = ft_adler32(text->buffer, text->size - 1);
	else
		tmp = 0;
	error = 0;
	if (tmp != adler32)
		error = ECD;
	shift = 0;
	adler32 = 0;
	ft_putendl_fd(text->buffer, STDOUT_FILENO);
	if (error)
		ft_display_error_msg(error);
	else
		ft_putendl_fd("Message received succesfully\n", STDOUT_FILENO);
	return (EOT);
}
