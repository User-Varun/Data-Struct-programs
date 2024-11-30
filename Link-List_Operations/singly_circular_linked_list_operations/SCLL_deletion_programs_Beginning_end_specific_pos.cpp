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

    if (head == nullptr)
    {
        cout << "list is empty: from traverse fn." << endl;

        return;
    }

    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " back to " << temp->next->data << endl;
};

void deletionAtBeginning(Node *&head)
{

    if (head == nullptr)
    {
        cout << "list is empty: from deletion At beginninng fn." << endl;
        return;
    }

    // if list has  one node only;
    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;
        delete temp;

        cout << "node is deleted. list is empty now." << endl;

        return;
    }

    // if list has more than one node
    Node *temp = head;
    Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    head = head->next;
    current->next = head;

    delete temp;
}

void deletionAtEnd(Node *&head)
{

    if (head == nullptr)
    {
        cout << "list is empty: from deletion at end fn. " << endl;

        return;
    }

    // if list has only one node;
    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;
        delete temp;

        cout << "node is deleted. list is empty now." << endl;
        return;
    }

    // if list is more than one node;
    Node *current = head;
    while (current->next->next != head)
    {
        current = current->next;
    }

    Node *temp = current->next->next;

    current->next = head;

    delete temp;

    return;
}

void deletionAtSpecificPostition(Node *&head)
{
    cout << "enter position: ";
    int pos;
    cin >> pos;

    if (pos < 1)
    {
        cout << "invalid position" << endl;
        return;
    }

    if (head == nullptr)
    {
        cout << "list is empty." << endl;
        return;
    }

    int nodeCount = 1;
    Node *tempPtr = head;

    while (tempPtr->next != head)
    {
        nodeCount++;
        tempPtr = tempPtr->next;
    }

    cout << "node count: " << nodeCount << endl;

    if (pos > nodeCount)
    {
        cout << "invalid position: deletion at specific position " << endl;
        return;
    }

    // if node has only one node or if pos is 1;
    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;
        delete temp;

        cout << "node is deleted. list is empty now." << endl;
        return;
    }

    // if list has more than one node;
    Node *current = head;

    for (int i = 1; current->next != head, i < pos - 1; i++)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}

int main()
{
    cout << "no. of nodes: ";
    int input;
    cin >> input;

    Node *head = nullptr;
    Node *current = nullptr;

    for (int i = 1; i <= input; i++)
    {

        cout << "enter value at node " << i << ": ";
        int newData;
        cin >> newData;

        Node *newNode = new Node(newData);

        if (head == nullptr)
        {
            newNode->next = newNode;
            head = newNode;
            current = newNode;
        }
        else
        {
            current->next = newNode;
            newNode->next = head;
            current = current->next;
        }
    }

    traverse(head);
    // deletionAtBeginning(head);
    // deletionAtEnd(head);
    deletionAtSpecificPostition(head);
    traverse(head);

    return 0;
}