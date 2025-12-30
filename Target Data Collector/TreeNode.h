

#include <iostream>
#include <conio.h>
#include "Person.h"
using namespace std;

class TreeNode {

private:

	Person data;
    TreeNode* left;
    TreeNode* right;

public:


    TreeNode(Person p);

	Person getData();

    TreeNode* getLeft();
    TreeNode* getRight();

    void setLeft(TreeNode* left);
    void setRight(TreeNode* right);

};



