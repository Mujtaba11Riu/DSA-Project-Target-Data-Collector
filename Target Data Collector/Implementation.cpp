#include"Tree.h"
#include<iostream>
using namespace std;

//...........Tree Node implementation................

TreeNode::TreeNode(Person p)
{
	data=p;
	right = NULL;
	left = NULL;
}

Person TreeNode::getData()
{
	return data;
}


TreeNode* TreeNode::getLeft()
{
	return left;
}

TreeNode* TreeNode::getRight()
{
	return right;
}


void TreeNode::setRight(TreeNode* right)
{
	this->right = right;
}


void TreeNode::setLeft(TreeNode* left)
{
	this->left = left;
}




//.......... Tree Implementation ...




Tree::Tree()
{
	root = NULL;
}

bool Tree::isEmpty()
{
	if (root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}






//Function FindParent


TreeNode* Tree::findParent(string name)
{
	TreeNode* temp = root;
	TreeNode* parent = NULL;

	if (isEmpty())
	{
		return NULL;
	}
	else 
	{
		while (temp != NULL)
		{
			if (temp->getData().name == name)
			{
				cout << "Duplication Not Allowed. Exiting the function";
				return NULL;
			}
			else if (name < temp->getData().name)
			{
				parent = temp;
				temp = temp->getLeft();
			}
			else 
			{
				parent = temp;
				temp = temp->getRight();
			}

		}

		// end of loop
		return parent;
	}
}




//Function Find Parent2

TreeNode* Tree::findParent2(string name) {

	TreeNode* temp = root;
	TreeNode* parent = NULL;

	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->getData().name == name)
			{
				return parent;
			}
			else if (name < temp->getData().name )
			{
				parent = temp;
				temp = temp->getLeft();
			}
			else 
			{
				parent = temp;
				temp = temp->getRight();
			}
		}// end of loop
		//return parent;
	}
}




//Function Insert

void Tree::insert(Person p){
	

	if (isEmpty())
	{
		
		root = new TreeNode(p);
	}

	else
	{
		TreeNode* parent = findParent(p.name); //finding place to insert
		if (parent != NULL)
		{
			TreeNode* newNode = new TreeNode(p); //creating new node

			if (p.name < parent ->getData().name)
			{
				parent->setLeft(newNode);
			}
			else
			{
				parent->setRight(newNode);
			}
		}
	}
}





// Function  Search 

TreeNode* Tree::search(string name)
 
{
	TreeNode* temp = root;

	
	if (isEmpty())
	{
		return NULL;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->getData().name == name)
			{
				return temp;
			}
			else if (name < temp->getData().name )
			{
				temp = temp->getLeft();
			}
			else
			{

				temp = temp->getRight();
			}
		}

		// end of loop
		return NULL;
	}
}






// Function Display

void Tree::display()
{
	inorder(root);
}

void Tree::inorder(TreeNode* n)

{

	if (n != NULL)

	{
		inorder(n->getLeft());
		cout <<"\n\nName : "<< n->getData().name << endl;
		
		cout<<"Age : "<< n->getData().age << endl;

		cout <<"Adress : "<< n->getData().address << endl;
		inorder(n->getRight());
	}
}







// Function RemoveNode



void Tree::removeNode(string name)
{
	TreeNode* target = search(name);
	
	if (target == NULL)
	{
		cout << "Not found" << endl;
		return;
	}

		TreeNode* parent = findParent2(name);

		//case 1 leaf node 

		if (target->getLeft() == NULL && target->getRight() == NULL) 
		{
			if(target ==root){

				delete root;
				root = NULL;
			}
			
			else if (parent->getLeft() == target)
			{
				parent->setLeft(NULL);
				delete target;
			}

			else
			
			{
				parent->setRight(NULL);

				delete target;
			}

		} //end of if

	

		//Case 2 One Child

	else if (target->getLeft() == NULL || target->getRight() == NULL)
	{
		TreeNode* child;

		if (target->getLeft() != NULL){

			child = target->getLeft();
		}

		else
		{

			child = target->getRight();
		}

		if (target == root)
		{
			root = child;
			delete target;
		}
		
		else if (parent->getLeft() == target)
		{
			parent->setLeft(child);
			delete target;
		}
		
		else
		{
			parent->setRight(child);
			delete target;
		}
	}//end of elseif




	// ---------- Case 3: Two Children ----------
	
	
	else

	{
		TreeNode* successorParent = target;
		TreeNode* successor = target->getRight();

		// Find inorder successor (smallest in right subtree)
	
		while (successor->getLeft() != NULL)
		
		{
			successorParent = successor;
			successor = successor->getLeft();
		
		}

		// Copy successor data into target
		
		target->getData() = successor->getData();

		// Delete successor
		
		if (successorParent->getLeft() == successor)
			{
				successorParent->setLeft(successor->getRight());
		
		}
		else {

			successorParent->setRight(successor->getRight());
		}
		
		delete successor;
	}
}