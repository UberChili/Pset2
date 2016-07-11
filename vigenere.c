/**
 * vigenere.c
 *
 * by Juan Andrés Núñez López
 *
 * Implements Vigenere's Cipher accepting a keyword as a single command line argument
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
void cipher(string text, int keylength, string key);
char shift_upp(char val, int key);
char shift_low(char val, int key);

// Applies vigenere's cipher to upper case letter chars
char shift_upp(char val, int key)
{
	return (((val - 'A') + (key - 'A')) % 26) + 'A';
}

// Applies vigenere's cipher to lower case letter chars
char shift_low(char val, int key)
{
	return (((val - 'a') + (key - 'A')) % 26) + 'a';
}

// Loops through string of plaintext to implement Caesar's cipher
void cipher(string text, int key_length, string key)
{
	for (int i = 0, j = 0, n = strlen(text); i < n; i++)
	{
		// Checks if [i]th character is alphanumeric
		if (isalpha(text[i]))
		{
			// Checks if [i]th character is upper case, else it has to be lower case
			if (isupper(text[i]))
			{
				text[i] = shift_upp(text[i], key[j % key_length]);
				j++;
			}
			else
			{
				text[i] = shift_low(text[i], key[j % key_length]);
				j++;
			}
		}
	}
}

// main, accepting command line arguments
int main(int argc, char* argv[])
{
	// Checks for correct usage
	if (argc != 2)
	{
		printf("Usage: ./vigenere key\n");
		return 1;
	}

	for (int i = 0, n = strlen(argv[1]); i < n; i++)
	{
		if (!isalpha(argv[1][i]))
		{
			printf("Enter only a keyword, all letters.\n");
			return 1;
		}
		else
		{
			argv[1][i] = toupper(argv[1][i]);
		}
	}
	
	int key_length = strlen(argv[1]);

	// Asks user for plaintext 
	string text = GetString();

	// Applies cipher
	cipher(text, key_length, argv[1]);

	// Prints ciphered text
	printf("%s\n", text);

	return 0;
}
