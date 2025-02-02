/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaleh <amsaleh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 01:33:06 by amsaleh           #+#    #+#             */
/*   Updated: 2025/01/18 16:13:50 by amsaleh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_expander_default_mode_basic(char c, int mode)
{
	if ((mode == SINGLE_QUOTE_MODE && c == '\'') || (mode == DOUBLE_QUOTE_MODE
			&& c == '"'))
		return (1);
	return (0);
}

int	check_if_wildcard(char c, size_t i, t_list *quotes_range)
{
	size_t	*range;
	t_qr	*qr;

	if (c == '*')
	{
		while (quotes_range)
		{
			qr = (t_qr *)quotes_range->content;
			if (!qr->is_empty)
			{
				range = qr->arr;
				if (i >= range[0] && i <= range[1])
					return (0);
			}
			quotes_range = quotes_range->next;
		}
		return (1);
	}
	return (0);
}

int	check_quotes_ex_literal(char c, t_tok_expander *tok_exp)
{
	if ((c == '"' && tok_exp->mode == DOUBLE_QUOTE_MODE) || (c == '\''
			&& tok_exp->mode == SINGLE_QUOTE_MODE) || (check_quotes(c)
			&& tok_exp->mode == DEFAULT_MODE))
		return (1);
	return (0);
}

int	check_env_mode(t_tok_expander *tok_exp)
{
	if (tok_exp->mode == ENV_MODE || tok_exp->mode == DOUBLE_QUOTE_ENV_MODE)
		return (1);
	return (0);
}

int	check_op_type(t_list *lst)
{
	if (((t_token *)lst->content)->type == AND_OPERATOR)
		return (OPERATION_AND);
	if (((t_token *)lst->content)->type == OR_OPERATOR)
		return (OPERATION_OR);
	if (((t_token *)lst->content)->type == PIPE)
		return (OPERATION_PIPE);
	return (OPERATION_DEFAULT);
}
