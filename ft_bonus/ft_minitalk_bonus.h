/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:30:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:51:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SLEEP_TIME			100
# define BUFFER_SIZE		1024

# define EMAF				1
# define ECD				2
# define ETC				3
# define EMA				4
# define EIP				5
# define ESTF				6
# define EMTF				7

typedef struct s_text
{
	char	*buffer;
	size_t	size;
	size_t	end;
}			t_text;

void	ft_putstr_fd(char *str, int fd);
void	ft_send_byte(int pid, char byte);

void	ft_manage_error(int error);
void	ft_display_error_msg(int error);

void	ft_manage_client_eot(int serverpid);
int		ft_manage_server_eot(char byte, t_text **text);

int		ft_atoi_check(const char *str, int *error);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

t_text	*ft_text_create(void);
t_text	*ft_text_append_char(t_text *text, char c);
void	ft_text_harddel(t_text **text);
t_text	*ft_text_expand(t_text *text);

#endif
