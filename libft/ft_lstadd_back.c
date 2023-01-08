/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:04:25 by igeorge           #+#    #+#             */
/*   Updated: 2021/11/12 14:04:25 by igeorge          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp)
	{
		if (!tmp->next)
		{
			tmp->next = new;
			return ;
		}
		tmp = tmp->next;
	}
}
