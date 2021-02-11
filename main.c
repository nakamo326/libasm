/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:28:24 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/11 15:14:17 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

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

	printf("[ft_write]\n");
	ft_ret = ft_write(fd, buf, 20);
	print_error_state();
	printf("[write]\n");
	lib_ret = write(fd, buf, 20);
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

	printf("[ft_read]\n");
	ft_ret = ft_read(fd, buf, 200);
	print_error_state();
	printf("[read]\n");
	lib_ret = read(fd, buf, 200);
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

int		main(void)
{
	size_t ret;
	char *str;
	char *dest;
	char *np = NULL;

	printf("\033[34m===strlen===\033[m\n");
	test_strlen("Hello,world!");
	test_strlen("");
	test_strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");

	printf("\033[34m===strcpy===\033[m\n");
	test_strcpy("Hello,world!", 13);
	test_strcpy("", 1);
	test_strcpy("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq", 584);

	printf("\033[34m===strcmp===\033[m\n");
	char *str1 = "hello,world!";
	char *str2 = "hello,world!";
	char *str3 = "hello,world";

	test_strcmp(str1, str2);
	test_strcmp(str1, str3);
	test_strcmp(str3, str1);
	test_strcmp("asdfc", "asdfg");
	test_strcmp("", "");

	printf("\033[34m===strdup===\033[m\n");

	printf("src:%s,%p\n",str1,str1);
	dest = strdup(str1);
	printf("lib:%s,%p\n",dest,dest);
	dest = ft_strdup(str1);
	printf("ft :%s,%p\n",dest,dest);
	test_strdup("aaaa\0aaaaaaaaaaaa\0aaaaaaaa\0aaaaaaaaaaaaa\0aaaaaaaaaaaaaaaa");
	test_strdup("\n\t\v\r\n\0");

	printf("\033[34m===write===\033[m\n");
	int fd;

	test_write(0, "Test string.\n");
	fd = open("test.txt", O_RDONLY);
	test_write(fd, "Test string.\n");
	close(fd);
	fd = open("test.txt", O_WRONLY);
	test_write(fd, "Test string.\n");
	close(fd);
	fd = 42;
	test_write(fd, "Test string.\n");
	fd = open("test.txt", O_RDWR);
	test_write(fd, np);
	close(fd);

	printf("\033[34m===read===\033[m\n");
	char buf[3000];
	//test_read_fd(0, buf);
	fd = open("test.txt", O_WRONLY);
	test_read_fd(fd, buf);
	close(fd);
	test_read("test_read.txt", buf);
	test_read("invalid_file_path", buf);
	test_read("test_read.txt", np);

	return 0;

}