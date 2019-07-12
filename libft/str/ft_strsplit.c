/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:26:08 by jjacobso          #+#    #+#             */
/*   Updated: 2019/03/06 18:52:05 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		is_after_word(char cur, char prev, char delim)
{
	return ((cur == delim || cur == '\0') && prev != delim);
}

size_t			ft_count_words(char const *s, char c)
{
	size_t		res;

	res = 0;
	while (*s++)
		if (is_after_word(*s, *(s - 1), c))
			res++;
	return (res);
}

static void		ft_destroy(char **f)
{
	while (f && *f)
	{
		free(*f);
		*f = NULL;
		f++;
	}
	free(f);
}

char			**ft_strsplit(char const *src, char c)
{
	char		**res;
	char		**r;
	char const	*start;

	if (!src || !*src)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char*)
		* (ft_count_words(src, c) + 1))))
		return (NULL);
	r = res - 1;
	start = src;
	while (*(++src - 1) != '\0')
		if (*(src - 1) == c && *src != c)
			start = src;
		else if (is_after_word(*src, *(src - 1), c))
			if (!(*++r = ft_strsub(start, 0, src - start)))
			{
				ft_destroy(res);
				return (NULL);
			}
	*++r = 0;
	return (res);
}
