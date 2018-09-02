/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:52:08 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/11 19:52:25 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

static void	room_start(t_room **rooms, t_room *room)
{
	if (rooms && room)
	{
		room->next = *rooms;
		*rooms = room;
		(*rooms)->prev = NULL;
		if ((*rooms)->next)
			(*rooms)->next->prev = (*rooms);
	}
}

void		add_room(t_room **rooms, t_room *room, int se)
{
	t_room	*end;

	if (se == 1 || !*rooms)
		room_start(rooms, room);
	else
	{
		if (!room)
			return ;
		end = *rooms;
		while (end->next)
			end = end->next;
		room->prev = end;
		end->next = room;
	}
}
