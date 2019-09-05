#include "ctype.h"
/*Si el caracter es un digito */
int is_digit(int c)
{
    return c>='0' && c<='9' ? 1:0;
}

/*Si el caracter es un alphanumerico*/
int is_alnum(int c)
{
    return (c>='0' && c<='9') || (c>'a' && c<'z') || (c>'A' && c<'Z') ? 1:0;
}

/* Si el caracter es una letra*/
int is_alpha(int c)
{
    return (c>='a' && c<='z') || (c>='A' && c<='Z') ? 1:0;
}

/* Si el caracter pertenece al codigo ascii*/
int is_ascii(int c)
{
    return c>=0 && c<=127 ? 1:0;
}
/* Si el caracter es de control*/
int is_cntrl(int c)
{
    return c>=0 && c<=31 ? 1:0;
}

int is_graph(int c)
{
    return c>=33 && c<=126 ? 1:0;
}

int is_lower(int c)
{
    return c>='a' && c<='z' ? 1:0;
}


int is_print(int c)
{
    return c>=32 && c<=126 ? 1:0;
}

int is_punct(int c)
{
    return !is_alpha(c) && c!=' ' ? 1:0;
}


int is_space(int c)
{
    return c>=9 && c<=10 && c==13 && c==32 ? 1:0;
}

int is_upper(int c)
{
    return c>='A' && c<='Z' ? 1:0;
}

int is_xdigit(int c)
{
    return is_digit(c) || is_alpha(c) ? 1:0;
}

int to_ascii(int c)
{
    return c>='0' && c<='9' ? c + '0' : c;
}

int to_lower(int ch)
{
    return ch>='A' && ch<='Z' ? ch : ch + ('a' - 'A');
}


int to_upper(int ch)
{
    return ch>='a' && ch<='z' ? ch : ch - ('a' - 'A');
}
