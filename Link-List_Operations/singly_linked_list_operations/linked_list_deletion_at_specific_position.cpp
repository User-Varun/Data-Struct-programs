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
    cout << "null" << endl;
};

void deletionAtSpecificPosition(Node *&head, int position)
{

    // case 1;
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    // case 2;
    if (position < 1)
    {
        cout << "invalid position" << endl;

        return;
    }

    // case 3;
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return;
    }

    // case 4;
    Node *current = head;
    int i = 1;

    while (i < position - 1)
    {
        current = current->next;
        i++;
    };

    if (current == nullptr || current->next == nullptr)
    {
        cout << "invalid position" << endl;
        return;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
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

    cout << "enter the position of node to delete: ";
    cin >> input;

    cout << "***before***" << endl;
    traverse(head);

    deletionAtSpecificPosition(head, input);

    cout << "***after***" << endl;
    traverse(head);

    return 0;
}