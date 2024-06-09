// file: lex.c

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "chtbl.h"
#include "lex.h"
#include "symbol.h"

#define TBLSIZ 11
// match_char
// we use this generic match char function to compare two characters
// pass it to the chained hash table public interface methods
static int match_char(const void *char1, const void *char2){
    // Compare two characters.

    return (*(const char *) char1 == *(const char *) char2);
}

// h_char
// we use this generic hash char function to hash a character within the table size
static int h_char(const void *key){

    // Define a simplistic hash function.

    return *(const char *) key % TBLSIZ;
}

// function : lex 

Token lex(const char *istream, CHTbl *symbl){

    Token token;
    Symbol *symbol;
    int length, retval, i;

    // Allocate space for a symbol

    if ((symbol = (Symbol *) malloc(sizeof(symbol))) == NULL){
        return error;
    }

    // Process the next token.
    if ((symbol->lexeme = next_token(istream)) == NULL){
        // REturn that there is no more input.
        free(symbol);
        return lexit;
    } else {
        // Determine the token type.

        symbol->token = digit;
        length = strlen(symbol->lexeme);

        for(int index = 0; index < length; index++){
            if (!isdigit(symbol->lexeme[index])){
                symbol->token = other;
            }
        }

        memcpy(&token, &symbol->token, sizeof(Token));
        // Insert the symbol into the symbol table
        if ((retval = chtbl_insert(symbl, symbol)) < 0){
            free(symbol);
            return error;
        } else if (retval == 1) {
            // The symbol is already in the symbol table.
            free(symbol);
        }


    }

    // Return the token for the parser.
    return token;
}

int main(void){
    CHTbl symbl; // Assume this is properly initialized somewhere

    const char *input = "123a45";

    Token token;

    if (chtbl_init(&symbl, TBLSIZ, h_char, match_char, free) != 0){
        return 1;
    }
    // Reset the token stream.
    next_token(input);

    // Process each token in the input string.
    while((token = lex(NULL, &symbl)) != lexit){
        if(token == digit){
            fprintf(stdout, "Token: digit\n");
        } else if (token == other){
            fprintf(stdout, "Token: other\n");
        } else if (token == error) {
            fprintf(stdout, "Token: error\n");
            break;
        }
    }
    return 0;
}