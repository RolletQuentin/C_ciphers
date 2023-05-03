/*!
\file main.c
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 29/11/2022
\brief Vectors and matrix manipulations
*/

#define ERROR_MISSING_VALUE -1
#define ERROR_VALUE_OUT_OF_RANGE -2
#define ERROR_NO_NUMBER -3
#define ERROR_WRONG_VALUE -4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#include "usefull_functions.h"
#include "code.h"

/*!
\fn int main(int argc, char **argv)
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 15/11/2022
\brief main function
\param argc number of arguments
\param **argv values of arguments
\return 0 if all is good
*/
int main(int argc, char **argv)
{
    int int_i;         // iteration variable
    long int lint_gap; // gap for cesar code
    char *str_code;    // name of the code
    char *str_key;     // the key for some codes
    char *str_message; // the message we want to encrypt
    char *str_endptr;
    size_t numberAllocateMemoryMessage;
    size_t numberAllocateMemoryKey;
    char *str_encryptedMessage;

    // options (if option == -1, option doesn't specify)
    int int_c; // encryption method option
    int int_d; // gap option
    int int_k; // key option
    int int_m; // message option

    // initialization
    errno = 0;
    int_c = -1;
    int_d = -1;
    int_k = -1;
    int_m = -1;
    str_key = NULL;
    str_code = NULL;
    str_message = NULL;

    // verification of the arguments (options correspond to odd index)
    for (int_i = 1; int_i < argc; int_i++)
    {
        // if we have -c option
        if (strcmp("-c", argv[int_i]) == 0)
        {
            int_c = 0;
            // missing parameter after -c
            if (int_i + 1 >= argc)
            {
                fprintf(stderr, "Merci de renseigner une valeur après -c.\n");
                exit(ERROR_MISSING_VALUE);
            }
            else
            {
                // alocate necessary belong the length of the user input
                str_code = malloc(strlen(argv[int_i]) * sizeof(char));
                str_code = argv[int_i + 1];
            }
        }

        // if we have -d option
        if (strcmp("-d", argv[int_i]) == 0)
        {
            int_d = 0;
            // missing parameter after -d
            if (int_i + 1 >= argc)
            {
                fprintf(stderr, "Merci de renseigner une valeur après -d.\n");
                exit(ERROR_MISSING_VALUE);
            }
            else
            {
                lint_gap = strtol(argv[int_i + 1], &str_endptr, 10);

                // Check for various possible errors
                if ((errno == ERANGE && (lint_gap == LONG_MAX || lint_gap == LONG_MIN)) || (errno != 0 && lint_gap == 0))
                {
                    perror("strtol : L'entier renseigné est trop grand ou n'est pas valide.\n");
                    exit(ERROR_VALUE_OUT_OF_RANGE);
                }
                if (str_endptr == argv[int_i + 1])
                {
                    fprintf(stderr, "Aucun nombre n'a été détecté.\n");
                    exit(ERROR_NO_NUMBER);
                }

                // All is good here
            }
        }

        // if we have -k option
        if (strcmp("-k", argv[int_i]) == 0)
        {
            int_k = 0;
            // missing parameter after -k.
            if (int_i + 1 >= argc)
            {
                fprintf(stderr, "Merci de renseigner une valeur après -c.\n");
                exit(ERROR_MISSING_VALUE);
            }
            else
            {
                // alocate necessary belong the length of the user input
                str_key = malloc(strlen(argv[int_i + 1]) * sizeof(char));
                str_key = argv[int_i + 1];
            }
        }

        // if we have -m option
        if (strcmp("-m", argv[int_i]) == 0)
        {
            int_m = 0;
            // missing parameter after -m
            if (int_i + 1 >= argc)
            {
                fprintf(stderr, "Merci de renseigner une valeur après -m.\n");
                exit(ERROR_MISSING_VALUE);
            }
            else
            {
                // alocate necessary belong the length of the user input
                str_message = malloc(strlen(argv[int_i + 1]) * sizeof(char));
                str_message = argv[int_i + 1];
            }
        }
    }

    // all parameters is read, now we verify if we have all required options
    if (int_c == -1)
    {
        fprintf(stderr, "The -c options is required.\n");
        exit(ERROR_MISSING_VALUE);
    }

    // if parameters is missing, we ask to the user to give them
    // missing gap
    if ((int_d == -1) && (strcmp("cesar", str_code)) == 0)
    {
        int_d = 0;
        lint_gap = inputInteger("Merci de renseigner le décallage voulu.\n");
    }
    // missing message
    if (int_m == -1)
    {
        int_m = 2;
        printf("Merci de renseigner le message à coder :\n");
        getline(&str_message, &numberAllocateMemoryMessage, stdin);
    }
    // missing key
    if ((int_k == -1) && (strcmp("vigenere", str_code) == 0))
    {
        int_k = 2;
        printf("Merci de renseigner la clé d'encodage :\n");
        getline(&str_key, &numberAllocateMemoryKey, stdin);
    }

    // we use the adequate function
    if (strcmp("cesar", str_code) == 0)
    {
        str_encryptedMessage = cesar(str_message, lint_gap);
    }
    else if (strcmp("vigenere", str_code) == 0)
    {
        str_encryptedMessage = vigenere(str_message, str_key);
    }
    else if (strcmp("scytale", str_code) == 0)
    {
        str_encryptedMessage = scytale(str_message);
    }
    // we don't recognise the code
    else
    {
        fprintf(stderr, "Le code renseigné n'existe pas. Merci de regarder lire le README, ou bien utiliser l'option -h");
        exit(ERROR_WRONG_VALUE);
    }

    printf("%s\n", str_encryptedMessage);

    // we free memory if a malloc is done
    if (int_k == 2)
    {
        free(str_key);
    }
    if (int_m == 2)
    {
        free(str_message);
    }
    if (int_c == 2)
    {
        free(str_code);
    }

    free(str_encryptedMessage);

    // because all is good
    return (0);
}
