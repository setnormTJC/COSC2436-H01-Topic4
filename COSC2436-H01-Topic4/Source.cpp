#include <iostream>

using namespace std;

struct Node
{
    int data; 

    Node* link; 

    //Node()
    //{

    //}
};

int main()
{

    Node* firstNode = new Node; 
    firstNode->data = 234; 
    firstNode->link = nullptr;

    Node* secondNode = new Node; 
    secondNode->data = 126; 
    secondNode->link = nullptr; 

    //UPDATE the address of first node's link: (so that it points to secondNode)
    firstNode->link = secondNode; 


    Node* thirdNode = new Node; 
    thirdNode->data = -256; 
    thirdNode->link = nullptr; 

    secondNode->link = thirdNode; 


    cout << firstNode->link->link->data << endl; 

    ////cout << firstNode.data << endl; 
    ////cout << firstNode.link << endl; 

    ////cout << &secondNode << endl; 
    //cout << firstNode->link->data << endl; 
    //cout << secondNode->data << endl; 

    ////cout << secondNode.link << endl; 

    return 0;
}