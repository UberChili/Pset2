/**
 * initials.c
 * by Juan Andrés Núñez López
 *
 * Capitalizes first letters of each word in a string
 *
 * Universidad Michoacana de San Nicolás de Hidalgo
 * CS50x
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	// Stores user's input, no message needed
	string name = GetString();

	// Converts and prints first element in string, being first letter
	printf("%c", toupper(name[0]));

	// loops through string
	for (int i = 0, n = strlen(name); i < n; i++)
	{
		// Checks to find spaces
		if (name[i] == ' ')
		{
			// Converts and prints the element next to a space
			printf("%c", toupper(name[i + 1]));
		}
	}

	printf("\n");

	return 0;
}
