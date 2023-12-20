#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************/
/* These are the methods you are to write for a BST           */
/* More Detailed Instructions can be found in the doc and in  */
/* the BST.hpp file                                           */
/**************************************************************/

BST::BST(string n, string st, string descr, bool Xtra) {
	//4 pts
	//Constructor, takes as input 3 strings and a Boolean. The three
	//strings are the species, the status, and the info, and are used to
	//create the root node’s animal; The Boolean is true for if you want
	//the print methods to print out everything about each animal, or false
	//if you just want to see each animal’s name and height (easier to test
	//with)
	Xt = Xtra;
	root->animal = new Species(n, st, descr);
}

bool BST::insert(string n, string st, string descr) {
	// 9 pts
	//this is to insert a new node into the tree. It takes as input 3
	//strings, the name, the status, and the info, which are used to create
	//the new node’s animal field.
	bool ret;

	if (root==NULL){
		root = new BSTNode(n, st, descr);
		// ret = true;
		setHeight(root);
	}
	else{
		BSTNode *tmpNode = root;
		while(tmpNode != NULL){
			if(n < tmpNode->animal->name){
				if (tmpNode->left == NULL){
					BSTNode *insertedNode = new BSTNode(n, st, descr);
					tmpNode->left = insertedNode;
					insertedNode->parent = tmpNode;
					setHeight(tmpNode);
					return true;
				}
				else{
					tmpNode = tmpNode->left;
				}
			}
			else if(n > tmpNode->animal->name){
				if (tmpNode->right == NULL){
					BSTNode *insertedNode = new BSTNode(n, st, descr);
					tmpNode->right = insertedNode;
					insertedNode->parent = tmpNode;
					setHeight(tmpNode);
					return true;
				}
				else{
					tmpNode = tmpNode->right;
				}
			}
			else{
				return false;
			}
		}
	}
	return ret;
}

BSTNode *BST::find(string n) {
	// 7 pts
	//this finds the node who’s animal’s name matches the input string n,
	//and returns the node. If the node is not in the tree, find returns
	//NULL
			
	BSTNode *tmpNode = root;
	if (root==NULL){
		return NULL;
	}
	while(tmpNode != NULL && tmpNode->animal->name != n){
		if(n < tmpNode->animal->name){
			tmpNode = tmpNode->left;
		}
		else{
			tmpNode = tmpNode->right;
		}
	}
	if (tmpNode != NULL){
		cout << "Found: " << tmpNode->animal->name << endl;;
	}
	else{
		cout << n << ": Not Found" << endl;
	}
	return tmpNode;
}

void BST::updateStatus(string name, string st) {
	// 4 pts
	//This finds a node with the animal's name matching the
	//input name parameter and changes its current status to the
	//status st that is being passed in as a parameter
	BSTNode *updateNode = find(name);
	updateNode->animal->status = st;
	cout << "Updated: " << updateNode->animal->name << ": " << updateNode->animal->status << endl;
}


void BST::printTreeIO(BSTNode *tmp) {
	//3 pts
	//Prints the tree in order
	if (tmp==NULL){
		return;
	}
	else{	
		printTreeIO(tmp->left);
		tmp->printNode(false);
		printTreeIO(tmp->right);
	}
}

void BST::printTreePre(BSTNode *tmp) {
	// 3 pts
	// Prints the tree using a pre-order traversal
	if (tmp==NULL){
		return;
	}
	else{
		tmp->printNode(false);
		printTreePre(tmp->left);
		printTreePre(tmp->right);
	}
}


void BST::printTreePost(BSTNode *tmp) {
	// 3 pts
	//Prints the tree using post-order travesal
	if (tmp==NULL){
		return;
	}
	else{
		printTreePost(tmp->left);
		printTreePost(tmp->right);
		tmp->printNode(false);
	}
}

void BST::setHeight(BSTNode *tmp) {
	// 9 pts
	// this method updates the heights of a node's ancestors
	// when a node is added to a tree. Whenever a node is added
	// to a tree, it is possible that every one of its direct
	// ancestors' heights might possibly increase by 1, so you
	// have to check and possibly update the ancestors' heights
	while(tmp!=NULL){
		if (tmp->left == NULL && tmp->right==NULL){
			tmp->height = 1;
		}
		else if(tmp->right == NULL){
			if (tmp->left != NULL){
				tmp->height = tmp->left->height + 1;
			}
		}
		else if(tmp->left == NULL){
			if (tmp->right != NULL){
				tmp->height = tmp->right->height + 1;
			}
		}
		else if (tmp->left->height >= tmp->right->height){
			tmp->height=tmp->left->height + 1;
		}
		else if(tmp->left->height <= tmp->right->height){
			tmp->height = tmp->right->height + 1;
		}
		tmp = tmp->parent;
		// cout << "setHeight node: ";
		// tmp->printNode(false);
		// cout << endl;
	}
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
	// 5 pts
	// the method that removes a node with no children
	//find the node, delete the node, make parent point to NULL
	BSTNode *deleteNode = find(tmp->animal->name);
	BSTNode *parentNode = find(tmp->parent->animal->name);
	if (deleteNode->animal->name < parentNode->animal->name){
		parentNode->left = NULL;
		delete tmp;
	}
	else if (deleteNode->animal->name > parentNode->animal->name){
		parentNode->right = NULL;
		delete tmp;
	}
	setHeight(parentNode);
	return deleteNode;
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
	// 7 pts
	// the method that removes a node with one child
	//make node's parent point to node's child, make node's child point to node's parent, delete node
	BSTNode *currentNode = find(tmp->animal->name);
	BSTNode *parentNode = currentNode->parent;
	BSTNode *childNode;

	if(leftFlag){
		childNode = tmp->left;
	}
	else{
		childNode = tmp->right;
	}

	if (parentNode->left == tmp){
		parentNode->left = childNode;
		childNode->parent = parentNode;
		// delete tmp;
	}
	else{
		parentNode->right = childNode;
		childNode->parent = parentNode;
		// delete tmp;
	}

	setHeight(childNode);
	return currentNode;
}


BSTNode *BST::remove(string s) {
	// 9 pts
	// this method is the general remove method. If the node to 
	//be removed has no children, it calls removeNoKids. If the 
	//node to be removed has one child, it calls removeOneKid. 
	//If the node to be removed has 2 children, it finds the 
	//correct replacement node (right-most of left child) and 
	//replaces the data to be removed with the data in the right- 
	//most of the left child. It then calls either
	//removeNoKids or removeOneKid with that right-most of left 
	//child node
	BSTNode *removedNode = find(s);
	BSTNode *retNode = new BSTNode();

	if (removedNode == NULL){
		return NULL;
	}

	else if (removedNode->left == NULL && removedNode->right == NULL){   //no kids
		retNode = removeNoKids(removedNode);
	}

	else if (removedNode->left == NULL || removedNode->right == NULL){
		if(removedNode->right == NULL){
			retNode = removeOneKid(removedNode, true);
		}
		else if(removedNode->left == NULL){
			retNode = removeOneKid(removedNode, false);
		}
	}
	else if(removedNode->left != NULL && removedNode->right != NULL){
		//find right most of left child and replaces data of both nodes (not the nodes entirely?). 
		//then call removeNoKids or removeOneKid with that right-most of left child node
		BSTNode *leftChild = find(removedNode->left->animal->name);

		//finding right most of left child
		BSTNode *tmpNode = leftChild;
		while (tmpNode->right != NULL){
			tmpNode = tmpNode->right; //now tmpNode = right most of left child
		}

		//switching their data
		retNode->animal = removedNode->animal;
		removedNode->animal = tmpNode->animal;
	

		//removing right-most of left child node
		if (tmpNode->left == NULL && tmpNode->right == NULL){  //no kids	
			removeNoKids(tmpNode);
		}
		else{
			removeOneKid(tmpNode, true);  //leftFlag is true because the kid has to be on the left (can't be right most)
		}
	}
	return retNode;
}

/**************** Written for you  ***********************/

BST::BST(bool Xtra) {
	root = NULL;
	Xt = Xtra;
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(BSTNode *tmp) {
	if (tmp == NULL) {
		return;
	}
	else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode(Xt);
		delete(tmp);
	}
}
void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl << "Printing In Order:" << endl;
		printTreeIO(root);
	}
}






