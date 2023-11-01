#include <iostream>

#include<queue>

using namespace std;

template<typename T> 
struct Node
{
    T info; 

    Node<T>* link; 
};

template<typename T>
class LinkedList
{

private:
    int nodeCount; //not mandatory, but convenient
    Node<T>* first;
    Node<T>* last;

public: 
    LinkedList()
    {
        nodeCount = 0;
        first = NULL; //or nullptr keyword, or 0
        last = NULL;
    }

    void print() {

        cout << "List contents: " << endl; 

        Node<T>* current;
        current = first;
        while (current != NULL) {
            cout << current->info << " ";
            current = current->link;
        }

        cout << "\n";
    }//end print() function

    int length() { return nodeCount; }

    T getLastNodeContents()
    {
        return last->info; 
    }

    void insertFirst(const T& newInfo)
    {
        Node<T>* newNode = new Node<T>;
        newNode->info = newInfo;

        newNode->link = first;

        first = newNode; 

        if (last == NULL)
        {
            last = newNode;
            //if newNode is the only node,
            //it is both first and last
        }

        nodeCount++; 
    }
    //searchForNodeWithValue()

    void insertAfter(Node<T>* previous, T insertedValue)
    {
        Node<T>* newNode = new Node<T>;
        newNode->info = insertedValue;

        //Diagram on next slides walks through two lines below:
        newNode->link = previous->link;
        previous->link = newNode;

        nodeCount++; 
    }


    //insertAfterGivenNode(Node, int valueToInsert)
    Node<T>* getNode(int nodePosition)
    {
        Node<T>* current = new Node<T>;
        current = first;
        int i = 0;
        while (i < nodePosition)
        {
            current = current->link;
            i++;
        }
        return current;
    }

    bool searchForNodeWithValue(T targetValue)
    {
        Node<T>* current = new Node<T>; 

        current = first; 

        bool isFound = false; 
        

        int nodeCounter = 0; 
        while (current != NULL && !isFound)
        {
            if (current->info == targetValue)
            {
                isFound = true; 
            }

            else
            {
                current = current->link;
                nodeCounter++; 
            }
        } //end while

        cout << "Node counter final value is: " << nodeCounter << endl; 
        return isFound; 
    } //end `search`
};


int main()
{
    LinkedList<char> charList; 
    charList.insertFirst('a');

    charList.insertFirst('c'); //c a 

    Node<char>* previousNode = charList.getNode(0);  //Node containing 'c'

    charList.insertAfter(previousNode, 'b');

    Node<char>* ANOTHERpreviousNode = charList.getNode(1);  //Node containing 'b'

    charList.insertAfter(ANOTHERpreviousNode, '9');


    charList.print();  //c b 9 a?
    cout << "length: " << charList.length() << endl; //4? 

    cout << "\n\n" << "Is the value 'b' in the list? " << endl; 
    cout << std::boolalpha << charList.searchForNodeWithValue('b') << endl; 

    //cout << "LAST element is: " << charList.getLastNodeContents() << endl; 
    //Node* firstNode = new Node; 
    //firstNode->data = 234; 
    //firstNode->link = nullptr;

    //Node* secondNode = new Node; 
    //secondNode->data = 126; 
    //secondNode->link = nullptr; 

    ////UPDATE the address of first node's link: (so that it points to secondNode)
    //firstNode->link = secondNode; 


    //Node* thirdNode = new Node; 
    //thirdNode->data = -256; 
    //thirdNode->link = nullptr; 

    //secondNode->link = thirdNode; 


    //cout << firstNode->link->link->data << endl; 

    ////cout << firstNode.data << endl; 
    ////cout << firstNode.link << endl; 

    ////cout << &secondNode << endl; 
    //cout << firstNode->link->data << endl; 
    //cout << secondNode->data << endl; 

    ////cout << secondNode.link << endl; 

    return 0;
}