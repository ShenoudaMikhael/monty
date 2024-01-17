#include <stdlib.h>
#include <stdio.h>
/**
 * word_c - get num of words
 * @s: ptr string
 *
 * Return: int, words count
 */
int word_c(char *s)
{
	int i, c = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (*s == ' ')
			s++;
		else
		{
			for (; s[i] != ' ' && s[i] != '\0'; i++)
				s++;
			c++;
		}
	}
	return (c);
}
/**
 * freemem - free mem
 * @string: ptr
 * @i: count
 */
void freemem(char **string, int i)
{
	for (; i > 0;)
		free(string[--i]);
	free(string);
}

/**
 * strtow - splits string into words
 * @str: string tobe splitted
 * Return: ptr of ptrs
 */
char **strtow(char *str)
{
	int c = 0, cwd = 0, wordc = 0, i = 0;
	char *w2, **t;

	if (str == 0 || *str == 0)
		return (NULL);
	wordc = word_c(str);
	if (wordc == 0)
		return (NULL);
	t = malloc((wordc + 1) * sizeof(char *));
	if (t == 0)
		return (NULL);
	for (; *str != '\0' && i < wordc;)
	{
		if (*str == ' ')
			str++;
		else
		{
			w2 = str;
			for (; *str != ' ' && *str != '\0';)
			{
				cwd++, str++;
			}
			t[i] = malloc((cwd + 1) * sizeof(char));
			if (t[i] == 0)
			{
				freemem(t, i);
				return (NULL);
			}
			while (*w2 != ' ' && *w2 != '\0')
			{
				t[i][c] = *w2;
				w2++;
				c++;
			}
			t[i][c] = '\0';
			i++;
			c = 0, cwd = 0, str++;
		}
	}
	return (t);
}
