#include "header.h"

void add_node(PTree* root, int key) {
	PTree temp;
	if (*root == NULL) {//if the tree is empty
		temp = (PTree)malloc(sizeof(Tree));
		if (temp == NULL) {
			printf("Memory allocation error.");
			free_tree(&temp);
			exit(1);
		}
		else {//A node is created with it's datas
			temp->key = key;
			temp->left = NULL;
			temp->right = NULL;
			(*root) = temp;
			printf("The key was successfuly added to the tree\n");
		}
	}
	else {//Finds the correct node location to create binaric tree
		if ((*root)->key < key)
			return add_node(&(*root)->right, key);
		if ((*root)->key > key)
			return add_node(&(*root)->left, key);
	}
}
int find_Treekey(PTree root, int to_find) {
	if (root == NULL)
		return 0;
	if (root->key == to_find)
		return 1;
	if (to_find < root->key)
		return find_Treekey(root->left, to_find);
	if (to_find > root->key)
		return find_Treekey(root->right, to_find);
}
void inOrder_print(PTree node_tree) {
	if (node_tree == NULL)
		return;
	inOrder_print(node_tree->left);
	printf("%d--> ", node_tree->key);
	inOrder_print(node_tree->right);
}

int height_Tree(PTree root) {//Recursive function to calculate tree's height.
	int left_h, right_h;
	if (root == NULL)
		return -1;//if tree is empty it returns -1
	left_h = height_Tree(root->left);
	right_h = height_Tree(root->right);
	if (left_h > right_h)
		return 1 + left_h;
	else
		return 1 + right_h;
}
void find_max(PTree root) {
	int max = root->key;
	PTree runner = root;//Runner to get to the rightest leaf which is the maximum in a binary search tree
	while (runner->right != NULL) {
		max = runner->right->key;
		runner = runner->right;
	}
	printf("\nThe maximum value in the tree is %d\n", max);
}
void print_k_smallest(PTree root, int* k) {//goes to the leftest leaf in the binary search tree and then using the value k recursivly to print k min values
	if (root == NULL)//checks if the tree is empty
		return;
	print_k_smallest(root->left, k);
	if (*k > 0) {//while k>0 print the current key and continue
		printf("%d--> ", root->key);
		(*k)--;
		print_k_smallest(root->right, k); 
	}
}
int num_nodes(PTree root) {//Calculates recursively the amount of nodes in the tree
	PTree runner = root;
	if (runner == NULL)
		return 0;
	else
		return 1 + (num_nodes(runner->left) + num_nodes(runner->right));
}
void free_tree(PTree* root) {//free all the nodes in the tree recursively
	if ((*root) == NULL)
		return;
	free_tree(&((*root)->left));
	free_tree(&((*root)->right));
	free(*root);
	*root = NULL;
}
