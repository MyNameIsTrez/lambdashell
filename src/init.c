/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 12:24:35 by mikuiper      #+#    #+#                 */
/*   Updated: 2022/09/12 13:00:39 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_ms(t_ms *ms)
{
	ms->line = NULL;
	return (0);
}

int	init_env(t_ms *ms, char **envp)
{
	int	i;

	ms->env = ft_calloc(1, sizeof(t_env));
	ms->tokens = ft_calloc(1, sizeof(t_list));
	i = 0;
	while (envp[i])
	{
		if (env_entry_cloner(ms, envp[i]))
			return (msg_err("env_entry_cloner()", 1));
		i++;
	}
	init_env_idx(ms->env);
	return (0);
}

int	init_start(void)
{
	if (!isatty(0))
		return(msg_err("init_start()", 1));
	if (!isatty(1))
		return(msg_err("init_start()", 1));
	if (!isatty(2))
		return(msg_err("init_start()", 1));
	//global_sig = 0;
	return (0);
}
