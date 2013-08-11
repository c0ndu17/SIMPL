/**
 * @file   token.h
 * @brief  Data type definitions of the lexical analyser (scanner) for SIMPL.
 * @author W. H. K. Bester
 * @date   2013/07/08
 */

#ifndef TOKEN_H
#define TOKEN_H

/** the maximum length of an identifier */
#define MAX_ID_LENGTH 32

/** the types of tokens that the scanner recognises */
typedef enum {

	TOKEN_EOF,		/* end-of-file    */
	TOKEN_ID,		/* identifier     */
	TOKEN_NUMBER,	/* number literal */
	TOKEN_STRING,	/* string literal */

	/* keywords */
	/* note the boolean operators AND and OR -- although written out as string
	 * literals -- are still treated as operators */
	TOKEN_ARRAY,
	TOKEN_BEGIN,
	TOKEN_BOOLEAN,
	TOKEN_DEFINE,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_ELSIF,
	TOKEN_END,
	TOKEN_FALSE,
	TOKEN_IF,
	TOKEN_INTEGER,
	TOKEN_LEAVE,
	TOKEN_NOT,
	TOKEN_PROGRAM,
	TOKEN_READ,
	TOKEN_RELAX,
	TOKEN_THEN,
	TOKEN_TRUE,
	TOKEN_WHILE,
	TOKEN_WRITE,
	
	/* relational operators */
	/* the order is significant -- it allows us to do range checking in the
	 * parser */
	TOKEN_EQUAL,
	TOKEN_GREATER_EQUAL,
	TOKEN_GREATER_THAN,
	TOKEN_LESS_EQUAL,
	TOKEN_LESS_THAN,
	TOKEN_NOT_EQUAL,

	/* additive operators */
	TOKEN_MINUS,
	TOKEN_OR,
	TOKEN_PLUS,

	/* multiplicative operators */
	TOKEN_AND,
	TOKEN_DIVIDE,
	TOKEN_MULTIPLY,
	TOKEN_REMAINDER,

	/* other non-alphabetic operators */
	TOKEN_CLOSE_BRACKET,
	TOKEN_CLOSE_PARENTHESIS,
	TOKEN_COMMA,
	TOKEN_DOT,
	TOKEN_GETS,
	TOKEN_OPEN_BRACKET,
	TOKEN_OPEN_PARENTHESIS,
	TOKEN_QUOTE,
	TOKEN_SEMICOLON,
	TOKEN_TO

} tokentype_t;

/** the token data type */
typedef struct {
	tokentype_t	 type;					/**< the type of the token        */
	int			 value;					/**< numeric value (for integers) */
	char		 lexeme[MAX_ID_LENGTH];	/**< lexeme for identifiers       */
	char        *string;				/**< string (for write)           */
} token_t;

/**
 * Returns a string representation of the specified token type.
 *
 * @param[in]	type
 * 				the token for which to get a string representation
 * @return	a (constant) string representation of the specified token type
 */
const char *get_token_string(tokentype_t type);

#endif /* TOKEN_H */

/* vim: textwidth=80 tabstop=4
 */
