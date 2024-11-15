#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void traverse(Node *&head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

void insertionAtBeginning(Node *&head, int val)
{

    Node *newNode = new Node(val);

    // case: 1 (list is empty)
    if (head == nullptr)
    {
        cout << "list is empty, creating new list..." << endl;
        head = newNode;
        return;
    }

    // case: 2 (list is not empty)
    if (head != nullptr)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertionAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);

    // case: 1 (list is empty)
    if (head == nullptr)
    {
        cout << "list is empty, creating new list..." << endl;
        head = newNode;
        return;
    }

    // case: 2 (list is not empty)
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
};

void insertionAtSpecificPosition(int newData, int pos, Node *&head)
{

    Node *newNode = new Node(newData);

    if (pos < 1)
    {
        cout << "invalid Position" << endl;
        return;
    }

    // case 1
    if (pos == 1)
    {
        if (head == nullptr)
        {
            cout << "list is emtpy, creating new list.." << endl;
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // case 2
    if (pos > 1)
    {

        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        // case 3

        if (temp == nullptr)
        {
            cout << "invalid position" << endl;
            return;
        }

        newNode->next = temp->next;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
            newNode->prev = temp;
            temp->next = newNode;
        }
    }
};

int main()
{

    cout << "no. of nodes: ";
    int input;
    cin >> input;

    Node *head = nullptr;
    Node *current = head;

    for (int i = 1; i <= input; i++)
    {
        int data;
        cout << "enter data at node " << i << " :";
        cin >> data;

        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            current = newNode;
        }
        else
        {
            newNode->prev = current;
            current->next = newNode;
            current = current->next;
        }
    }

    cout << "val for inserting at beginning and end: ";
    int data;
    cin >> data;

    insertionAtBeginning(head, data);
    cout << "***Result after insertion at beginning***" << endl;
    traverse(head);

    insertionAtEnd(head, data);
    cout << "***Result after insertion at End***" << endl;
    traverse(head);

    return 0;
}