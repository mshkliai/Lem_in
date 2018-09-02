/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshkliai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 18:45:06 by mshkliai          #+#    #+#             */
/*   Updated: 2018/06/16 10:07:54 by mshkliai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_lem_in.h"

static void	count_ants(int *count)
{
	char	*line;
	int		i;

	i = 0;
	i = get_next_line(0, &line);
	!i || i == -1 ? out_error(ER) : 0;
	while (ft_strchr(line, '#') && ft_printf("%s\n", line) && spacer(&line))
	{
		!get_next_line(0, &line) ? out_error(ER) : 0;
		!ft_strcmp(line, S) || !ft_strcmp(line, E) ? out_error(ESE) : 0;
	}
	*count = ft_atoi(line);
	*count < 0 ? i += 1 : i + 0;
	if (*count <= 0 && ft_isdigit(line[i]))
		out_error(BA);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (i != (int)ft_strlen(line))
		out_error(EC);
	if (!ft_atoi(line) && !ft_isdigit(line[0]))
		out_error(IN);
	ft_printf("%s\n", line);
	ft_strdel(&line);
}

static char	*all_rooms(t_room **rooms, int i)
{
	t_start	a;
	char	*line;

	a.line = 0;
	while (get_next_line(0, &line))
	{
		i > 2 ? out_error(DC) : 0;
		if (ft_strchr(line, '-') && len_c(line, ' ') == 0)
			break ;
		ft_printf("%s\n", line);
		if (!ft_strcmp(line, S) || !ft_strcmp(line, E))
		{
			if (se(&line, rooms, &i, &a.line) && ft_printf("%s\n", line))
				a.line = ft_strdup(line);
		}
		else if (!ft_strchr(line, '#') && len_c(line, ' '))
			add_room(rooms, new_room(line), 0);
		else if (!ft_strchr(line, '#'))
			out_error(BD);
		ft_strdel(&line);
	}
	i < 2 ? out_error(NC) : 0;
	add_room(rooms, new_room(a.line), 0);
	ft_strdel(&a.line);
	return (line);
}

static void	errors(t_room *rooms, char *line, char *line2, int flag)
{
	t_room	*start;
	t_room	*end;
	int		i;

	i = 0;
	end = rooms;
	end->vis = 1;
	end->in = -1;
	while (end)
	{
		end->next ? start = end->next : 0;
		if (flag)
			if (!ft_strcmp(end->name, line) || !ft_strcmp(end->name, line2))
				i++;
		while (start)
		{
			!ft_strcmp(start->name, end->name) || (start->x == end->x &&
					start->y == end->y) ? out_error(IR) : 0;
			start = start->next;
		}
		!end->next ? end->in = -2 : end->in + 0;
		end = end->next;
	}
	flag && i < 2 ? out_error(EL) : 0;
}

static void	find_room(t_room **a_r, char *line)
{
	t_start	a;
	t_room	*end;
	t_comm	*comm2;
	t_room	*pars;

	a.start = *a_r;
	end = *a_r;
	pars = *a_r;
	a.n = 0;
	a.line = ft_strndup(line, len_to(line, '-') - 1);
	errors(pars, a.line, line + ft_strlen(a.line) + 1, 1);
	while (a.start && ft_strcmp(a.start->name, a.line))
		a.start = a.start->next;
	while (end && ft_strcmp(end->name, line + ft_strlen(a.line) + 1))
		end = end->next;
	comm2 = ft_memalloc(1);
	a.start2 = ft_memalloc(1);
	a.start2->room = end;
	a.start2->next = a.start->coms;
	a.start->coms = a.start2;
	comm2->room = a.start;
	comm2->next = end->coms;
	end->coms = comm2;
	ft_strdel(&a.line);
}

void		parsing(t_room **rooms)
{
	t_start	a;
	t_room	*b_r;
	int		i;

	i = 0;
	count_ants(&a.ants);
	!a.ants ? out_error(NA) : 0;
	a.line = all_rooms(rooms, i);
	errors(*rooms, 0, 0, 0);
	(*rooms)->ant = a.ants;
	!a.line ? ft_printf("%s", NL) : 0;
	!a.line ? exit(0) : 0;
	ft_printf("%s\n", a.line);
	b_r = *rooms;
	find_room(&b_r, a.line);
	while (spacer(&a.line) && get_next_line(0, &a.line))
	{
		!ft_strcmp(a.line, S) || !ft_strcmp(a.line, E) ? out_error(DC) : 0;
		!ft_strchr(a.line, '#') && !ft_strchr(a.line, '-') ? out_error(BL) : 0;
		ft_printf("%s\n", a.line);
		ft_strchr(a.line, '-') && !ft_strchr(a.line, '#')
			? find_room(&b_r, a.line) : 0;
	}
}
