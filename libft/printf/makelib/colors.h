/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:43:48 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/26 17:47:45 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H
/*
** @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
**						TEXT COLORS
**
** Example:
** ft_printf(BOLD RED BLINK"Hello, "CYN"%s!", "world"RESET)
** And another one:
** ft_printf(BOLD COLOR("32") "Bold green" RESET)
** More console codes info (ru):
** http://www.opennet.ru/base/dev/console_ctl.txt.html
*/
# define BLK			"\e[30m"
# define RED			"\e[31m"
# define GRN			"\e[32m"
# define YEL			"\e[33m"
# define BLU			"\e[34m"
# define PPL			"\e[35m"
# define CYN			"\e[36m"
# define GRY			"\e[37m"
/*
**						BACKGROUND COLORS
*/
# define BBLK			"\e[40m"
# define BRED			"\e[41m"
# define BGRN			"\e[42m"
# define BYEL			"\e[43m"
# define BBLU			"\e[44m"
# define BPPL			"\e[45m"
# define BCYN			"\e[46m"
# define BGRY			"\e[47m"
/*
**						OTHER TEXT SETTINGS
*/
# define RESET			"\e[0m"
# define BOLD 			"\e[1m"
# define BLINK			"\e[5m"
# define REVERSE		"\e[7m"
# define COLOR(X)		"\e["X"m"
#endif
