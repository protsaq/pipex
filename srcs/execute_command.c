/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/27 20:26:43 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int execute_command(s_info *info, char **command)
{
	int pid;

	pid = fork();
	if (pid == 0)
	{
		// needs a piping from the file to the stdin
		printf("executing %s\n", command[0]);
		execve(command[0], &command[1], info->envp);
	}
	else
		wait(NULL);
	return (1);
}
