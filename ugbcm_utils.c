/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugbcm_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaducew <lgaducew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 12:56:26 by rtournet          #+#    #+#             */
/*   Updated: 2021/11/11 22:18:16 by lgaducew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ugbcm.h"

t_lst	*lstnew(uintptr_t ptr)
{
	t_lst	*lst;

	lst = NULL;
	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->to_free = ptr;
	lst->lst_next = NULL;
	return (lst);
}

t_lst	*lstnew_node(t_ugbcm *gbc, uintptr_t ptr)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	if (!lst)
		return (NULL);
	lst->lst_next = gbc->last_garbage;
	lst->to_free = ptr;
	gbc->last_garbage = lst;
	return (lst);
}

void	free_your_garbage(t_lst *lst)
{
	if (lst->to_free)
		free((void *)lst->to_free);
	lst->to_free = 0;
}
