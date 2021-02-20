/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:56:06 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/20 13:21:59 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"

void	print_test_ret(bool ret)
{
	if (ret == true)
	{
		printf("\033[32m[OK]\n\033[m");
		return;
	}
	printf("\033[31m[KO]\n\033[m");
}

void	print_error_state()
{
	if (errno == 0)
		printf("\033[32m errno = %d: %s\n\033[m", errno, strerror(errno));
	else
		printf("\033[31m errno = %d: %s\n\033[m", errno, strerror(errno));
	errno = 0;
	return;
}

void	test_strlen(char *str)
{
	size_t	lib_ret;
	size_t	ft_ret;
	bool	ret;

	lib_ret = strlen(str);
	ft_ret = ft_strlen(str);
	if (lib_ret == ft_ret)
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	return ;
}

void	test_strcpy(char *str, int len)
{
	char *lib_ret;
	char *ft_ret;
	bool ret;

	lib_ret = malloc(len);
	ft_ret = malloc(len);
	lib_ret = strcpy(lib_ret, str);
	ft_ret = ft_strcpy(ft_ret, str);
	if (!strcmp(lib_ret, ft_ret))
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	free(lib_ret);
	free(ft_ret);
	return ;
}

void	test_strcmp(char *str1, char *str2)
{
	bool	ret;
	int		lib_ret;
	int		ft_ret;

	lib_ret = strcmp(str1, str2);
	ft_ret = ft_strcmp(str1, str2);
	if (lib_ret == ft_ret)
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	return;
}

void	test_strdup(char *str)
{
	char *lib_ret;
	char *ft_ret;
	bool ret;

	lib_ret = strdup(str);
	print_error_state();
	ft_ret = ft_strdup(str);
	print_error_state();
	if (!strcmp(lib_ret, ft_ret))
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	free(lib_ret);
	free(ft_ret);
	return ;
}

void	test_write(int fd, char *buf)
{
	bool	ret;
	int		lib_ret;
	int		ft_ret;

	printf("[write]\n");
	lib_ret = write(fd, buf, strlen(buf));
	print_error_state();
	printf("[ft_write]\n");
	ft_ret = ft_write(fd, buf, strlen(buf));
	print_error_state();
	printf("return value equality check...");
	if (lib_ret == ft_ret)
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	return ;
}

void	test_read_fd(int fd, char *buf)
{
	bool	ret;
	int		lib_ret;
	int		ft_ret;

	printf("[read]\n");
	lib_ret = read(fd, buf, 200);
	print_error_state();
	printf("[ft_read]\n");
	ft_ret = ft_read(fd, buf, 200);
	print_error_state();
	printf("return value equality check...");
	if (lib_ret == ft_ret)
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	return ;
}

void	test_read(char *path, char *buf)
{
	bool	ret;
	int		lib_ret;
	int		ft_ret;
	int		fd;

	fd = open(path, O_RDONLY);
	printf("[ft_read]\n");
	ft_ret = ft_read(fd, buf, 200);
	print_error_state();
	close(fd);
	fd = open(path, O_RDONLY);
	printf("[read]\n");
	lib_ret = read(fd, buf, 200);
	print_error_state();
	close(fd);
	printf("return value equality check...");
	if (lib_ret == ft_ret)
		ret = true;
	else
		ret = false;
	print_test_ret(ret);
	return ;
}
