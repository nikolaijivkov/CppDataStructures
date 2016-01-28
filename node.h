//
// Created by Nikolay on 1/20/2016.
//

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

#include <iostream>
using namespace std;


template<class T>
class Node {
public:
    bool debug = false;
    T data;
    Node<T> *pNext = nullptr;
    Node<T> *pPrev = nullptr;

    Node(T in_data): data(in_data)
    {
        if(debug) cout << "constructing new Node with data " << data << endl;
    }

    ~Node()
    {
        if(debug) cout << "destructing Node with data " << data << endl;
    }
};


template<class T>
class TreeNode {
public:
    bool debug = false;
    T data;
    TreeNode<T> *pLeft = nullptr;
    TreeNode<T> *pRight = nullptr;

    TreeNode(T in_data): data(in_data)
    {
        if(debug) cout << "constructing new Node with data " << data << endl;
    }

    ~TreeNode()
    {
        if(debug) cout << "destructing Node with data " << data << endl;
    }
};

#endif //DATASTRUCTURES_NODE_H
