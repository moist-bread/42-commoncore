/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:38:59 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/30 14:52:52 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		exe_intructions(t_stacks *stk);
int		command_assign(char *command, t_stacks *stk);
void	check_ok(t_stacks *stk);

#endif