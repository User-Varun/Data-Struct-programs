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

void insertionAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

void insertionAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
};

void traverse(Node *&head)
{
    Node *temp = head;
    int count = 0;

    while (temp->next != head)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
        count++;
    }
    cout << temp->data << " back to first -> " << temp->next->data << endl;

    // cout << "ran " << count << " times" << endl;
};

void insertionAtSpecificPosition(Node *&head, int val)
{

    cout << "enter the position: ";
    int pos;
    cin >> pos;

    Node *newNode = new Node(val);

    if (pos < 1)
    {
        cout << "invalid position. exiting..." << endl;

        return;
    }

    if (head == nullptr)
    {
        newNode->next = newNode;
        head = newNode;
    }

    if (pos == 1)
    {
        Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        int i = 1;

        while (temp->next != head && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
};

int main()
{

    cout << "inter no. of nodes u want: ";
    int input;
    cin >> input;

    Node *head = nullptr;
    Node *current = nullptr;

    for (int i = 1; i <= input; i++)
    {
        cout << "enter val at node " << i << ": ";
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
            current = newNode;
        }
    }
    traverse(head);
    insertionAtBeginning(head, 100);
    insertionAtEnd(head, 500);
    insertionAtSpecificPosition(head, 450);
    traverse(head);

    return 0;
}