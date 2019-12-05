#ifndef __TESTS_H__
#define __TESTS_H__

#define DEBUG 0

#if DEBUG == 1
#define DEB(s) printf("\nDEBUGGING_VALUE\n%s\nEND_DEB\n",s);
#elif DEBUG == 0
#define DEB(s) {};
#endif

#endif
