/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmors-um <gmors-um@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:59:58 by jjacobso          #+#    #+#             */
/*   Updated: 2018/12/25 19:55:48 by gmors-um         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char					*ft_cut(char **s)
{
	char					*res;
	char					*b;

	if (!(res = ft_strsub(*s, 0, ft_strlento(*s, '\n'))))
		return (NULL);
	if (ft_strlen(*s) - ft_strlen(res) > 1)
	{
		if (!(b = ft_strsub(*s, ft_strlento(*s, '\n') + 1,
									ft_strlen(*s) - ft_strlen(res))))
			return (ft_ptr_free((void**)&res));
		free(*s);
		*s = b;
	}
	else
	{
		free(*s);
		*s = NULL;
	}
	return (res);
}

static t_lst				*get_valid_node(t_lst **head, int fd, char b)
{
	t_lst					*node;

	if (fd < 0 || read(fd, &b, 0) < 0)
		return (NULL);
	if (!*head)
	{
		if (!(node = (t_lst*)malloc(sizeof(t_lst))))
			return (NULL);
		node->fd = fd;
		node->str = NULL;
		node->next = NULL;
		return ((*head = node));
	}
	node = *head;
	while (node)
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	node->fd = fd;
	node->str = NULL;
	node->next = *head;
	return ((*head = node));
}

static int					ft_init(int fd, t_lst **head, t_lst **node)
{
	if (BUFF_SIZE <= 0
		|| !(*node = get_valid_node(head, fd, 0)))
		return (GNL_ERROR);
	return (GNL_SUCCESS);
}

void						ft_readln(ssize_t *readed, int fd, char *buff,
																	t_lst *node)
{
	while ((*readed = read(fd, buff, BUFF_SIZE)))
	{
		buff[*readed] = '\0';
		node->str = ft_strfjoin(&node->str, buff);
		if (ft_strchr(buff, '\n') || *readed < BUFF_SIZE)
			break ;
	}
}

int							get_next_line(const int fd, char **line)
{
	static	t_lst			*head;
	char					*buff;
	t_lst					*node;
	ssize_t					readed;

	readed = 0;
	if (!(buff = (char*)malloc(BUFF_SIZE + 1)) || !line
		|| ft_init(fd, &head, &node) == GNL_ERROR)
		return (ft_int_free((void**)&buff, GNL_ERROR));
	if (node->str && ft_strchr(node->str, '\n'))
	{
		if (!(*line = ft_cut(&node->str)))
			return (ft_int_free((void**)&buff, GNL_ERROR));
		return (ft_int_free((void**)&buff, GNL_SUCCESS));
	}
	else
		ft_readln(&readed, fd, buff, node);
	if (node->str)
	{
		if (!(*line = ft_cut(&node->str)))
			return (ft_int_free((void**)&buff, GNL_ERROR));
		readed = 1;
	}
	free(buff);
	return (!node->str && readed == 0) ? (GNL_EOF) : (GNL_SUCCESS);
}
