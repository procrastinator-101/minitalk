/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:46:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 14:02:06 by yarroubi         ###   ########.fr       */
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

# define OTR				-1
# define EOT				0
# define EMAF				1
# define ECD				2
# define ETC				3
# define EMA				4
# define EIP				5

typedef struct s_text
{
	char	*buffer;
	size_t	size;
}			t_text;

size_t		ft_strlen(const char *s);

void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);

int			ft_atoi_check(const char *str, int *error);
char		*ft_append_character(char *str, char c);

void		ft_manage_error(int error);
void		ft_display_error_msg(int error);

void		ft_transmit_string(int pid, char *str);

uint32_t	ft_adler32_bonus(char *buffer, size_t len);

void		ft_text_del(t_text *text);
t_text		*ft_text_create(void);
t_text		*ft_text_expand(t_text *text);

#endif
