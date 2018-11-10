/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:26:40 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/11 14:09:52 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_lem_in.h"

char	*join_free(char *line, char *line2, int flag)
{
	char	*line3;
	char	*line4;

	if (!line2 || !line)
		return (NULL);
	line3 = ft_strdup(line);
	line4 = ft_strdup(line2);
	ft_strdel(&line);
	line = ft_strjoin(line3, line4);
	if (flag == 1)
		ft_strdel(&line2);
	ft_strdel(&line3);
	ft_strdel(&line4);
	return (line);
}
