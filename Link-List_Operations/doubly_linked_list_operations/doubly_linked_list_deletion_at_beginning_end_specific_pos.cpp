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
    cout << "null" << endl;
};

void deletionAtBeginning(Node *&head)
{

    // case 1: (list is empty)
    if (head == nullptr)
    {
        cout << "list is empty, creating new List..";
        return;
    }

    Node *temp = head;
    head->next->prev = nullptr;
    head = head->next;

    delete temp;
};

void deletionAtEnd(Node *&head)
{

    // case 1: list is empty
    if (head == nullptr)
    {
        cout << "list is empty, exiting the program.." << endl;
        return;
    }
    // case 2: only one node
    if (head->next == nullptr)
    {
        Node *temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;

        return;
    }

    // case 3: list has more than 1 node
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
};

void deletionAtSpecificPosition(int pos, Node *&head)
{
    // case 1: list is empty;
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    // case 2: pos < 1
    if (pos < 1)
    {
        cout << "invalid position" << endl;
        return;
    }
    // case 3: pos == 1
    if (pos == 1)
    {

        Node *temp = head;
        head = head->next;

        if (temp->next != nullptr)
        {
            head->prev = nullptr;
        }

        delete temp;
        return;
    }
    // case 4: pos > 1
    Node *temp1 = head;

    for (int i = 1; i < pos - 1; i++)
    {
        temp1 = temp1->next;
    }

    if (temp1 == nullptr || temp1->next == nullptr)
    {
        cout << "invalid Position" << endl;
        return;
    }

    Node *current = temp1->next;
    temp1->next = current->next;

    if (current->next != nullptr)
    {
        current->next->prev = temp1;
    }

    delete current;
};

int main()
{
    cout << "no. of nodes: ";
    int input;
    cin >> input;

    Node *head = nullptr;
    Node *current = nullptr;

    for (int i = 1; i <= input; i++)
    {
        cout << "enter data at node " << i << ": ";
        int newData;
        cin >> newData;

        Node *newNode = new Node(newData);

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

    int pos = 1;

    traverse(head);
    deletionAtSpecificPosition(pos, head);
    traverse(head);

    return 0;
}