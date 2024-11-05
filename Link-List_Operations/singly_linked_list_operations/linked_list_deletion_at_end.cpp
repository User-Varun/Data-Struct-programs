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

void deletionAtEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    if (head->next == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return;
    }

    Node *current = head;
    while (current->next->next != nullptr)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = nullptr;
    delete temp;
};

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

    cout << "***Before***" << endl;
    traverse(head);
    cout << endl;

    deletionAtEnd(head);
    cout << "***After***" << endl;
    traverse(head);

    return 0;
}