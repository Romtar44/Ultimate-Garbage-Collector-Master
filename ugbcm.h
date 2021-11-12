/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_garbage_collector_master.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaducew <lgaducew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:43:55 by rtournet          #+#    #+#             */
/*   Updated: 2021/11/11 19:57:13 by lgaducew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ULTIMATE_GARBAGE_COLLECTOR_MASTER_H
# define ULTIMATE_GARBAGE_COLLECTOR_MASTER_H

# include <stdlib.h>
# include <stdint.h>

typedef struct s_lst
{
	uintptr_t	to_free;
	void		*lst_next;
}	t_lst;

typedef struct s_ugbcm
{
	t_lst	*garbage_master;
	t_lst	*last_garbage;
}	t_ugbcm;

t_lst	*lstnew(uintptr_t to_free);
t_lst	*lstnew_node(t_ugbcm *gbc, uintptr_t ptr);
void	free_your_garbage(t_lst *lst);
void	init(t_ugbcm *gbc);
void	*better_than_malloc(t_ugbcm *gbc, size_t size, size_t len);
void	taking_out_trashes(t_ugbcm *gbc);

#endif
