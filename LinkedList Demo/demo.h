//Linked List Demo see source.cpp for using the features below.

#include <iostream>
using namespace std;

namespace NodeDemo{
	//Node
	class Node{
	public:
		//Node data that works on ints.
		int data;
		//Node ptr
		Node *next;
	};

	//Create a new node
	Node *NewNode(Node*next, int data){
		Node*n = new Node();
		//Check if node is null
		if (n == NULL){
			//Display error and exit
			std::cout << "Error Creating Node." << std::endl;
			exit(EXIT_FAILURE);
		}
		//Set node data
		n->data = data;
		//Set node next ptr to next
		n->next = next;
		return n;
	}

	Node *add_node(Node *head, int data){
		//New node
		Node* n = NewNode(head, data);
		//Set head to new node
		head = n;
		//Return node
		return head;
	}

	//Display all the data in the nodes
	void show_nodes(Node *n){
		//While node is not null
		while (n != NULL){
			//Display node data
			std::cout << n->data << std::endl;
			//Move to next ptr
			n = n->next;
		}
	}
	//Retuen the number of nodes
	int NodeCount(Node *head){
		Node* n = head;
		int x = 0;
		//While node is not null
		while (n != NULL){
			//INC node counter
			x++;
			//Move to next ptr
			n = n->next;
		}
		//Return counter value
		return x;
	}

	//Remove the first node
	Node *remove_first(Node* head){
		//Is head node null
		if (head == NULL){
			//Return null
			return NULL;
		}
		//Set first node to head node
		Node* first = head;
		//Move to next ptr
		head = head->next;
		//Set first ptr to null
		first->next = NULL;
		//Is first node head node
		if (first == head){
			//Set head node to null
			head = NULL;
			//Destroy the first node
			free(first);
		}
		//Return head node
		return head;
	}

	//Remove the last node
	Node *remove_last(Node * head){
		//Is head node null
		if (head == NULL){
			//Return null
			return NULL;
		}
		//Set cursor to head node
		Node *cursor = head;
		//Set back node to null
		Node *back = NULL;
		//While cursor ptr not equal null loop
		while (cursor->next != NULL){
			//Set back node to cursor node
			back = cursor;
			//Move the cursor node ptr
			cursor = cursor->next;
		}
		//Is back ptr not equal null
		if (back->next != NULL){
			//Set the back node ptr to null
			back->next = NULL;
		}
		//If cursor is the same as the head node
		if (cursor == head){
			//Set head node to null
			head = NULL;
		}
		//Destroy the cursor node
		free(cursor);
		//Return head node
		return head;
	}
	//This removes a node found in the head nodes list
	Node *remove_nodeAt(Node *head, Node *node){

		//If node is null
		if (node == NULL){
			//Return null
			return NULL;
		}
		//Is the node the head node
		if (node == head){
			//We remove the first node and return
			return remove_first(head);
		}

		//Is the node ptr null
		if (node->next == NULL){
			//We remove the last node and return
			return remove_last(head);
		}
		//Set cursor node to the head node
		Node* cursor = head;
		//While cursor node is not equal null loop
		while (cursor != NULL){
			//Is the cursor ptr equal null
			if (cursor->next == node){
				//We just excape out of the loop
				break;
			}
			//Move the cursor ptr
			cursor = cursor->next;
		}
		//Check if cursor is null
		if (cursor != NULL){
			//Set n to cursor ptt
			Node *n = cursor->next;
			//Set cursor ptr to n ptr
			cursor->next = n->next;
			//Set n ptr to null
			n->next = NULL;
			//Destroy n node
			free(n);
		}
		//Return head node
		return head;
	}

	//Reverse the order nodes in a list
	Node *reverse(Node *head){
		Node *old = NULL;
		Node *current = head;
		Node*next;
		//Check if current node is not equal null
		while (current != NULL){
			//Set next node to current node ptr
			next = current->next;
			//Set current ptr to old node
			current->next = old;
			//Set old node to the current node
			old = current;
			//Set the current node to the next node
			current = next;
		}
		//set head node to old node
		head = old;
		//Return head node
		return head;
	}

	//Locate a data item in a node in the list and return the node found
	Node*FindNode(Node* head, int finddata){
		//Set n node to head node
		Node* n = head;
		//While the n node is not null
		while (n != NULL){
			//Compare n contents to finddata value
			if (n->data == finddata){
				//Return the node found
				return n;
			}
			//Move the node along the list
			n = n->next;
		}
		//Nothing found so we return null
		return NULL;
	}
}