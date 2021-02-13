/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:28:24 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/12 22:49:55 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"
#include "./includes/test.h"

int		put_num(char *src, char *base, int base_len);

void	strlen_testcase()
{
	printf("\033[34m===strlen===\033[m\n");

	test_strlen("Hello,world!");
	test_strlen("");
	test_strlen("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq");

}

void	strcpy_testcase()
{
	printf("\033[34m===strcpy===\033[m\n");

	test_strcpy("Hello,world!", 13);
	test_strcpy("", 1);
	test_strcpy("qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq", 584);

}

void	strcmp_testcase()
{
	printf("\033[34m===strcmp===\033[m\n");

	char *str1 = "hello,world!";
	char *str2 = "hello,world!";
	char *str3 = "hello,world";

	test_strcmp(str1, str2);
	test_strcmp(str1, str3);
	test_strcmp(str3, str1);
	test_strcmp("asdfc", "asdfg");
	test_strcmp("", "");

}

void	strdup_testcase()
{
	char	*dest;
	char	*src = "hello,world!";

	printf("\033[34m===strdup===\033[m\n");

	printf("src:%s,%p\n",src,src);
	dest = strdup(src);
	printf("lib:%s,%p\n",dest,dest);
	dest = ft_strdup(src);
	printf("ft :%s,%p\n",dest,dest);
	test_strdup("aaaa\0aaaaaaaaaaaa\0aaaaaaaa\0aaaaaaaaaaaaa\0aaaaaaaaaaaaaaaa");
	test_strdup("\n\t\v\r\n\0");

}

void	write_testcase()
{
	int		fd;
	char	*np = NULL;

	printf("\033[34m===write===\033[m\n");

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
}

void	read_testcase()
{
	int		fd;
	char	*np = NULL;
	char	buf[3000];

	printf("\033[34m===read===\033[m\n");
	//test_read_fd(0, buf);
	fd = open("test.txt", O_WRONLY);
	test_read_fd(fd, buf);
	close(fd);
	test_read("test_read.txt", buf);
	test_read("invalid_file_path", buf);
	test_read("test_read.txt", np);

}

void	test_all()
{
	strlen_testcase();
	strcpy_testcase();
	strcmp_testcase();
	strdup_testcase();
	write_testcase();
	read_testcase();
	test_ft_list_push_front();
}

int		main(int argc, char **argv)
{
	int	num;

	if (argc > 3)
	{
		write(1,"put 0(test all) or 1(test 1 func) as args.\n", 44);
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		if (!strcmp(argv[1], "strlen"))
		{
			strlen_testcase();
			return 0;
		}
		else if (!strcmp(argv[1], "strcpy"))
		{
			strcpy_testcase();
			return 0;
		}
		else if (!strcmp(argv[1], "strcmp"))
		{
			strcmp_testcase();
			return 0;
		}
		else if (!strcmp(argv[1], "strdup"))
		{
			strdup_testcase();
			return 0;
		}
		else if (!strcmp(argv[1], "write"))
		{
			write_testcase();
			return 0;
		}
		else if (!strcmp(argv[1], "read"))
		{
			read_testcase();
			return 0;
		}
		else
		{
			write(1,"wrong arg.\n", 12);
			exit(EXIT_FAILURE);
		}
	}

	test_all();
	printf("%d\n", ft_atoi_base("   --+++11111111","01"));

	

	return 0;
}
