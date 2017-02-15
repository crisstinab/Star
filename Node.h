#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

template<typename NodeType>
class Node {
public:
    Node(NodeType d);
    ~Node();

    NodeType data;
    Node<NodeType> *next;
};

template<typename NodeType>
Node<NodeType>::Node(NodeType d)
{
    data = d;
    next = NULL;
}

template<typename NodeType>
Node<NodeType>::~Node()
{
    if(next)
        delete next;
}

#endif // NODE_H
