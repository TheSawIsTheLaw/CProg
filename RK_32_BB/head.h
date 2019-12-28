#ifndef __HEAD_H__
#define __HEAD_H__

typedef struct
{
	char word[11];
	struct node_t *before;
	struct node_t *after;
}node_t;

#endif
