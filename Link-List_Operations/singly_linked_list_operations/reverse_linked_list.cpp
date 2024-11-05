#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int newData)
    {
        this->data = newData;
        this->next = nullptr;
    };
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
}

int main()
{
    cout << "Please enter no. of nodes you want in your linked list: ";
    int number_of_nodes;
    cin >> number_of_nodes;

    Node *head = nullptr;
    Node *current = nullptr;

    for (int i = 1; i <= number_of_nodes; i++)
    {
        int data;

        cout << "Enter the data for Node " << i << " :";
        cin >> data;

        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    traverse(head);

    return 0;
}