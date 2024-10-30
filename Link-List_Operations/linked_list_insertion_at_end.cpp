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

void insertionAtEnd(Node *&head, int newData)
{
    Node *newNode = new Node(newData);

    // Case: 1--- List is empty
    if (head == nullptr)
    {
        cout << "list is empty, creating new node..." << endl;
        Node *head = newNode;
        traverse(head);
    }
    else
    {
        // Case: 2--- list is not empty
        cout << "list is not empty , inserting element at end..." << endl;
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        traverse(head);
    }
};

int main()
{
    int input;
    cout << "Enter element at first node: ";
    cin >> input;

    Node *Node1 = new Node(input);
    Node *head = Node1;

    cout << "enter the element to be inserted at: ";
    cin >> input;

    insertionAtEnd(head, input);

    return 0;
}