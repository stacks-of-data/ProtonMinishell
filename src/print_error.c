/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:54:59 by abueskander       #+#    #+#             */
/*   Updated: 2024/12/05 19:33:51 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_error(int error)
{
	if (error == ERR_MALLOC || error == ERR_MALLOC2)
		perror("malloc failed");
	if (error == ERR_TERM)
		perror("term fail");
}
