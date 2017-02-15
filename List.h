#ifndef LIST_H
#define LIST_H

#include <Node.h>
#include <iostream>

using namespace std;

template<typename NodeType>
class List
{
public:
    List(NodeType elem);
    ~List();

    void insertElement(NodeType elem);
    bool removeElement(NodeType elem);
    void printList();

private:
    Node<NodeType> *head;
    int count;
};

template<typename NodeType>
List<NodeType>::List(NodeType elem)
{
    head = new Node<NodeType>(elem);
    count = 1;
}

template<typename NodeType>
List<NodeType>::~List()
{
    Node<NodeType> *temp = head;
    if(head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
}

template<typename NodeType>
void List<NodeType>::insertElement(NodeType elem)
{
    if(head == NULL)
    {
        head = new Node<NodeType>(elem);
        count++;
        return;
    }

    Node<NodeType> *temp = head;
    while(temp->next)
        temp = temp->next;

    temp->next = new Node<NodeType>(elem);
    count++;
}

template<typename NodeType>
bool List<NodeType>::removeElement(NodeType elem)
{
    if(head == NULL)
        return false;

    if(head->data == elem)
    {
        Node<NodeType> *discard = head;
        head = head->next;
        cout<< discard << discard->data << endl;
        cout << head << discard->data << endl;

        delete discard;
        count--;
        return true;
    }

    Node<NodeType> *temp = head;
    while(temp->next && temp->next->data != elem)
        temp = temp->next;

    if(temp->next->data == elem)
    {
        Node<NodeType> *discard = temp->next;
        temp->next = temp->next->next;
        delete discard;
        count--;
        return true;
    }

    return false;
}

template<typename NodeType>
void List<NodeType>::printList()
{
    cout<< "Print List: " << endl;
    Node<NodeType> *temp = head;
    cout<<head;

    while(temp)
    {
        cout << "Node: " << temp->data << endl;
        temp = temp->next;
    }

    cout << "Count: " << count <<endl;
}

#endif // LIST_H
