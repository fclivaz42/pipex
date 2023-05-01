/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclivaz <fclivaz@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:02:00 by fclivaz           #+#    #+#             */
/*   Updated: 2023/03/15 17:02:08 by fclivaz          ###    LAUSANNE.CH      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_pdata
{
	int		pid;
	int		infd;
	int		outfd;
	int		pipes;
	int		**fd;
	char	**commands;
}	t_pdata;

// --- PIPEX MAIN UTILS --- //
int		open_infile(char *path);
int		open_outfile(char *path);
int		count_pipes(t_pdata pipex);
int		skip_token(char *src, int i, char c);
int		**create_pipes(t_pdata pipex);
char	*make_token(char *src, int i, char c);
char	*first_token(char *src, int i);
char	**check_arguments(char **arg, char **env);
char	**tokenize(char *src);
void	free_array(char **array);
void	close_pipes(t_pdata pipex);

// --- BUNGIE SPECIFIC --- //

void	error_incorrect_use(void);
void	error_bad_format(char *src);
void	check_failed_memory(void *str);
void	error_system(int mode, char *file);

#endif