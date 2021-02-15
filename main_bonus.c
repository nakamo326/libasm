/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:56:02 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/15 13:13:48 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libasm.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

int		main()
{
	t_list	*list;
	t_list	*tmp;
	char	*test0 = strdup("c");
	char	*test1 = strdup("a");
	char	*test2 = strdup("d");
	char	*test3 = strdup("b");
	int (*cmp)() = ft_strcmp;
	void (*free_fct)(void *) = free;

	list = ft_lstnew((void *)test0);
	printf("\033[34m===ft_list_push_front===\033[m\n");
	ft_list_push_front(&list, (void *)test1);
	ft_list_push_front(&list, (void *)test2);
	ft_list_push_front(&list, (void *)test3);

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)(tmp->data));
		tmp = tmp->next;
	}
	printf("\033[34m===ft_list_size===\033[m\n");
	printf("%d\n",ft_list_size(list));

	printf("\033[34m===ft_list_sort===\033[m\n");

	ft_list_sort(&list, cmp);

	tmp = list;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)(tmp->data));
		tmp = tmp->next;
	}

	return 0;

}