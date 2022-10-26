#include <iostream>
#include <stdexcept>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node() = default;

    Node(int d) {
        this->data = d;
        next = nullptr;
        prev = nullptr;
    }

};

class D_LinkedList
{

private:
    Node* head;
    Node* tail;

public:
    D_LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~D_LinkedList()
    {
        Node *curr = head;

        while(curr != nullptr)
        {
            Node *tmp = curr;
            curr = curr->next;
            delete tmp;
        }
    }

    void prepend(int d);
    void append (int d);

    void delete_first();
    void delete_last();

    void print();

};

void D_LinkedList:: prepend(int d)
{
    Node *node = new Node(d);

    //if the list is empty
    if(head == nullptr)
    {
        head = tail = node;
    }

    else
    {
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }
}

void D_LinkedList:: append(int d)
{
    Node *node = new Node(d);

    //if the list is empty
    if(head == nullptr)
    {
        head = tail = node;
    }

    else
    {
        node->prev = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }
}

void D_LinkedList:: delete_first()
{
    //if empty
    if(head == nullptr)
        throw underflow_error("The list is empty");

    //otherwise
    (head->next)->prev == nullptr;
    head = head->next;

}

void D_LinkedList:: delete_last()
{
    //if empty
    if(head == nullptr)
        throw underflow_error("The list is empty");

    //otherwise
    (tail->prev)->next = nullptr;
    tail = tail->prev;

}

void D_LinkedList:: print()
{
    Node *curr = head;

    while(curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
