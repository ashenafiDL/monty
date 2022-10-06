#include "monty.h"

/**
 * check_digit - checks if str is number
 * @str: the string to be checked
 * Return: 1 if str is number, 0 otherwise
 */
int check_digit(char *str)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}

	return (1);
}
