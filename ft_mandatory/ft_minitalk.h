/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/22 15:20:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

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

int		ft_atoi_check(const char *str, int *error);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

t_text	*ft_text_create(void);
t_text	*ft_text_append_char(t_text *text, char c);
void	ft_text_harddel(t_text **text);
t_text	*ft_text_expand(t_text *text);

#endif
