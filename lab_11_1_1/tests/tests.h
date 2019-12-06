#ifndef __TESTS_H__
#define __TESTS_H__

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "../my_snprintf.h"

#define YAHOOO 1 // Successed test
#define FUUUUU 0 // Fault test

#define DEBUG 0

#if DEBUG == 1
#define DEB(s) printf("\nDEBUGGING_VALUE\n%d\nEND_DEB\n",s);
#elif DEBUG == 0
#define DEB(s) {};
#endif

int neg_d_buf();

int neg_d_format();

int neg_d_size();

int pos_d_neg_num();

int pos_d_normal();

int pos_d_pos_num();

int pos_d_text();

int pos_d_zero_num();

#endif
