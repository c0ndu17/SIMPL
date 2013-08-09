/**
 * @file	token.c
 * @brief	Utility functions for SIMPL tokens.
 * @author	W. H. K. Bester
 * @date	2013/07/08
 */

#include "token.h"

/* the token strings */
static char *token_names[] = { "end-of-file", "identifier", "number literal",
	"string literal", "'array'", "'begin'", "'boolean'", "'define'", "'do'",
	"'else'", "'elsif'", "'end'", "'false'", "'if'", "'integer'", "'leave'",
	"'not'", "'program'", "'read'", "'relax'", "'then'", "'true'", "'while'",
	"'write'", "'='", "'>='", "'>'", "'<='", "'<'", "'#'", "'-'", "'or'", "'+'",
	"'and'", "'/'", "'*'", "'%'", "']'", "')'", "','", "'.'", "':='", "'['",
	"'('", "'\"'", "';'", "'->'"
};

/* --- functions ------------------------------------------------------------ */

const char *get_token_string(tokentype_t type)
{
	return token_names[type];
}

/* vim: textwidth=80 tabstop=4
 */
