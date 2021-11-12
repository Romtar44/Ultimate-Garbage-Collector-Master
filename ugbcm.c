/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ugbcm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaducew <lgaducew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:55:11 by rtournet          #+#    #+#             */
/*   Updated: 2021/11/11 22:18:22 by lgaducew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ugbcm.h"

void	init(t_ugbcm *gbc)
{
	gbc->garbage_master = NULL;
	gbc->last_garbage = NULL;
	gbc->garbage_master = lstnew(0x0);
}

void	*better_than_malloc(t_ugbcm *gbc, size_t size, size_t len)
{
	void	*to_malloc;
	t_lst	*lst;

	to_malloc = malloc(size * len);
	if (!to_malloc)
		return (NULL);
	lst = lstnew_node(gbc, (uintptr_t)to_malloc);
	if (!lst)
		return (NULL);
	return (to_malloc);
}

void	taking_out_trashes(t_ugbcm *gbc)
{
	t_lst	*temp;
	t_lst	*lst;

	if (gbc)
	{
		lst = gbc->last_garbage;
		while (lst)
		{
			free_your_garbage(lst);
			temp = lst->lst_next;
			if (lst)
				free(lst);
			lst = NULL;
			lst = temp;
		}
		if (gbc->garbage_master)
			free(gbc->garbage_master);
	}
}
