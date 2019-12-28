#ifndef __MY_SNPRINTF_H__
#define __MY_SNPRINTF_H__

#define DEBUG 0

#if DEBUG == 1
#define DEBM(s) printf("\nDEBUGGING_VALUE\n%s\nEND_DEB\n",s);
#elif DEBUG == 0
#define DEB(s) {};
#endif

int my_snprintf(char *restrict buf, size_t n, const char *restrict format, ...);

#endif
