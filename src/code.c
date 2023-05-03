/*!
\file code.c
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 28/12/2022
\brief A few code to encode a message
*/

#include "code.h"

char *cesar(char *str_message, int int_gap)
{
    char *str_encryptMessage; // the message after encryption
    int int_i;                // iteration variable

    // allocate memory
    str_encryptMessage = malloc(strlen(str_message) * sizeof(char));

    // for each char of the string
    for (int_i = 0; int_i < strlen(str_message); int_i++)
    {
        // uppercase case
        if ((64 < (int)(str_message[int_i])) && ((int)(str_message[int_i]) < 91))
        {
            str_encryptMessage[int_i] = 65 + (((int)(str_message[int_i]) - 65 + int_gap) % 26);
        }

        // lowercase case
        else if ((96 < (int)(str_message[int_i])) && ((int)(str_message[int_i]) < 123))
        {
            str_encryptMessage[int_i] = 97 + (((int)(str_message[int_i]) - 97 + int_gap) % 26);
        }

        // other case, we do nothing
        else
        {
            str_encryptMessage[int_i] = str_message[int_i];
        }
    }

    return (str_encryptMessage);
}

char *vigenere(char *str_message, char *str_key)
{
    int int_i;                  // iteration variable
    int int_j;                  // iteration variable
    char *str_encryptedMessage; // the message after encryption

    // allocate memory
    str_encryptedMessage = malloc(strlen(str_message) * sizeof(char));

    // for each char of the string
    for (int_i = 0; int_i < strlen(str_message); int_i++)
    {
        int_j = int_i % strlen(str_key);

        // uppercase case
        if ((64 < (int)(str_message[int_i])) && ((int)(str_message[int_i]) < 91))
        {
            str_encryptedMessage[int_i] = 65 + (((int)(str_message[int_i]) - 65 + (int)(tolower(str_key[int_j]) - 97)) % 26);
        }

        // lowercase case
        else if ((96 < (int)(str_message[int_i])) && ((int)(str_message[int_i]) < 123))
        {
            str_encryptedMessage[int_i] = 97 + (((int)(str_message[int_i]) - 97 + (int)(tolower(str_key[int_j]) - 97)) % 26);
        }

        // other case, we do nothing
        else
        {
            str_encryptedMessage[int_i] = str_message[int_i];
        }
    }

    return (str_encryptedMessage);
}

char *scytale(char *str_message)
{
    int int_dim;                // the dimension of the grid
    int int_i;                  // iteration variable
    int int_j;                  // iteration variable
    int int_count;              // to know if we out of bounds
    char **ttchar_grid;         // grid
    char *str_encryptedMessage; // the message after encryption

    // -1 is because you have the \0 character at the end of the message
    int_dim = (int)(ceil(sqrt((strlen(str_message) - 1))));

    str_encryptedMessage = malloc(int_dim * int_dim * sizeof(char));
    int_count = 0;

    // construction of the matrix

    // allocation of memory
    ttchar_grid = malloc(int_dim * sizeof(char *));
    for (int_i = 0; int_i < int_dim; int_i++)
    {
        ttchar_grid[int_i] = malloc(int_dim * sizeof(char));
    }

    // we fill the grid
    for (int_i = 0; int_i < int_dim; int_i++)
    {
        for (int_j = 0; int_j < int_dim; int_j++)
        {
            if (int_count < strlen(str_message))
            {
                ttchar_grid[int_i][int_j] = str_message[(int_dim * int_i) + int_j];
            }
            else
            {
                ttchar_grid[int_i][int_j] = ' ';
            }
        }
        int_count++;
    }

    // construction of encrypted message
    // we read the matrix column by column
    for (int_j = 0; int_j < int_dim; int_j++)
    {
        for (int_i = 0; int_i < int_dim; int_i++)
        {
            str_encryptedMessage[(int_dim * int_j) + int_i] = ttchar_grid[int_i][int_j];
        }
    }

    // we can free memory allocate to the grid
    for (int_i = 0; int_i < int_dim; int_i++)
    {
        free(ttchar_grid[int_i]);
    }
    free(ttchar_grid);

    fprintf(stderr, "Tu arrives là ?\n");

    return (str_encryptedMessage);
}