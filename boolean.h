/**
 * @file   boolean.h
 * @brief  Boolean data type definitions.
 * @author W. H. K. Bester
 * @date   2007
 */

#ifndef BOOLEAN_H
#define BOOLEAN_H

/** the boolean data type definition */
typedef short int boolean;

/** the boolean value TRUE */
#define TRUE  1

/** the boolean value FALSE */
#define FALSE 0

/** a macro to return a string value from a boolean; useful for debugging. */
#define BOOLEAN_VALUE(x) ((x) ? "TRUE" : "FALSE")

#endif

/* vim: tabstop=4 textwidth=79:
 */
