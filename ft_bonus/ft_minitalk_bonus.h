/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 11:46:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 11:47:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

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
