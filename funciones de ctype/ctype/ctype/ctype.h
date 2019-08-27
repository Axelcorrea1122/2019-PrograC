#ifndef CTYPE_H_INCLUDED
#define CTYPE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_digit(int c);
int is_alnum(int c);
int is_alpha(int c);
int is_ascii(int c);
int is_cntrl(int c);
int is_graph(int c);
int is_lower(int c);
int is_print(int c);
int is_punct(int c);
int is_space(int c);
int is_upper(int c);
int to_ascii(int c);
int to_lower(int ch);
int to_upper(int ch);
#endif // CTYPE_H_INCLUDED
