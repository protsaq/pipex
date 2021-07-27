/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinto <apinto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:31:46 by apinto            #+#    #+#             */
/*   Updated: 2021/07/27 20:15:02 by apinto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	file_handler(s_info *info, int in, int out)
	// one could make this print as an error
	if (in && access(info->infile, R_OK) == -1)
	{
		printf("no such file or directory: %s\n", argv[1]);
		return (-1);
	}
	else if (in)
	{
		info->infile_fd = open(info->infile, O_RDONLY);
		if (info->infile_fd == -1)
			return (-1);
	}
	else if (!in)
	{
		info->outfile_fd = open(info->outfile, O_WRONLY | O_CREAT);
		if (info->outfile_fd == -1)
			return (-1);
	}
