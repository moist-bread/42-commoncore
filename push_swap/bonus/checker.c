/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduro-pe <rduro-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:41:42 by rduro-pe          #+#    #+#             */
/*   Updated: 2024/12/29 00:05:30 by rduro-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_ok(t_stacks *stk);
void	exe_intructions(t_stacks *stk);

int	main(int argc, char **argv)
{
	t_stacks	*stk;

	if (input_processer(argc, argv, &stk, 0))
		return (1);
	// print_both_stacks(stk);
	exe_intructions(stk);
	check_ok(stk);
	// print_both_stacks(stk);
	free_stacks(stk);
	return (0);
}

void	exe_intructions(t_stacks *stk)
{
	char	*command;

	(void)stk;
	// when an instruct doesn’t exist or is incorrectly formatted
	// write(2, "Error\n", 6)
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (ft_strncmp(command, "sa\n", 3))
			sa_do(stk, 0);
		else if (ft_strncmp(command, "sb\n", 3))
			sb_do(stk, 0);
		else if (ft_strncmp(command, "ss\n", 3))
			ss_do(stk);
		else if (ft_strncmp(command, "pa\n", 3))
			pa_do(stk);
		else if (ft_strncmp(command, "pb\n", 3))
			pb_do(stk);
		else if (ft_strncmp(command, "ra\n", 3))
			ra_do(stk, 0);
		else if (ft_strncmp(command, "rb\n", 3))
			rb_do(stk, 0);
		else if (ft_strncmp(command, "rr\n", 3))
			rr_do(stk);
		else if (ft_strncmp(command, "rra\n", 4))
			rra_do(stk, 0);
		else if (ft_strncmp(command, "rrb\n", 4))
			rrb_do(stk, 0);
		else if (ft_strncmp(command, "rrr\n", 4))
			rrr_do(stk);
		else
		{
			write(2, "Error\n", 6);
			break ;
		}
		ft_printf("%s", command);
	}
	// ft_strncmp(command, "sa\n", 3);
}

void	check_ok(t_stacks *stk)
{
	if (sort_check(stk->a, stk->atop_id) && stk->btop_id == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/* int main(void)
{
	char	*line;

	//terminal input get line
	write(1, "your input: ", 13);
	line = get_next_line(1);
	printf("line: %s", line);
	free(line);
	return(0);
}
*/
/* int	main(void)
{
	int fd;
	char *line;
	int i = 1;

	fd = open("text.txt", O_RDONLY);
	while(i <= 42)
	{
		line = get_next_line(fd);
		printf("line %d: %s", i, line);
		i++;
		free(line);
	}
	return(0);
}  */

/* int main (void)
{

	int temp;
	int size;
	size = read (fd,buff, 10);
	buff[size] = '\0';
	printf("%s\n\n", buff);
	size = read (fd,buff, 10);
	buff[size] = '\0';
	printf("%s\n\n", buff);
	//close(fd);
	//fd = open("text.txt", O_RDONLY);
	//printf("%s\n\n", buff2);

} */