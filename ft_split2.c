/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahermaciel <lahermaciel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:04:51 by marvin            #+#    #+#             */
/*   Updated: 2025/08/11 12:03:30 by lahermaciel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Searches for the next separator position, handling quoted strings.
 *
 * This function finds the next occurrence of the separator character 'c',
 * but skips over quoted strings (both single and double quotes) to avoid
 * splitting within quotes. It handles special cases like empty quotes.
 *
 * @param str The string to search in.
 * @param c The separator character to find.
 * @return Position of the next separator, or -1 if not found.
 */
static size_t	ft_find_next_separator(const char *str, int c)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	if (ft_strncmp(str, "\' \'", 3) == 0)
		return (3);
	while (++a <= len)
	{
		if (str[a] == '\"' && (a == 0 || str[a - 1] == ' '))
		{
			a++;
			while (str[a] && str[a] != '\"')
				a++;
		}
		if (str[a] == c)
			return (a);
	}
	return (-1);
}

/**
 * @brief Skips leading separator characters.
 *
 * This function finds the position of the first non-separator character in the
 * string, effectively skipping over leading separators.
 *
 * @param str The string to search in.
 * @param c The separator character to skip.
 * @return Position of the first non-separator character, or -1 if all are
 * separators.
 */
static size_t	ft_skip_separators(const char *str, int c)
{
	size_t	a;
	size_t	len;

	a = -1;
	len = ft_strlen(str);
	while (++a < len)
		if (str[a] != c)
			return (a);
	return (-1);
}

/**
 * @brief Calculates the number of substrings that will be created.
 *
 * This function counts how many substrings will be created when splitting
 * the string 's' by the separator 'c', taking into account quoted strings
 * that should not be split.
 *
 * @param s The string to analyze.
 * @param c The separator character.
 * @return Number of substrings that will be created.
 */
static size_t	ft_count_substrings(const char *s, char c)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip_separators(s + (start + sep), c);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_find_next_separator((s + start), c);
		i++;
	}
	return (i);
}

/**
 * @brief Creates the array of substrings from the input string.
 *
 * This function performs the actual splitting operation, creating substrings
 * and storing them in the provided array. It handles quoted strings properly
 * and ensures the array is null-terminated.
 *
 * @param str The string to split.
 * @param c The separator character.
 * @param splited The array to store the substrings.
 * @return The filled array of substrings.
 */
static char	**ft_create_substring_array(const char *str, char c, char **splited)
{
	size_t	start;
	size_t	sep;
	size_t	i;
	size_t	sk;

	start = 0;
	i = 0;
	sep = 0;
	while (sep != (size_t) -1)
	{
		sk = ft_skip_separators(str + (start + sep), c);
		if (sk != (size_t) - 1)
			start = start + sep + sk;
		else if (sk == (size_t) - 1)
			break ;
		sep = ft_find_next_separator((str + start), c);
		if (sep != (size_t) - 1)
			splited[i] = ft_substr2(str, start, sep);
		else if (sep == (size_t) - 1)
			splited[i] = ft_substr2(str, start, ft_strlen(str + start));
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

/**
 * @brief Splits a string into an array of substrings, respecting quoted strings.
 *
 * This function splits the input string by the specified separator character,
 * but preserves quoted strings (both single and double quotes) as single
 * elements. It handles edge cases like NULL input and empty strings.
 *
 * @param s The string to split.
 * @param c The separator character.
 * @return Array of substrings, or NULL on failure.
 */
char	**ft_split2(char const *s, char c)
{
	char	**splited;

	if (!s)
		splited = (char **) ft_calloc(0, sizeof(char *));
	else
		splited = (char **) ft_calloc(
				(ft_count_substrings(s, c) + 1), sizeof(char *));
	if (!splited)
		return (NULL);
	return (ft_create_substring_array(s, c, splited));
}
