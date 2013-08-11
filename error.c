/* Adapted from 'The Practice of Programming' */
/* by Brian W. Kernighan and Rob Pike */
/* Copyright (C) 1999 Lucent Technologies */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "error.h"

extern int line_number;

static char *pname = NULL;

static void _weprintf(const char *pre, int lnum, const char *fmt, va_list args)
{
	fflush(stdout);
	if (pname != NULL)
		fprintf(stderr, "%s: ", pname);
	if (pre != NULL)
		fprintf(stderr, "%s: ", pre);
	if (lnum > 0)
		fprintf(stderr, "Line %d: ", line_number);

	vfprintf(stderr, fmt, args);

	if (fmt[0] != '\0' && fmt[strlen(fmt)-1] == ':')
		fprintf(stderr, " %s", strerror(errno));
	fprintf(stderr, "\n");
}


void eprintf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	_weprintf(NULL, 0, fmt, args);
	va_end(args);
	exit(2);
}


void leprintf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	_weprintf(NULL, line_number, fmt, args);
	va_end(args);
	exit(2);
}


void weprintf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	_weprintf("warning", 0, fmt, args);
	va_end(args);
}



void teprintf(const char *tag, const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	_weprintf(tag, line_number, fmt, args);
	va_end(args);
	exit(3);
}


char *estrdup(const char *s)
{
	char *t;
	t = malloc((strlen(s)+1)*sizeof(char));
	if (t == NULL)
		eprintf("estrdup(\"%.20s\") failed:", s);
	strcpy(t, s);
	return t;
}


char *westrdup(const char *s)
{
	char *t;
	t = malloc((strlen(s)+1)*sizeof(char));
	if (t == NULL)
		weprintf("estrdup(\"%.20s\") failed:", s);
	strcpy(t, s);
	return t;
}


void *emalloc(size_t n)
{
	void *p;

	p = malloc(n);
	if (p == NULL)
		eprintf("malloc of %u bytes failed:", n);
	return p;
}


void *wemalloc(size_t n)
{
	void *p;

	p = malloc(n);
	if (p == NULL)
		weprintf("malloc of %u bytes failed:", n);
	return p;
}


void *erealloc(void *vp, size_t n)
{
	void *p;
	
	p = realloc(vp, n);
	if (p == NULL)
		eprintf("realloc of %u bytes failed:", n);
	return p;
}


void *werealloc(void *vp, size_t n)
{
	void *p;
	
	p = realloc(vp, n);
	if (p == NULL)
		weprintf("realloc of %u bytes failed:", n);
	return p;
}


void setprogname(char *s)
{
	char *c;

	if ((c = strrchr(s, '/')) == NULL)
		c = s;
	else
		c++;
	pname = estrdup(c);
}


char *progname(void)
{
	return pname;
}

void freeprogname(void)
{
	free(pname);
}
