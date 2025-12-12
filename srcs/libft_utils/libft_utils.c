/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arochd <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:22:39 by arochd            #+#    #+#             */
/*   Updated: 2025/12/11 11:13:05 by arochd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	nbr;

	if (!s)
		return (0);
	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			nbr++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nbr);
}

static void	freeing(char **arr, int i)
{
	while (i >= 0)
		free(arr[i--]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	cntr;

	if (!s)
		return (NULL);
	strs = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	(1 == 1) && (i = 0, cntr = 0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		strs[cntr] = ft_substr(s, j, i - j);
		if (!strs[cntr++])
			return (freeing(strs, cntr - 1), NULL);
	}
	return (strs[cntr] = NULL, strs);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*duplicated;

	len = ft_strlen(s);
	duplicated = malloc((len + 1) * sizeof(char));
	if (!duplicated)
		return (NULL);
	i = 0;
	while (i < len)
	{
		duplicated[i] = s[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
}
