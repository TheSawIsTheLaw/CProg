#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "head.h"

node_t *full_from_file(FILE *f)
{
	char word[11];
	node_t *new_node, *pre_node = NULL;
	
	while (fscanf(f, "%s", word) == 1)
	{
		new_node = calloc(1, sizeof(new_node));
		strcpy(new_node->word, word);
		if (pre_node)
			pre_node->after = new_node;
		new_node->before = pre_node;
		
		pre_node = new_node;
	}
	return new_node;
}

int reverse(FILE *f, node_t *node)
{
	while (node->before)
	{
		fprintf(f, "%s\n", node->word);
		node = node->before;
	}
	fprintf(f, "%s\n", node->word);
	
	return 0;
}

int main()
{
	FILE *file = fopen("in.txt", "r");
	
	if (!file)
		return 1;
	
	node_t *node = full_from_file(file);

	fclose(file);
	
	file = fopen("out.txt", "w");
	
	reverse(file, node);
	
	fclose(file);
	
	return 0;
}