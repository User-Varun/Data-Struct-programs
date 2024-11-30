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

void deletionAtBeginning(Node *&head)
{

    if (head == nullptr)
    {
        cout << "list is empty. exiting the program..." << endl;
        return;
    }

    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;

        delete temp;

        return;
    }

    if (head->next != head)
    {
        Node *temp = head;

        head->prev->next = temp->next;
        temp->next->prev = head->prev;
        head = head->next;

        delete temp;
    }
}

void deletionAtEnd(Node *&head)
{

    //    if list is empty
    if (head == nullptr)
    {
        cout << "list is empty" << endl;

        return;
    }

    // if list has only one node
    if (head->next == head)
    {
        Node *temp = head;
        head = nullptr;

        delete temp;
    }

    // if list has more than one node
    if (head->next != head)
    {
        Node *last = head->prev;
        Node *secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        delete last;
    }
}

void deletionAtSpecificPosition(Node *&head, int pos)
{

    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }

    if (pos < 1)
    {
        cout << "invalid position" << endl;
        return;
    }

    //    if list has only one node
    if (head->next == head || pos == 1)
    {
        Node *temp = head;

        temp->next->prev = head->prev;
        head->prev->next = temp->next;
        head = head->next;

        delete temp;
    }

    if (pos > 1)
    {
        Node *temp = head;
        int nodeCount = 1;

        while (temp->next != head && nodeCount < pos)
        {
            temp = temp->next;
            nodeCount++;
        }

        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;
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
    // deletionAtBeginning(head);
    // deletionAtEnd(head);
    deletionAtSpecificPosition(head, 3);
    traverse(head);

    return 0;
}