/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmaguire <wmaguire@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 1970/01/01 00:00:00 by wmaguire      #+#    #+#                 */
/*   Updated: 1970/01/01 00:00:00 by wmaguire      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
THIS FILE IS LICENSED UNDER THE GNU GPLv3
Copyright (C) 2022  Will Maguire

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
				- The freedom to run the program, for any purpose.
				- The freedom to study how the program works, and adapt it to your needs.
				- The freedom to redistribute copies so you can help your neighbor.
				- The freedom to improve the program, and release
				your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#include "../../include/minishell.h"

// NOTE: INFO
// Takes a raw line including args and redirections and
// outputs a string array only including the name of the program
// and the args. If a redirection operator exists, allocs the t_redirect
// struct in t_cmd.
// static char **chk_and_redirec(char *prog, t_cmd	*cmd)
// {
// 	char	**split;
// 	int		direction;

// 	if (ft_strrchr(prog, '>'))
// 	{
// 		split = ft_split(prog, '>');
// 		direction = OUT;
// 	}
// 	else if (ft_strrchr(prog, '<'))
// 	{
// 		split = ft_split(prog, '<');
// 		direction = IN;
// 	}
// 	else
// 		return (ft_split(prog, ' '));
// 	if (!split)
// 		return (NULL);
// 	cmd->redirection = ft_calloc(1, sizeof(*cmd->redirection));
// 	if (!cmd->redirection)
// 	{
// 		free_ptr_array(split);
// 		return (NULL);
// 	}
// 	cmd->redirection->content.direction = direction;
// 	cmd->redirection->content.file_path = split[1];
// 	return (ft_split(split[0], ' '));
// }

// NOTE: INFO
// cmd_constructor() is the constructor for the type
// t_cmd, which contains all the data required for execve() to be called.
// cmd_constructor() is used in the construction of singular commands.

// NOTE: USAGE
// The t_cmd type is used in the program to execute external binaries
// cleanly and without error. All errors surrounding missing binaries
// and non-functioning/non-existant paths should be caught here.
// The function operates in three stages.
// First assigning the args by splitting the prog_n string.
// Then using the env_to_string() function to assign the shell environment.
// Finally getting the full path to the binary returning the fully formed t_cmd.
// If any part fails, all memory will be freed before returning.

// TODO: lol @ the arrogance
// Memory leaks SHOULD be impossible.
// t_cmd	*cmd_constructor(char *prog_n_args, t_vector *env)
// {
// 	t_cmd	*cmd;

// 	cmd = ft_calloc(1, sizeof(*cmd));
// 	if (!cmd)
// 		return (null_msg_err("cmd_constructor()"));
// 	cmd->i_fd = STDIN_FILENO;
// 	cmd->o_fd = STDOUT_FILENO;
// 	cmd->redirection = NULL;
// 	cmd->args = chk_and_redirec(prog_n_args, cmd);
// 	if (!cmd->args)
// 	{
// 		cmd_deallocator(cmd);
// 		return (null_msg_err("cmd_constructor()"));
// 	}
// 	if (ft_strnstr(cmd->args[0], "/", ft_strlen(cmd->args[0])))
// 		cmd->path = cmd->args[0];
// 	else
// 		cmd->path = get_path_from_name(cmd->args[0], env);
// 	if (!cmd->path)
// 	{
// 		msg_err(cmd->args[0], FAILURE);
// 		cmd_deallocator(cmd);
// 		return (NULL);
// 	}
// 	return (cmd);
// }

// // NOTE: Cleanly deallocates a t_cmd.
// void	cmd_deallocator(t_cmd *cmd)
// {
// 	if (cmd->redirection)
// 	{
// 		ft_free(&cmd->redirection->file_path);
// 		ft_free(&cmd->redirection);
// 	}
// 	if (cmd->args)
// 		free_ptr_array(cmd->args);
// 	ft_free(&cmd->path);
// 	ft_free(&cmd);
// }
>>>>>>> origin/tokens
