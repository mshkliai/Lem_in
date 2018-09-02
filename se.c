/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 18:02:40 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/15 20:44:25 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

int	se(char **line, t_room **rooms, int *k, char **check)
{
	int		i;
	char	*end;

	end = 0;
	*k += 1;
	i = 2;
	if (!ft_strcmp(*line, S))
		i = 1;
	if (!i && *check)
	{
		ft_strdel(check);
		out_error(DE);
	}
	while (spacer(line) && get_next_line(0, line) && ft_strchr(*line, '#'))
	{
		if (!ft_strcmp(*line, S) || !ft_strcmp(*line, E))
			out_error(DC);
		ft_printf("%s\n", *line);
	}
	i == 1 ? ft_printf("%s\n", *line) : i + 0;
	if (i == 1)
		add_room(rooms, new_room(*line), 1);
	else
		return (1);
	return (0);
}
