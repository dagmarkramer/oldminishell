#include "tokenizer"

// working on this need to take care of env first!!

// using a global for env is ok?
char	*tk_replace_env(char *word, int dollar)
{
	char	*result;
	char	*key;
	char	*value;

	key = ft_substr(word, dollar, ft_strclen(&word[dollar], ' '));
	value = ms_getenv(key, /* list */);			// herer needs my own version of getenv, is not malloced


	// malloc word-len plus env-len
	// write first part to result
	// write env part to result
	// write second part to result ft_strclen(&word[dollar], ' ')
	// strdup to get a clean string (maybe ot needed just small excess allocation)
}

char	*tk_expander(char *word)
{
	int	state;
	int	i;

	i - 0;
	state = 0;
	while (word[i])
	{
		if (state == 0)
		{
			if (word[i] == '\'')
				state = 1;
			if (word[i] == '$')
			{
				word = tk_repace_env(word, i);
				i--;
			}	
		}
		else
			if (word[i] == '\'')
				state = 0;
		i++;
	}
	return (word);
}

void	tk_expand_env(void *in)
{
	t_list	*token;

	token = (t_list *)in;
	token->word = tk_expander(token->word);
}
