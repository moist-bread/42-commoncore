/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:20:50 by rduro-pe          #+#    #+#             */
/*   Updated: 2025/01/29 16:44:41 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv)
{
	int result;

	if(argc != 5)
		return (1);
	result = access(argv[1], F_OK);
	ft_printf("%d (file 1)\n", result);
	result = access(argv[4], F_OK);
	ft_printf("%d (file 2)\n", result);
}