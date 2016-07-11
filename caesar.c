/**
 * caesar.c
 *
 * by Juan Andrés Núñez López
 *
 * Implements Caesar's Cipher accepting a number as a single command line argument
 *
 * Universidad Michoacana de San Nicolás de Hidalgo
 * CS50x
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototyping functions
void caesar(string text, int key);
char shift_upp(char val, int key);
char shift_low(char val, int key);

// Applies caesar's formula to upper case letter chars
char shift_upp(char val, int key)
{
	char arr[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	return  arr[((val - 'A') + key) % 26];
}

// Applies caesar's formula to lower case letter chars
char shift_low(char val, int key)
{
	char arr[26] = "abcdefghijklmnopqrstuvwxyz";

	return arr[((val - 'a') + key) % 26];
}

// Loops through string of plaintext to implement Caesar's cipher
void caesar(string text, int key)
{
	for (int i = 0, n = strlen(text); i < n; i++)
	{
		// Checks if [i]th character is alphanumeric
		if (isalpha(text[i]))
		{
			// Checks if [i]th character is upper case, else it has to be lower case
			if (isupper(text[i]))
			{
				text[i] = shift_upp(text[i], key);
			}
			else
			{
				text[i] = shift_low(text[i], key);
			}
		}
	}
}

int main(int argc, char* argv[])
{
	// Checks for correct usage
	if (argc != 2)
	{
		printf("Usage: ./caesar key\n");

		return 1;
	}

	// Stores argv[1] as the key
	int key = atoi(argv[1]);
	
	// Asks user for plaintext 
	string text = GetString();

	// Ciphers text using Caesar's cipher
	caesar (text, key);

	// Prints ciphered text
	printf("%s\n", text);

	return 0;
}
