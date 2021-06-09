/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text_expand_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:47:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/09 12:53:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

t_text	*ft_text_expand(t_text *text)
{
	size_t	i;
	char	*buffer;

	buffer = malloc((text->size + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
	{
		free(text->buffer);
		free(text);
		return (0);
	}
	i = 0;
	while (i < text->size - 1)
	{
		buffer[i] = text->buffer[i];
		i++;
	}
	buffer[i] = 0;
	free(text->buffer);
	text->buffer = buffer;
	return (text);
}
