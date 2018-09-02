/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:29:59 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/16 08:52:41 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

static void		valid_room(t_room *room, char *str)
{
	int	i;

	i = -1;
	if (str[0] == 'L')
		out_error(BN);
	i = len_to(str, ' ');
	if (len_c(str, ' ') != 2 || ft_countwords(str, ' ') != 3)
		out_error(WR);
	room->x = ft_atoi(str + i);
	!room->x && str[i] != '0' ? out_error(WRC) : 0;
	room->y = ft_atoi(str + i + len_to(str + i, ' '));
	!room->y && str[i + len_to(str + i, ' ')] != '0' ?
		out_error(WRC) : 0;
}

t_room			*new_room(char *str)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(*room))))
		return (NULL);
	room->coms = 0;
	valid_room(room, str);
	room->ant = 0;
	room->vis = 0;
	room->nice_way = 0;
	room->in = 0;
	room->name = ft_strndup(str, len_to(str, ' ') - 1);
	if (ft_strchr(room->name, '-'))
		out_error(BN);
	room->next = NULL;
	return (room);
}
