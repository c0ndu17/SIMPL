#ifndef ERROR_H
#define ERROR_H


/** the current line_number in the source file */
int line_number;

void eprintf(const char *fmt, ...);
void leprintf(const char *fmt, ...);
void teprintf(const char *tag, const char *fmt, ...);
void weprintf(const char *fmt, ...);
char *estrdup(const char *s);
char *westrdup(const char *s);
void *emalloc(size_t n);
void *wemalloc(size_t n);
void *erealloc(void *vp, size_t n);
void *werealloc(void *vp, size_t n);
char *progname(void);
void setprogname(char *s);
void freeprogname(void);

#endif  /* ERROR_H */
