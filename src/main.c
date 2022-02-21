#include "../headers/minishell.h"
// #  include <stdio.h>
// #  include <readline/readline.h>
// #  include <readline/history.h>
// d

int	g_global = 0;

void	error_handling(char *errormessage)
{
	perror(errormessage);
	exit(EXIT_FAILURE);
}

void	ms_next(t_mini *mini)
{
		mini->splitin = ft_split(mini->prompt, ' ');
		if (!ft_strncmp(mini->splitin[0], "echo", ft_strlen(mini->splitin[0])))
			ms_echo(mini);
		free(mini->splitin[0]);
		free(mini->splitin);
}

int	main(int argc, char **argv, char **newenv)
{
	t_mini	mini;

	(void)argv;
	(void)newenv;
	mini.prompt = NULL;
	signals();
	if (argc != 1)
	{
		printf("Error\nDo not use arguments, a prompt will pop up.\n");
		return (1);
	}
	while (1)
	{
		mini.prompt = readline("Oud Getrouwd Shell : ");
		if (mini.prompt == 0 && g_global == 0)
			break ;
		if (g_global == 0 && mini.prompt[0] != 0)
			ms_next(&mini);
		g_global = 0;
	}
	printf("\b\bexit\n");
	return (0);
}