#include "header.h"
int main() {
	int key;
	char choice;
	int height, k, nodesNum, flag = 1;
	PTree root = NULL;
	while (flag)
	{
		printf("---------------------------\n---------------------------\nMenu:\n");
		printf("Press an option 1-6:\n");
		printf("1: To add a key to the tree\n");
		printf("2: To print the tree keys by In-Order\n");
		printf("3: To calculate the tree height\n");
		printf("4: To find the maximum key in the tree\n");
		printf("5: Check if a key exists in the tree\n");
		printf("6: To print the k smallest keys in increasing order\n");
		printf("Press q or Q to exit the program\n");

		printf("Please enter your choice: ");
		rewind(stdin);//We rewing the user keyboard input to not include \n 
		scanf("%c", &choice);
		switch (choice)
		{
		case '1':
			printf("Enter a key that you want to add to the tree:");
			while (1)
			{
				scanf("%d", &key);
				if (find_Treekey(root, key) == 1) {//return 1 if key already exists, else returns 0
					printf("The key is already exit, enter different key:");
				}
				else
				{
					add_node(&root, key);//if the key does not exist we add it to the tree
					break;
				}
			}
			break;
		case '2':
			printf("The tree in Inorder form is: \n\n");
			inOrder_print(root);//we call inOrder function
			printf("\n");
			break;
		case '3':
			height = height_Tree(root);//veriable gets the tree height
			printf("\nThe height of the tree is %d\n", height);
			break;
		case '4':
			find_max(root);
			break;
		case '5':
			printf("Enter a key to find in the tree:");
			scanf("%d", &key);//We get a float veriable from the user to check if exists.
			find_Treekey(root, key);
			if (find_Treekey(root, key) == 0)//if key does not exist
				printf("\nThe %d key was not found in the tree\n", key);
			else//if key exist
				printf("\nThe %d key exists in the tree\n", key);
			break;
		case '6':
			while (1)
			{
				printf("Choose how many keys you want to print in increasing order: ");
				scanf("%d", &k);
				nodesNum = num_nodes(root);
				if (k > nodesNum)
					printf("There are not enough nodes in the tree, please enter another value,\n\n");// if k> num of nodes
				else {

					print_k_smallest(root, &k);//We call print_k_smallest function with root of the tree and the adress of k.
					printf("\n");
					break;
				}
			}
			break;
		case 'q':case 'Q':
			flag = 0;
			free_tree(&root);
			printf("\nFINISH\nThank you for using our binaric-tree program!\n");
			break;
		default:
			printf("\nInput error, please try again.\n");
			break;
		}
	}
	return 0; 
}
