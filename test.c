/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:28:24 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/08 17:33:38 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libasm.h"

int main(void)
{
	size_t ret;
	char *str;


	printf("strlen-------------------------------\n");
	ret = strlen("hello,world!");
	printf("%ld\n", ret);
	ret = ft_strlen("hello,world!");
	printf("%ld\n", ret);
	printf("%ld\n", strlen(""));
	printf("%ld\n", ft_strlen(""));

	printf("\nstrcpy-------------------------------\n");
	str = malloc(20);
	printf("%s\n",strcpy(str, "hello,world!"));
	printf("%s\n",ft_strcpy(str, "hello,world!"));
	free(str);
	str = malloc(20);
	printf("%s\n",strcpy(str, ""));
	printf("%s\n",ft_strcpy(str, ""));
	free(str);

	printf("\nstrcmp-------------------------------\n");
	char *str1 = "hello,world!";
	char *str2 = "hello,world!";
	char *str3 = "hello,world";

	printf("%d\n",strcmp(str1, str1));
	printf("%d\n",ft_strcmp(str1, str1));
	printf("%d\n",strcmp(str1, str2));
	printf("%d\n",ft_strcmp(str1, str2));
	printf("%d\n",strcmp(str3, str1));
	printf("%d\n",ft_strcmp(str3, str1));
		printf("%d\n",strcmp(str1, str3));
	printf("%d\n",ft_strcmp(str1, str3));

	return 0;

}