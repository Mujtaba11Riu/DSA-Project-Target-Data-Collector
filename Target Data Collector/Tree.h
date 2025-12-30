


#include"TreeNode.h"
using namespace std;

class Tree {

private:
   
	TreeNode* root;
    void inorder(TreeNode* n);

public:
    
	Tree();
    bool isEmpty();

    TreeNode* findParent(string name);
    TreeNode* findParent2(string name);

    void insert(Person p);
	TreeNode* search(string name);
    void removeNode(string name);

    void display();

    
};