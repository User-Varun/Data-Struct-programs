#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    };
};

void insertionAtBeginning(Node *&head, int newData)
{

    Node *node2 = new Node(newData);
    node2->next = head;
    head = node2;
};

void traverse(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    };
    cout << "null";
}

int main()
{

    cout << "Enter the data you want in your first Node: ";
    int input;
    cin >> input;

    Node *node1 = new Node(input);
    Node *head = node1;

    // Insertion at beginning code starts here
    cout << "Enter the data to be inserted at beginning: ";
    int input2;
    cin >> input2;

    insertionAtBeginning(head, input2);

    //  linked list traversal starts here
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return 0;
    }
    else
    {
        traverse(head);
    }

    return 0;
}
