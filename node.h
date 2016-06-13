//
// Created by Nikolay on 1/20/2016.
//

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

#include <iostream>

template<class T>
class Node {
private:
    bool debug = false;
public:
    T data;
    Node<T> *pNext = nullptr;
    Node<T> *pPrev = nullptr;

    Node(T in_data): data(in_data)
    {
        if(debug) std::cout << "constructing new Node with data " << data << std::endl;
    }

    ~Node()
    {
        if(debug) std::cout << "destructing Node with data " << data << std::endl;
    }
};

#endif //DATASTRUCTURES_NODE_H
