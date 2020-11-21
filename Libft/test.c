#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node *next;
	int	data;
} node;

int	main(void)
{
	node *head = (node *)malloc(sizeof(node));
	head->data = 100;

	node *node1 = (node *)malloc(sizeof(node));
	head->next = node1;
	node1->data = 10;

	node *node2 = (node *)malloc(sizeof(node));
	node1->next = node2;
	node2->data = 20;

	node2->next = NULL;

	node *curr = head;

	while (curr)
	{
		printf("%d\n", curr->data);
		curr = curr->next;
	}

	free(node2);
	free(node1);
	free(head);

	return (0);
}
