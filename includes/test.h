/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:48:52 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/12 16:37:56 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

void	print_test_ret(bool ret);
void	print_error_state();
void	test_strlen(char *str);
void	test_strcpy(char *str, int len);
void	test_strcmp(char *str1, char *str2);
void	test_strdup(char *str);
void	test_write(int fd, char *buf);
void	test_read_fd(int fd, char *buf);
void	test_read(char *path, char *buf);
void	test_ft_list_push_front();


#endif