// Reverse a linked list using iterative and recursive methods
#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	// Constructor
	node(int x)
	{
		this->data = x;
		next = NULL;
	}
};

// Iterative method
node *reverseList(node *head)
{
	node *prev = NULL, *curr = head, *next;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

// Recursive method when head is global
/* void recursiveReverse(node *curr)
{
	if (curr->next == NULL)
	{
		head = curr;
		return;
	}
	recursiveReverse(curr->next);
	node *nextNode = curr->next;
	nextNode->next = curr;
	curr->next = NULL;
} */

// When head is passed ar arg and new head is returned
node *revList(node *head)
{
	if (head->next == NULL)
	{
		return head;
	}
	node *rest = revList(head->next); // Throughout all recursive calls while popping stack calls, rest is the new head.
	head->next->next = head;		  // Links are reversed using these two steps
	head->next = NULL;
	return rest;
}

int main()
{
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	node *newHead = revList(head);
	node *temp = newHead;
	newHead = reverseList(head);
	// printing list
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}