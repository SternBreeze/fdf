/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:59:58 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 17:06:53 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char					*ft_cut(char **s, int *eof)
{
	char					*res;
	char					*b;
	int						len;
	int						lento;

	len = ft_strlen(*s);
	lento = ft_strlento(*s, '\n');
	res = 0;
	if ((lento == 0 && (*s[0]) != '\n') && len != 0)
	{
		if (!(res = ft_strdup(*s)))
			return (NULL);
		free(*s);
		*s = NULL;
		*eof = 1;
	}
	else
	{
		if (!(res = ft_strsub(*s, 0, lento)))
			return (NULL);
		b = lento + 1 < len ? ft_strsub(*s, lento + 1, len - lento) : NULL;
		free(*s);
		*s = b;
	}
	return (res);
}

static int					init(int fd, t_list **head, t_list **node, char b)
{
	t_fd_info				*info;
	t_list					*t;

	t = *head;
	if (fd < 0 || read(fd, &b, 0) < 0)
		return (GNL_ERROR);
	while (t)
		if (INFO(t)->fd == fd)
		{
			*node = t;
			return (GNL_SUCCESS);
		}
		else
			t = t->next;
	if (!*node)
	{
		if (!(info = malloc(sizeof(t_fd_info))))
			return (GNL_ERROR);
		info->fd = fd;
		info->str = 0;
		info->eof = 0;
		ld_push_back(head, info);
		*node = l_last(*head);
	}
	return (GNL_SUCCESS);
}

static int					ft_readln(int fd, char *buff, t_list *node)
{
	ssize_t					readed;

	readed = 0;
	while ((readed = read(fd, buff, BUFF_SIZE)))
	{
		buff[readed] = '\0';
		INFO(node)->str = ft_strfjoin(&INFO(node)->str, buff);
		if (ft_strchr(buff, '\n') || readed < BUFF_SIZE)
			return (readed);
	}
	return (readed);
}

static int					remove_node(t_list **head, int fd)
{
	t_list					*t;
	t_list					*b;

	b = 0;
	t = *head;
	while (t && !(INFO(t) && INFO(t)->fd == fd))
		t = t->next;
	if (INFO(t) && INFO(t)->fd == fd && t->prev)
	{
		t = t->prev;
		b = t->next->next;
		free(t->next->data);
		ft_memdel((void**)(t->next));
		t->next = b;
		b ? b->prev = t : (void)1;
	}
	else if (INFO(t) && INFO(t)->fd == fd)
	{
		(b = (*head)->next) ?
		(b->prev = 0) : (void)1;
		free((*head)->data);
		free(*head);
		*head = b;
	}
	return (GNL_SUCCESS);
}

int							get_next_line(const int fd, char **line)
{
	static	t_list			*head;
	char					*buff;
	t_list					*node;
	int						readed;

	node = 0;
	readed = 0;
	if (!(buff = (char*)malloc(BUFF_SIZE + 1)) || !line
		|| init(fd, &head, &node, 0) == GNL_ERROR)
		return (ft_int_free((void**)&buff, GNL_ERROR));
	if (INFO(node)->eof)
		return (ft_int_free((void**)&buff, GNL_EOF) && remove_node(&head, fd));
	if (!(INFO(node)->str && ft_strchr(INFO(node)->str, '\n')))
		readed = ft_readln(fd, buff, node);
	if ((!node || !INFO(node)->str) && readed == 0)
		return (ft_int_free((void**)&buff, GNL_EOF) && remove_node(&head, fd));
	else
	{
		if (!(*line = ft_cut(&INFO(node)->str, &INFO(node)->eof)))
			return (ft_int_free((void**)&buff, GNL_ERROR));
		return (ft_int_free((void**)&buff, GNL_SUCCESS));
	}
	return (ft_int_free((void**)&buff, GNL_ERROR));
}
