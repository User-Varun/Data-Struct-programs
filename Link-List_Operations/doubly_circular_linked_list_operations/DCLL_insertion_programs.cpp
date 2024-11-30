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

void insertionAtBeginning(Node *&head, int newData)
{

    Node *newNode = new Node(newData);

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;

        head = newNode;
    }
}

void traverse(Node *&head)
{
    if (head == nullptr)
        return;

    Node *temp = head;

    while (temp->next != head)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << temp->data << " back to " << temp->next->data << endl;
}

void insertionAtEnd(Node *&head, int userData)
{
    Node *newNode = new Node(userData);

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }
    else
    {

        Node *tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void insertionAtSpecificPositon(Node *&head, int newData, int pos)
{

    if (pos < 1)
    {
        cout << "invalid position";
        return;
    }

    Node *newNode = new Node(newData);

    if (head == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    }

    if (pos == 1)
    {
        insertionAtBeginning(head, newData);
    }

    if (pos > 1)
    {
        int counter = 1;
        Node *temp = head;

        while (temp->next != head && counter < pos - 1)
        {
            temp = temp->next;
            counter++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        // delete temp;
    }
}

int main()
{
    cout << "no of nodes: ";
    int input;
    cin >> input;

    Node *head = nullptr;

    for (int i = 1; i <= input; i++)
    {
        cout << "enter node at index " << i << ": ";
        int userData;
        cin >> userData;

        Node *newNode = new Node(userData);

        if (head == nullptr)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else
        {

            Node *tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    traverse(head);
    // insertionAtBeginning(head, 80);
    // insertionAtEnd(head, 50);
    insertionAtSpecificPositon(head, 100, 2);
    traverse(head);

    return 0;
}