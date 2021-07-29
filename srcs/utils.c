/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:06:42 by apinto            #+#    #+#             */
/*   Updated: 2021/07/29 08:07:24 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// must take care of the path that starts with PATH
char **get_path_variables(char **envp)
{
	char **paths;

	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (DEBUG)
		printf("%s\n", *envp);
	paths = ft_split(*envp, ':');
	return paths;
}

int	initialize_info(s_info *info, int argc, char **argv, char **envp)
{
	info->infile = argv[1];
	info->outfile = argv[4];
	info->command_count = 0;
	info->paths = get_path_variables(envp);
	info->envp = envp;
	info->argv = argv;
	info->argc = argc;
	if (pipe(info->pipe_fd) == -1)
		return (-1);
	if (!info->paths)
		return (-1);
	return (1);
}
