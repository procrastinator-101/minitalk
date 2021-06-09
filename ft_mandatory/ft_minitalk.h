/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 10:55:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define SLEEP_TIME	50

size_t	ft_strlen(const char *s);

void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);

int		ft_atoi_check(const char *str, int *error);
char	*ft_append_character(char *str, char c);

void	ft_transmit_string(int pid, char *str);

#endif
