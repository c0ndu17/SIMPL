/**
 * @file    scanner.c
 *
 *
 *
 * @author  W. H. K. Bester
 * @date    2013/07/08
 */

#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "scanner.h"
#include "token.h"

/* --- type definitions and constants --------------------------------------- */

typedef struct {
    char        *word;          /* the reserved word, i.e., the lexeme */
    tokentype_t  type;          /* the associated token type           */
} rword_t;

/* --- global non-static variables ------------------------------------------ */

extern int line_number;

/* --- global static variables ---------------------------------------------- */

static FILE *src_file;          /* the source file pointer   */
static char ch;                 /* the next source character */

static rword_t reserved[] = {   /* reserved words            */
    /* TODO:
     * - populate with appropriate reserved-word-strings--token-type pairs
     * - must be ordered alphabetically by reserved-word-string
     */
    {"end-of-file", TOKEN_EOF },
    {"identifier", TOKEN_ID},
    {"number literal", TOKEN_NUMBER},
    {"string literal", TOKEN_STRING},
    {"'and'", TOKEN_AND},
    {"'array'", TOKEN_ARRAY},
    {"'begin'", TOKEN_BEGIN},
    {"'boolean'", TOKEN_BOOLEAN},
    {"'define'", TOKEN_DEFINE},
    {"'do'", TOKEN_DO},
    {"'else'", TOKEN_ELSE},
    {"'elsif'", TOKEN_ELSEIF},
    {"'end'", TOKEN_END},
    {"'false'", TOKEN_FALSE},
    {"'if'", TOKEN_IF},
    {"'integer'", TOKEN_INTEGER},
    {"'leave'", TOKEN_LEAVE},
    {"'not'", TOKEN_NOT},
    {"'program'", TOKEN_PROGRAM},
    {"'read'", TOKEN_READ},
    {"'relax'", TOKEN_RELAX},
    {"'then'", TOKEN_THEN},
    {"'true'", TOKEN_TRUE},
    {"'while'", TOKEN_WHILE},
    {"'write'", TOKEN_WRITE},
    {"'='", TOKEN_EQUAL},
    {"'>='", TOKEN_GREATER_EQUAL},
    {"'>'", TOKEN_GREATER THAN},
    {"'<='", TOKEN_LESS_EQUAL},
    {"'<'", TOKEN_LESS_THAN},
    {"'#'", TOKEN_NOT_EQUAL},
    {"'-'", TOKEN_MINUS},
    {"'or'", TOKEN_OR},
    {"'+'", TOKEN_PLUS},
    {"'/'", TOKEN_DIVIDE},
    {"'*'", TOKEN_MULTIPLY},
    {"'%'", TOKEN_REMAINDER},
    {"']'", TOKEN_CLOSE_BRACKET},
    {"')'", TOKEN_CLOSE_PARANTHESES},
    {"','", TOKEN_COMMA},
    {"'.'", TOKEN_DOT},
    {"':='", TOKEN_GETS},
    {"'['", TOKEN_OPEN_BRACKET},
    {"'('", TOKEN_OPEN_PARENTHESIS},
    {"'\"'", TOKEN_QUOTE},
    {"';'", TOKEN_SEMICOLON},
    {"'->'", TOKEN_TO}
};

#define NUM_RESERVED_WORDS (sizeof(reserved) / sizeof(rword_t))

/* XXX: The following definition is a temporary measure; our approach to string
 * handling will change in Part III.
 */
#define MAX_STRING_LEN     1024

/* --- function prototypes -------------------------------------------------- */

static void next_char(void);
static void process_number(token_t *token);
static void process_string(token_t *token);
static void process_word(token_t *token);
static void skip_comment(void);

/* --- scanner interface ---------------------------------------------------- */

void init_scanner(FILE *in_file)
{
    src_file = in_file;
    line_number = 1;
    next_char();
}

void get_token(token_t *token)
{
    /* remove whitespace */
    /* TODO: skip all whitespace characters */

    /* get the next token */
    if (!feof(src_file)) {
        if (isalpha(ch)) {

            /* process a word */
            process_word(token);

        } else if (isdigit(ch)) {

            /* process a number */
            process_number(token);

        } else switch (ch) {

            /* process a string */
            case '"':
                /* TODO: process the string */
                break;

            /* process other tokens */
            /* TODO */

        }
    } else {
        token->type = TOKEN_EOF;
    }
}

/* --- utility functions ---------------------------------------------------- */

/**
 * Reads the next character from the input (source) file into the global
 * variable <code>ch</code>.
 */
void next_char(void)
{
    /* TODO:
     * - get the next character from the source file
     * - increment the line number on EOL
                                                                                                            printf("fine\n");
     */
    if((ch = fgetc(src_file))==EOF)
        return;
    if(ch=='\n')
        line_number++;
}

/**
 * Constructs a number from the input (source) file.
 *
 * @param[out]  token
 *              the token in which to store the number information
 */
void process_number(token_t *token)
{
    /* TODO:
     * - build numbers (up to the specified maximum magnitude)
     * - store in the appropriate token field
     * - set the appropriate token type
     */
}

/**
 * Processes a string literal from the input (source) file.
 *
 * @param[out]  token
 *              the token in which to store the string literal
 */
void process_string(token_t *token)
{
    /* TODO:
     * - allocate heap space up to the maximum allowed string length; this is a
     *   temporary measure and will change in Part III
     * - ONLY printable ASCII characters are allowed; man 3 isalpha
     * - set the appropriate token type
     */
}

void process_word(token_t *token)
{
    char lexeme[MAX_ID_LENGTH + 1];
    int i, cmp, low, mid, high;

    /* check that the id length is less than the maximum */
    /* TODO: build the "word" in the lexeme array */

    /* do a binary search through the array of reserved words */
    /* TODO: you MUST use binary search */

    /* if id was not recognised as a reserved word, it is an identifier */
    /* TODO */
}

void skip_comment(void)
{
    int start_line;

    /* TODO:
     * - skip nested comments
     * - terminate on error if not properly nested
     * - show such errors for the line on which the unclosed comment starts
     */
}

/* vim: textwidth=80 tabstop=4
 */
