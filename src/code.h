#ifndef __CODE_H_
#define __CODE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/*!
\fn char *cesar(char *str_message, int int_gap)
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 30/12/2022
\brief Use the cesar code to encrypt a message.
\param *str_message the message to encrypt
\param int_gap the gap use in the cesar code. If the gap is 3, a -> d, b-> e, etc.
\return the encrypted message
*/
char *cesar(char *str_message, int int_gap);

/*!
\fn char *vigenere(char *str_message, char *str_key);
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 29/12/2022
\brief Use the vigenere code to encrypt a message. WARNING : space count as a character, so it also use a letter in the kew word
\param *str_message the message to encrypt
\param *str_key the key word
\return the encrypted message
*/
char *vigenere(char *str_message, char *str_key);

/*!
\fn *scytale(char *str_message)
\author Quentin Rollet <quentin.rollet@cy-tech.fr>
\version 0.1 Initialization
\date 30/12/2022
\brief Use the scytale code to encrypt a message.
\param *str_message The message to encrypt
\return The encrypted message
*/
char *scytale(char *str_message);

#endif