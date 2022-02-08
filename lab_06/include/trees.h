#ifndef _TREES_H_
#define _TREES_H_

#include "additional_structs.h"

// struct of the vertex(es)
typedef struct node_t
{
	char *value;         // значение в вершине
	unsigned int height; 
	struct node_t *left;
	struct node_t *right;
} node_t;

node_t *create_node(const char *const value);
void free_node(node_t *node);

void fix_height(node_t *p);
node_t *find_min(node_t *p);
node_t *remove_min(node_t *p);

node_t *remove_a(node_t *p, const char *const value, stat_t *const stat);
node_t *insert(node_t *p, const char *const value);

node_t *insert_b(node_t *vertex, const char *const value);
node_t *remove_b(node_t *vertex, const char *const value, stat_t *const stat);

void clean_atree(node_t *vertex);
void clean_tree(node_t *vertex);
#endif