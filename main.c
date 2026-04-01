/*
Created by following guide by AlexTheRealDev
Video: How to Build a Compiler from Scratch | Full Guide
https://www.youtube.com/watch?v=HOe2YFnzO2I
*/

#include <stdio.h>
#define DS_IO_IMPLEMENTATION
#include "ds.h"
#include <string.h>
#include <ctype.h>

enum token_kind {
    IDENT,
    LABEL,
    INT,
    INPUT,
    OUTPUT,
    GOTO,
    IF,
    THEN,
    EQUAL,
    PLUS,
    LESS_THAN,
    INVALID
};

const char *show_token(enum token_kind kind) {
    switch(kind) {
        case IDENT: 
            return "ident";
        case LABEL: 
            return "label";
        case INT: 
            return "int";
        case INPUT: 
            return "input";
        case OUTPUT: 
            return "output";
        case GOTO: 
            return "goto";
        case IF: 
            return "if";
        case THEN: 
            return "then";
        case EQUAL: 
            return "equal";
        case PLUS: 
            return "plus";
        case LESS_THAN: 
            return "less_than";
        case INVALID:
            return "invalid";
    }
}

struct lexer {
    char *buffer;
    unsigned int buffer_len;
    unsigned int pos;
    unsigned int read_pos;
    char ch;
};

/*
looks at current read position and returns the 
character at that position
*/
static char lexer_peek_char(struct lexer *l) {
    if (l->read_pos >= l->buffer_len) {
        return EOF;
    }

    return l->buffer[l->read_pos];
}

/*
advance buffer and returns the current char
*/
static char lexer_read_char(struct lexer *l) {
    l->ch = lexer_peek_char(l);

    l->pos = l->read_pos;
    l->read_pos += 1;

    return l->ch;
}

static void skip_whitespaces(struct lexer *l) {
    while (isspace(l->ch)) {
        lexer_read_char(l);
    }
}

int main() {
    char *buffer = NULL;
    ds_io_read_file(NULL, &buffer);

    printf("%s\n", buffer);
    return 0;
}
