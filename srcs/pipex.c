/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 17:12:52 by apinto            #+#    #+#             */
/*   Updated: 2021/07/27 20:23:49 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	s_info info;

	if (argc != 5)
	{
		printf("Wrong number of arguments! 😗\n");
		return (-1);
	}
	if (initialize_info(&info, argc, argv, envp) == -1)
		return (-1);
	file_handler(&info, 1);
	while (info.command_count != argc)
	{
		// prepare_command;
		commands_handler(&info, argv[info.command_count + 1]);
		// free_command;
	}
	return (0);
}
