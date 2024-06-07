/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:19:32 by itahri            #+#    #+#             */
/*   Updated: 2024/05/21 19:37:51 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		if (str[i] != sep && str[i])
			count++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (count);
}

static char	**escape(char **to_free, int count, int cas)
{
	int		i;
	char	**str;

	if (cas == 2)
	{
		i = 0;
		while (i <= count)
			free(to_free[i++]);
		return (free(to_free), NULL);
	}
	else
	{
		str = malloc(sizeof(char *) * 1);
		if (!str)
			return (NULL);
		else
		{
			str[0] = NULL;
			return (str);
		}
	}
}

static char	*compose(char const *word, char c, int index)
{
	size_t	i;
	char	*result;
	size_t	w_len;

	w_len = 0;
	while (word[index + w_len] && word[index + w_len] != c)
		w_len++;
	result = malloc(sizeof(char) * w_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < w_len)
	{
		result[i] = word[index + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**split_it(char const *s, char **result, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			result[cnt] = compose(s, c, i);
			if (!result[cnt])
				return (escape(result, cnt, 2), NULL);
			cnt++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (result[cnt] = NULL, result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	**escape_val;

	if (s[0] == '\0' || !s)
	{
		escape_val = escape(NULL, 0, 1);
		if (!escape_val)
			return (NULL);
		return (escape_val);
	}
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	result = split_it(s, result, c);
	if (!result)
	{
		if (result && !result[0])
			free(result);
		return (NULL);
	}
	return (result);
}

/*
int main(void)
{
	char **tab;
	//char invalid[] = "\0"; 

	printf("nb words : %d\n", ft_count_words(" s f f ||  ", ' '));

	tab = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');

	if (tab && tab[0])
		printf("tab[0] : %s\n", tab[0]);
	if (tab && tab[1])
		printf("tab[1] : %s\n", tab[1]);
	if (tab && tab[2])
		printf("tab[2] : %s\n", tab[2]);
	if (tab && tab[3])
		printf("tab[2] : %s\n", tab[3]);
}
*/
/*
int    main(void)
{
	char **tab;
	tab = ft_split("hello!", ' ');
	if (!tab || !tab[0])
	{
		if (tab && !tab[0])
			free(tab);
		return 0;
	}
	printf("%s\n", tab[0]);
	//printf("%s\n", tab[1]);
	free(tab[0]);
	//free(tab[1]);
	free(tab);
}
*/
