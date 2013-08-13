/**
 * @file    scanner.c
 *
 *
 *
 * @author  G.W.A. Phillips, 16512561
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

    {"end-of-file", TOKEN_EOF },
    {"identifier", TOKEN_ID},
    {"number literal", TOKEN_NUMBER},
    {"string literal", TOKEN_STRING},*/
    {"array", TOKEN_ARRAY},
    {"begin", TOKEN_BEGIN},
    {"boolean", TOKEN_BOOLEAN},
    {"define", TOKEN_DEFINE},
    {"do", TOKEN_DO},
    {"else", TOKEN_ELSE},
    {"elsif", TOKEN_ELSIF},
    {"end", TOKEN_END},
    {"false", TOKEN_FALSE},
    {"if", TOKEN_IF},
    {"integer", TOKEN_INTEGER},
    {"leave", TOKEN_LEAVE},
    {"not", TOKEN_NOT},
    {"program", TOKEN_PROGRAM},
    {"read", TOKEN_READ},
    {"relax", TOKEN_RELAX},
    {"then", TOKEN_THEN},
    {"true", TOKEN_TRUE},
    {"while", TOKEN_WHILE},
    {"write", TOKEN_WRITE}/* ,
   {"'='", TOKEN_EQUAL},
    {"'>='", TOKEN_GREATER_EQUAL},
    {"'>'", TOKEN_GREATER_THAN},
    {"'<='", TOKEN_LESS_EQUAL},
    {"'<'", TOKEN_LESS_THAN},
    {"'#'", TOKEN_NOT_EQUAL},
    {"'-'", TOKEN_MINUS},
    {"'or'", TOKEN_OR},
    {"'+'", TOKEN_PLUS},
    {"'and'", TOKEN_AND},
    {"'/'", TOKEN_DIVIDE},
    {"'*'", TOKEN_MULTIPLY},
    {"'%'", TOKEN_REMAINDER},
    {"']'", TOKEN_CLOSE_BRACKET},
    {"')'", TOKEN_CLOSE_PARENTHESIS},
    {"','", TOKEN_COMMA},
    {"'.'", TOKEN_DOT},
    {"':='", TOKEN_GETS},
    {"'['", TOKEN_OPEN_BRACKET},
    {"'('", TOKEN_OPEN_PARENTHESIS},
    {"'\"'", TOKEN_QUOTE},
    {"';'", TOKEN_SEMICOLON},
    {"'->'", TOKEN_TO}*/
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
    while(isspace(ch))
        next_char();
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
                process_string(token);
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
     * - Error on max int and chars
     */
     int num;
     num = ch -'0';
     next_char();
     while(isdigit(ch)){
        num = (( 10 * num ) + (ch - '0'));
        next_char();
     }
     token->type=TOKEN_NUMBER;
     token->value=num;
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
    char (*String)[MAX_STRING_LEN];
    int i;
    i=0;
    next_char();
    String = malloc(MAX_STRING_LEN);
    while(isprint(ch) && ch !='"' ){
        String[i++]=ch;
        next_char();
    }
    printf(sizeof(String));
    token->type=TOKEN_STRING;
    token->string = &String;
}

void process_word(token_t *token)
{
    char lexeme[MAX_ID_LENGTH + 1];
    int i, cmp, low, mid, high;

    /* check that the id length is less than the maximum */
    /* TODO: build the "word" in the lexeme array */
    i=0;
    while(lexeme[i]!=0)
        lexeme[i++]=0;
    i=0;
    while( !isspace(ch)&& i < MAX_ID_LENGTH ){
        lexeme[i++] = ch;
        next_char();
    }
    /* do a binary search through the array of reserved words */
    /* TODO: you MUST use binary search */
    high=NUM_RESERVED_WORDS;
    low=0;

    while(low<=high){
        mid = (high+low)/2;
        cmp = strcmp(lexeme, reserved[mid].word);
        if(cmp == 0){
          token -> type = reserved[mid].type;
          break;
        }
        if(cmp > 0){
          low = mid+1;
        }
        if(cmp < 0){
          high=mid-1;
        }
    }
    /* if id was not recognised as a reserved word, it is an identifier */
    /* TODO */

    if(cmp!=0){
       token->type= TOKEN_ID;
       while(i>=0)
         token->lexeme[i]=lexeme[i--];
    }
}

void skip_comment(void)
{
    int start_line;
    char tmp;
    /* TODO:
     * - skip nested comments
     * - terminate on error if not properly nested
     * - show such errors for the line on which the unclosed comment starts
     */
    start_line=line_number;
    while(ch!=EOF){
        tmp = ch;
        next_char();
        if(ch=='\n')
        if(tmp=='/'&&ch=='*')
            skip_comment();
        if(tmp=='*'&&ch=='/')
            return;
    }
    if(ch==EOF)
      printf("The comments are not nested correctly.\n Error on line %d", start_line);
    return;
}

/* vim: textwidth=80 tabstop=4
 */
