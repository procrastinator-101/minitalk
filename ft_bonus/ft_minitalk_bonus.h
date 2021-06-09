/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:46:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 17:07:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SLEEP_TIME			50
# define BUFFER_SIZE		1024
# define ADLER32_MOD		65521

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
}			t_text;

size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *str, int fd);
void		ft_putnendl_fd(char *str, size_t n, int fd);
void		ft_putendl_fd(char *str, int fd);

void		ft_send_byte(int pid, char byte);
void		ft_manage_client_eot(int pid, char *str);
int			ft_manage_server_eot(t_text **text, char byte);

void		ft_manage_error(int error);
void		ft_display_error_msg(int error);

int			ft_atoi_check(const char *str, int *error);
int			ft_append_character(t_text *text, char c);

uint32_t	ft_adler32(char *buffer, size_t len);

void		ft_text_harddel(t_text **text);
t_text		*ft_text_create(void);
t_text		*ft_text_expand(t_text *text);

#endif
