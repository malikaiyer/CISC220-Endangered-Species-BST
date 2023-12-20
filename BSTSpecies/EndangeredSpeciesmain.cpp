#include "BST.cpp"
#include "Interface.cpp"
#include "BSTNode.cpp"
#include "Species.cpp"
#include <iostream>
using namespace std;


void readInTree(BST *tree);


int main() {
/******************************************************************************
* For Testing - this is how I did it (there's more than one way!!!)
* Step 1:
* I First wrote the constructor, the insert, and the 3 print methods - I didn't
* write the setHeights until after, so all heights are 1 at this point.
******************************************************************************/
BST *tree = new BST(false); //false is for the less verbose version - for testing purposes
readInTree(tree);
tree->printTreePre();
tree->printTreeIO();
tree->printTreePost();
/****************************************************************************
* My output from this:
****************************************************************************/
/*
Printing PreOrder:
Tiger (1)
Orangutan (1)
Giant Panda (1)
Blue Whale (1)
Asian Elephant (1)
African Wild Dog (1)
Amur Leopard (1)
Axolotl (1)
Black-footed Ferrets (1)
Chimpanzees (1)
Galapagos Penguins (1)
Gorilla (1)
Golden Lion Tamarins (1)
Snow Leopard (1)
Rhinoceros (1)
Sea Turtle (1)
Sea Otter (1)

Printing In Order:
African Wild Dog (1)
Amur Leopard (1)
Asian Elephant (1)
Axolotl (1)
Black-footed Ferrets (1)
Blue Whale (1)
Chimpanzees (1)
Galapagos Penguins (1)
Giant Panda (1)
Golden Lion Tamarins (1)
Gorilla (1)
Orangutan (1)
Rhinoceros (1)
Sea Otter (1)
Sea Turtle (1)
Snow Leopard (1)
Tiger (1)

Printing PostOrder:
Amur Leopard (1)
African Wild Dog (1)
Black-footed Ferrets (1)
Axolotl (1)
Asian Elephant (1)
Galapagos Penguins (1)
Chimpanzees (1)
Blue Whale (1)
Golden Lion Tamarins (1)
Gorilla (1)
Giant Panda (1)
Sea Otter (1)
Sea Turtle (1)
Rhinoceros (1)
Snow Leopard (1)
Orangutan (1)
Tiger (1)
/****************************************************************************
* For Testing - (again, there's more than one way!!!)
* Step 2:
* I then wrote find, which I called from the insert method since heights
* are only changed when a new node is inserted.
****************************************************************************/
cout << endl << "Testing Find: " << endl;
tree->find("Sea Otter");
tree->find("Asian Elephant");
tree->find("Giant Panda");
tree->find("T Rex");
/****************************************************************************
* My output from this:
****************************************************************************/
/*
Testing Find:
Found:Sea Otter (1)
Found:Asian Elephant (1)
Found:Giant Panda (1)
T Rex: Not Found
*/
/****************************************************************************
* Clear out old tree
****************************************************************************/
tree->clearTree();
cout <<"************************************" << endl;
/****************************************************************************
* For Testing - (again, there's more than one way!!!)
* Step 3:
* I then wrote setHeight, which I called from the insert method since heights
* are only changed when a new node is inserted.
****************************************************************************/
readInTree(tree);
tree->printTreeIO();
/****************************************************************************
* My output from this:
****************************************************************************/
/*
Printing In Order:
African Wild Dog (2)
Amur Leopard (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (3)
Sea Otter (1)
Sea Turtle (2)
Snow Leopard (4)
Tiger (7)
***********************************************************************/
/****************************************************************************
* For Testing - (yep, still more than one way!!!)
* Step 4:
* I then wrote updateStatus and tested:
****************************************************************************/
cout << "************************************************************"<<endl;
cout << "Testing Update Status"<<endl;
BSTNode *tmp = tree->find("Black-footed Ferrets");
cout << endl;
tmp->printNode(true);
cout << endl;
tree->updateStatus("Black-footed Ferrets", "T1");
cout << endl << endl;
tmp = tree->find("Sea Turtle");
cout << endl;
tmp->printNode(true);
cout << endl;
tree->updateStatus("Sea Turtle", "NT");
cout << endl << endl;
/****************************************************************************
* My output from this:
****************************************************************************/
/*
**************************************************************
Testing Update Status
Found:Black-footed Ferrets (1)
Black-footed Ferrets (1) : T2
Get this - this ferret is only found in North America and eats animals its own size.
Found:Black-footed Ferrets (1)
Black-footed Ferrets (1) : T1
Get this - this ferret is only found in North America and eats animals its own size.
Found:Sea Turtle (2)
Sea Turtle (2) : VU
These animals have been around for 100 million years, and, yep, we're about to wipe
that out. Quite an accomplishment, in a bad way...,
Found:Sea Turtle (2)
Sea Turtle (2) : NT
These animals have been around for 100 million years, and, yep, we're about to wipe
that out. Quite an accomplishment, in a bad way...,
*/
/****************************************************************************
* For Testing - (...and... still more than one way!!!)
* Step 5:
* I started writing the three remove methods. I started by witing part of the
* general remove method that called the removeNoKids method. Then I wrote
* removeNoKids and tested by removing a node that had no children. I made sure
* that remove called removeNoKids when the node to be removed had no kids
* Note that the heights of the ancestors of the removed node have been updated
****************************************************************************/
cout << "********************************************************"<<endl;
cout << "Removing, node with no kids:"<<endl;
tree->printTreeIO();
cout << endl;
tree->remove("Amur Leopard");
tree->printTreeIO();
/****************************************************************************
* My output from this:
****************************************************************************/
/*
********************************************************
Removing, node with no kids:
Printing In Order:
African Wild Dog (2)
Amur Leopard (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (3)
Sea Otter (1)
Sea Turtle (2)
Snow Leopard (4)
Tiger (7)

Found:Amur Leopard (1)
Removed:
Amur Leopard (1) : T1
This animal is seriously hurting because it has a beautiful coat, and people keep
hunting it for its coat. Like the leopard doesn't need its coat. Let the leopard
keep its coat, people!,

Printing In Order:
African Wild Dog (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (3)
Sea Otter (1)
Sea Turtle (2)
Snow Leopard (4)
Tiger (7)
*/
/****************************************************************************
* Step 5b :
* I then wrote removeOneKid and made sure that the remove method called the
* removeOneKid method when the node to be removed had only one kid. I then tested.
* Note that the heights of the ancestors of the removed node have been updated
****************************************************************************/
cout << "********************************************************"<<endl;
cout << "Removing, node with one kid:"<<endl;
tree->printTreeIO();
cout << endl;
tmp = tree->remove("Sea Turtle");
cout << "Removed: " << endl;
tmp->printNode(true);
cout << endl;
tree->printTreeIO();
/****************************************************************************
* My output from this:
****************************************************************************/
/*
********************************************************
Removing, node with one kid:
Printing In Order:
African Wild Dog (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (3)
Sea Otter (1)
Sea Turtle (2)
Snow Leopard (4)
Tiger (7)

Found:Sea Turtle (2)
Removed:
Sea Turtle (2) : NT
These animals have been around for 100 million years, and, yep, we're about to wipe
that out. Quite an accomplishment, in a bad way...,


Printing In Order:
African Wild Dog (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (2)
Sea Otter (1)
Snow Leopard (3)
Tiger (7)
*/
/****************************************************************************
* Step 5c :
* I then modified the remove method so that it removes a node with 2 kids. If
* the node to be removed has 2 kids, I found the replacement node, replaced the data
* in the node to be removed with the data in the replacement node, and the called
* removeNoKids or removeOneKid with the replacement node.
* Note: I replaced with the right-most of the left child. If you want results like
* mine, you should do the same.
* Note that the heights of the ancestors of the removed node have been updated
****************************************************************************/
cout << "********************************************************"<<endl;
cout << "Removing, node with two kid:"<<endl;
tree->printTreeIO();
cout << endl;
tmp = tree->remove("Giant Panda");
cout << "Removed: " << endl;
tmp->printNode(true);
cout << endl;
tree->printTreeIO();
/****************************************************************************
* My output from this:
****************************************************************************
********************************************************
Removing, node with two kid:
Printing In Order:
African Wild Dog (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (2)
Galapagos Penguins (1)
Giant Panda (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (2)
Sea Otter (1)
Snow Leopard (3)
Tiger (7)
Found:Giant Panda (5)
Removed:
Giant Panda (1) : VU
Yep, Giant Pandas are threatened too, although less so now. They're very cute.,
Printing In Order:
African Wild Dog (1)
Asian Elephant (3)
Axolotl (2)
Black-footed Ferrets (1)
Blue Whale (4)
Chimpanzees (1)
Galapagos Penguins (5)
Golden Lion Tamarins (1)
Gorilla (2)
Orangutan (6)
Rhinoceros (2)
Sea Otter (1)
Snow Leopard (3)
Tiger (7)
*/
/********************************************************************
/*If you’ve made it this far, congratulations!!!!! Now you should run
The code below, and play around.
YOu can play around with the menu interface fo the smaller test file,
and when you're satisfied everything runs, you can play around with the
larger endangered Species file.
I’m including another file with the Output of my playing around with the
Endangered Species file.
********************************************************************/
cout << "TESTING FIND MORE.." << endl;
tree->find("Tiger");
tree->find("Gorilla");

// cout << "***********************************" << endl;
// cout << "CLEARING TREE";
// tree->clearTree();
// cout <<"************************************" << endl;
// Interface interface("PracticeSpecies.txt", false);
// interface.Menu();
// interface.tree->clearTree();
// Interface interface("EndangeredSpecies.txt", true);
// interface.Menu();
return 0;
}


void readInTree(BST *tree){
	string animal[] = {"Tiger","Orangutan","Giant Panda","Blue Whale","Asian Elephant","Gorilla","Snow Leopard","Rhinoceros","Sea Turtle","Sea Otter","African Wild Dog","Amur Leopard","Axolotl","Black-footed Ferrets","Chimpanzees","Galapagos Penguins","Golden Lion Tamarins"};
	string threat[] = {"T1","T2","VU","T2","T1","VU","T1","T1","VU","T1","T1","T1","T2","T2","VU","T2","VU"};
	string info[] = {"The tigers are critically threatened. It's not good.", 
	"Orangutans are also in trouble. Because of the whole habitat loss thing.", 
	"Yep, Giant Pandas are threatened too, although less so now. They're very cute.", 
	"Blue Whales are in trouble - they eat a lot, they live in the sea, seas are kind of a mess right now.", "These are the elephants with the tiny ears. Everyone wants their tusks. Very sad.", 
	"They were on the list of endangered species, so I have to believe it is true. Jane Goodall is not happy.", 
	"Makes sense that these are endangered. They have snow in their name, and there's the whole global warming thing.", 
	"These are also endangered because of their tusks. What is it about tusks?? Just let the animal that grew 'em keep 'em!", 
	"These animals have been around for 100 million years, and, yep, we're about to wipe that out. Quite an accomplishment, in a bad way...", 
	"They live near Alaska mostly. There used to be 300,000. Now? 3000.", "Okay, so this particular dog isn't terribly cute, but it is really seriously endangered, and I don't wish for it to be extinct!",
	"This animal is seriously hurting because it has a beautiful coat, and people keep hunting it for its coat. Like the leopard doesn't need its coat. Let the leopard keep its coat, people!", 
	"No idea what this is. But it was on the list of endangered species. Should probably google it.", 
	"Get this - this ferret is only found in North America and eats animals its own size.", 
	"Yep, we're wiping out the habitat of the species most closely related to us. Good job humans!",
	"My guess is that the Galapagos Islands are going to be under water shortly, so any animal with the word 'Galapagos' in their name is probably in trouble.",
	"Poor Golden Lion Tamarins. Their habitat is going away. Poor, poor Golden Lion Tamarins."};
	for (int i = 0; i < 17; i++) {
		tree->insert(animal[i],threat[i],info[i]);
	}
	cout << endl;
}