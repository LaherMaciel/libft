/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwencesl <lwencesl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:21:40 by lwencesl          #+#    #+#             */
/*   Updated: 2023/06/20 16:57:55 by lwencesl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Processes a string for pipex command handling.
 *
 * This helper function handles special cases for pipex commands, including
 * empty quotes and quoted strings. It frees the input string and returns
 * appropriate replacements based on the content.
 *
 * @param d The string to process for pipex.
 * @return Processed string or NULL on failure.
 */
char	*ft_process_pipex_string(char *d)
{
	char	*e;

	e = NULL;
	if (ft_strncmp(d, "''", 0) == 0)
	{
		free(d);
		return (ft_calloc(1, sizeof(char)));
	}
	if (ft_strncmp(d, "\' \'", 3) == 0)
	{
		free(d);
		d = ft_calloc(1, sizeof(char));
		d = " ";
	}
	else if (ft_strchr(d, '\"') != NULL && ft_strrchr(d, '\"') != NULL)
	{
		e = ft_substr(d, 0, (ft_strlen(d)));
		free(d);
		return (e);
	}
	return (d);
}

/**
 * @brief Creates a substring with pipex command processing.
 *
 * This function creates a substring from the input string starting at 'start'
 * with length 'len', then processes it for pipex command handling. It handles
 * edge cases like NULL input and ensures the substring doesn't exceed the
 * original string's bounds.
 *
 * @param s The input string to extract from.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return Processed substring, or NULL on failure.
 */
char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*d;

	a = 0;
	if (!s)
		return (NULL);
	while ((start + a) < ft_strlen(s) && a < len)
		a++;
	d = ft_calloc((a + 1), sizeof(char));
	if (!d)
		return (NULL);
	a = 0;
	while ((start + a) < ft_strlen(s) && a < len)
	{
		d[a] = s[start + a];
		a++;
	}
	d[a] = '\0';
	return (ft_process_pipex_string(d));
}
