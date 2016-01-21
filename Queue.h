//
// Created by Nikolay on 1/20/2016.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <iostream>
#include <algorithm>
#include "list.h"

using namespace std;


template <class T>
class Queue{  // Queue with Linked List
private:
    bool debug = true;
    List<T> *data = nullptr;
public:
    Queue()
    {
        if(debug) cout << "constructing empty Queue (Linked List implementation)" << endl;
        data = new List<T>;
    };

    ~Queue()
    {
        if(debug) cout << "destructing Queue (Linked List implementation)" << endl;
        delete data;
    };

    void push(T n)
    {
        data->push_front(n);
    }

    void pop()
    {
        data->pop_back();
    }

    T& front() const
    {
        return data->front();
    }

    T& back() const
    {
        return data->back();
    }

    int size() const
    {
        return data->size();
    }

    bool empty() const
    {
        return data->empty();
    }
};

#endif //DATASTRUCTURES_QUEUE_H
