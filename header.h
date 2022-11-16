#ifndef _header
#define _header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bin_tree {// structure for the binary tree with pointer PTree 
	int key;
	struct bin_tree* left;
	struct bin_tree* right;
}Tree,* PTree;

/*Declaration for all of our functions we are using*/
void add_node(PTree root, int key);//function to add a new node to the tree
void inOrder_print(PTree root);//function to print the tree in inorder
int height_Tree(PTree root);//fubction that calculates the height of the tree and return it
void find_max(PTree root);//function to find the maximum key in the tree
int find_Treekey(PTree root, int to_find);//function that find the input key chosen by the user
void print_k_smallest(PTree root, int* cnt);//function that prints the k smallest keys and prints them
void free_tree(Tree** root);//free the memory
int num_nodes(PTree root);//calculates the amount of nodes in the tree

#endif

