/**
 * @file	scanner.h
 * @brief	Definitions for the exported variables and functions for the
 * 			lexical analyser (scanner) of SIMPL.
 * @author	W. H. K. Bester
 * @date	2012/07/08
 */

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>

#include "token.h"

/**
 * @brief	Initialises the scanner.
 *
 * @param[in]	in_file
 *		the (already open) source file
 */
void init_scanner(FILE *in_file);

/**
 * @brief	Gets the next token from the input (source) file.
 *
 * @param[out]	token
 *		contains the token just scanned
 */
void get_token(token_t *token);

#endif /* SCANNER_H */

/* vim: textwidth=80 tabstop=4
 */
