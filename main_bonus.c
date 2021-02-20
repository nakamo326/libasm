/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:56:02 by ynakamot          #+#    #+#             */
/*   Updated: 2021/02/20 13:22:18 by ynakamot         ###   ########.fr       */
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

void	print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", (char *)(list->data));
		list = list->next;
	}
}

void	test_ft_list_push_front()
{
	char	*data = "test string";
	t_list list;
	t_list *start;
	t_list **begin_list;

	start = &list;
	begin_list = &start;
	printf("\033[34m===ft_list_push_front===\033[m\n");
	printf("*data             : %p\n", data);
	//printf("start             : %p\n", start);
	//printf("start->next       : %p\n", start->next);
	printf("(*b_list)         : %p\n", (*begin_list));
	printf("(*b_list)->next   : %p\n", (*begin_list)->next);
	ft_list_push_front(begin_list, (void *)data);
	printf("---after---\n");
	printf("(*b_list)(new elm): %p\n", (*begin_list));
	printf("(*b_list)->data   : %p\n", (*begin_list)->data);
	printf("(*b_list)->next   : %p\n", (*begin_list)->next);
	printf("(*b_l)->next->next: %p\n", (*begin_list)->next->next);
}

int		main()
{
	t_list	*list;
	char	*test0 = strdup("car");
	char	*test1 = strdup("bike");
	char	*test2 = strdup("donut");
	char	*test3 = strdup("apple");
	int (*cmp)() = ft_strcmp;
	void (*free_fct)(void *) = free;

	list = ft_lstnew((void *)test0);
	print_list(list);
	printf("\033[34m===ft_list_push_front===\033[m\n");
	ft_list_push_front(&list, (void *)test1);
	ft_list_push_front(&list, (void *)test2);
	ft_list_push_front(&list, (void *)test3);

	test_ft_list_push_front();
	print_list(list);

	printf("\033[34m===ft_list_size===\033[m\n");
	printf("%d\n",ft_list_size(list));

	printf("\033[34m===ft_list_sort===\033[m\n");

	ft_list_sort(&list, cmp);

	print_list(list);

	printf("\033[34m===ft_list_remove_if===\033[m\n");

	ft_list_remove_if(&list, "donut", cmp, free);
	ft_list_remove_if(&list, "apple", cmp, free);
	ft_list_remove_if(&list, "car", cmp, free);
	//ft_list_remove_if(&list, "bike", cmp, free);
	print_list(list);


	return 0;

}