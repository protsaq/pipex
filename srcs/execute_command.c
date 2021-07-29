/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:26:20 by apinto            #+#    #+#             */
/*   Updated: 2021/07/29 08:07:57 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* dup2(fd_1, fd_2)
 * fd_2 will point to the same stream as fd_1
 *  fd[0]; //-> for using read end
    fd[1]; //-> for using write end*/
int execute_command(s_info *info, char **command)
{
	int err;
	int pid;

	pid = fork();
	if (pid == 0)
	{
		if (info->command_count == 0)
			dup2(info->infile_fd, STDIN_FILENO);
		else
			dup2(info->pipe_fd[0], STDIN_FILENO);
		if (info->command_count == info->argc - 1)
			dup2(info->outfile_fd, STDOUT_FILENO);
		else
			dup2(info->pipe_fd[1], STDOUT_FILENO);
		err = execve(info->concatenated_path, ft_split("cat", ' '), info->envp);
		if (err == -1)
			printf("failed execution of %s\n", command[0]);
	}
	wait(NULL);
	info->command_count++;
	close(info->pipe_fd[1]);
	return (1);
}
