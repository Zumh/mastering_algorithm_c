// symbol.h

#ifndef SYMBOL_H
#define SYMBOL_H
// Define next_token for demonstration purpose.
static char *next_token(const char *istream) {
    return NULL;
}

// Define a symbol structure for demonstration purposes.

typedef struct Symbol_ {
    char *lexeme;
    Token token;
} Symbol;
#endif