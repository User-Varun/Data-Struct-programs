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
    }
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
};

void insertionAtSpecificPosition(Node *&head, int newData, int position)
{
    Node *newNode = new Node(newData);

    //  Case: 1
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Case: 2
    int i = 1;
    Node *temp = head;

    while (temp != nullptr && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr)
    {
        cout << "invalid Position" << endl;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{

    int input;
    cout << "Enter element at first node: ";
    cin >> input;

    Node *Node1 = new Node(input);
    Node *head = Node1;

    cout << "Enter element at second node: ";
    cin >> input;

    Node *Node2 = new Node(input);
    Node1->next = Node2;

    cout << "Enter element at third node: ";
    cin >> input;

    Node *Node3 = new Node(input);
    Node2->next = Node3;

    traverse(head);
    cout << endl;
    cout << "element to insert at specific position: ";
    cin >> input;
    cout << "enter the position for insertion: ";
    int position;
    cin >> position;

    insertionAtSpecificPosition(head, input, position);
    traverse(head);

    return 0;
}