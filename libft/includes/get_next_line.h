/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:26:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 19:28:13 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 42
# define GNL_SUCCESS 1
# define GNL_ERROR -1
# define GNL_EOF 0

# define INFO(x) ((t_fd_info *)x->data)

typedef struct		s_fd_info
{
	int				fd;
	char			*str;
	int				eof;
}					t_fd_info;
/*
**  GNL read a line ending with a newline character from a file descriptor
**
**	usage example:
**	char  *line = NULL;
**	int   fd = open("t4", O_RDONLY);
**	while((get_next_line(fd, &line)) > 0)
**	{
**		printf("%s\n",line);
**		free(line);
**	}
*/
int					get_next_line(const int fd, char **line);
#endif
