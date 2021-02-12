/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:55:31 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/12 15:41:07 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *src);

void			ft_list_push_front(t_list **begin_list, void *data);

#endif