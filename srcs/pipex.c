/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:59:55 by fclivaz           #+#    #+#             */
/*   Updated: 2023/03/28 20:00:05 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_array(char **array)
{
	int	y;

	y = -1;
	while (array[++y] != NULL)
		free(array[y]);
	free(array);
}

static void	pipemoment(t_pdata pipex, int x)
{
	if (x == 0)
	{
		dup2(pipex.infd, STDIN_FILENO);
		dup2(pipex.fd[x][1], STDOUT_FILENO);
	}
	else if (pipex.commands[x + 1] == NULL)
	{
		dup2(pipex.fd[x - 1][0], STDIN_FILENO);
		dup2(pipex.outfd, STDOUT_FILENO);
	}
	else
	{
		dup2(pipex.fd[x - 1][0], STDIN_FILENO);
		dup2(pipex.fd[x][1], STDOUT_FILENO);
	}
	close_pipes(pipex);
}

static void	exec(t_pdata pipex, char **env, int x)
{
	char	**execute;

	execute = tokenize(pipex.commands[x]);
	pipemoment(pipex, x);
	if (execve(execute[0], execute, env) == -1)
		error_system(errno, "execfail");
}

static void	forkloop(t_pdata pipex, char **env, int x)
{
	pipex.pid = fork();
	if (pipex.pid < 0)
		error_system(errno, "forkfail");
	if (pipex.pid == 0)
		exec(pipex, env, x);
}

int	main(int argc, char **argv, char **env)
{
	t_pdata	pipex;
	int		x;

	x = -1;
	if (argc < 5)
		error_incorrect_use();
	pipex.infd = open_infile(argv[1]);
	pipex.outfd = open_outfile(argv[argc - 1]);
	pipex.commands = check_arguments(argv, env);
	pipex.pipes = count_pipes(pipex);
	pipex.fd = create_pipes(pipex);
	while (pipex.commands[++x] != NULL)
		forkloop(pipex, env, x);
	free_array(pipex.commands);
	waitpid(pipex.pid, NULL, 0);
	exit (0);
}
