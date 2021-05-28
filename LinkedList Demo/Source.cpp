// Linked list demo
// By Ben a.k.a DreamVB

#include <iostream>
#include "demo.h";
using namespace std;

int main(){
	//Head node is the top head of the linked list
	NodeDemo::Node* LList = NULL;
	NodeDemo::Node *tmp_find;
	//This adds the node to the head list
	LList = add_node(LList, 10);
	LList = add_node(LList, 20);
	LList = add_node(LList, 30);
	LList = add_node(LList, 40);
	LList = add_node(LList, 150);
	LList = add_node(LList, 255);
	LList = add_node(LList, 65);

	//Display items
	show_nodes(LList);

	//Display items in reverse order
	std::cout << std::endl << "Reverse order: " << std::endl;
	LList = reverse(LList);
	//Display the items
	show_nodes(LList);

	//Find a node's data.
	tmp_find = FindNode(LList, 20);
	//No node found
	if (tmp_find == NULL){
		std::cout << "20 was not found in the nodes." << std::endl;
	}
	else{
		//Node was found
		std::cout << "20 Was found in the nodes." << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Remove 150 from the list" << std::endl;
	//Locate the node in the list
	tmp_find = FindNode(LList, 150);
	//If not is not equal to null
	if (tmp_find != NULL){
		//Remove the node found above
		LList = remove_nodeAt(LList, tmp_find);
	}
	//Display the items after node remove
	show_nodes(LList);
	std::cout << std::endl;
	
	//Remoev front and back nodes in the list
	std::cout << "Remove first and last nodes" << std::endl;
	//Remove first node
	LList = remove_first(LList);
	//Remove the last node
	LList = remove_last(LList);
	//Display the items in the list after removes above
	show_nodes(LList);

	return EXIT_SUCCESS;
}