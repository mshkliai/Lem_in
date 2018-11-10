/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:35:45 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/15 20:29:09 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/list_lem_in.h"

static char	*move_him(t_room *links, char *line, int *ants)
{
	int		ant;

	ant = 0;
	while (links->prev)
	{
		if (!links->ant && links->prev->ant)
			break ;
		links = links->prev;
	}
	if (links->prev)
	{
		links->ant = links->prev->ant;
		links->prev->ant = 0;
		line = join_free(line, "L", 0);
		line = join_free(line, ft_itoa(links->ant), 1);
		line = join_free(line, "-", 0);
		line = join_free(line, links->name, 0);
		line = join_free(line, " ", 0);
		links->in == -2 ? *ants += 1 : ant + 0;
		links->in == -2 ? links->ant = 0 : ant + 0;
	}
	if (links->in != -1)
		return (move_him(links, line, ants));
	return (line);
}

void		pass_ant(t_room **links, t_room *rooms, int fixed)
{
	t_start		a;
	int			ants2;

	a.ants = 0;
	ants2 = 0;
	while (1)
	{
		a.n = -1;
		a.line = ft_memalloc(1);
		while (links[++a.n])
		{
			a.start = links[a.n];
			while (a.start->next)
				a.start = a.start->next;
			a.line = move_him(a.start, a.line, &ants2);
			a.start = links[a.n];
			rooms->ant ? a.start->ant = ++a.ants : a.ants + 0;
			rooms->ant ? rooms->ant -= 1 : a.ants + 0;
			if (!ft_strlen(a.line) && ants2 == fixed && spacer(&a.line))
				return ;
		}
		write(1, a.line, ft_strlen(a.line) - 1);
		ft_strlen(a.line) ? ft_printf("\n") : a.ants + 0;
		ft_strdel(&a.line);
	}
}
