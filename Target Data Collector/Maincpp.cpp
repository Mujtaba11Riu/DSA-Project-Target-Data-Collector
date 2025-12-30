#include <iostream>
#include <conio.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree t;

    Person p1={"Ali", 22, "Islamabad" };
    Person p2={"Ahmed", 25, "Lahore" };
    Person p3={"Zain", 21, "Karachi" };


    t.insert(p1);
    t.insert(p2);
    t.insert(p3);

    cout<<"Inorder Traversal:"<<endl;

	t.display();

    cout<<endl<<"Searching Ahmed:"<<endl;

    if (t.search("Ahmed") != NULL){

        cout << "Found" << endl;
	}
	else
	{

        cout << "Not Found" << endl;
	}

	 cout<<endl<<"Searching Faizan:"<<endl;
    if (t.search("Faizan") != NULL){

        cout << "Found" << endl;
	}
	else
	{

        cout << "Not Found" << endl;
	}



    _getch();
    return 0;
}
