#include "minishell.h"

void	ms_print_word(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	printf("%s\n", token->word);
}

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	// tk_expand_all(tokens, data->env);
	ft_lstiter(tokens, tk_remove_quotes);
	ft_lstiter(tokens, ms_print_word);
	// go to execution
}
