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


template <class T>
class QueueStatic{  // Stack with Expandable C Array
private:
    bool debug = true;
    int length = 0;
    int arr_length = 4;
    T *data = nullptr;
    int head = 0;
    int tail = 0;
public:
    QueueStatic()
    {
        if(debug) cout << "constructing empty Queue (Expandable C Array implementation)" << endl;
        data = new T[arr_length];
    };

    ~QueueStatic()
    {
        if(debug) cout << "destructing Queue (Expandable C Array implementation)" << endl;
        delete[] data;
    };

    void push(T n)
    {
        if(length == arr_length){
            //throw length_error("Queue overflow");
            if(debug) cout << "data_array expanding at element " << n << endl;
            T *new_data = new T[arr_length*2];  // make new data array, twice as big as the old one

            copy(data+head, data+arr_length, new_data);
            copy(data, data+tail, new_data+(arr_length-head));

            delete[] data;  // deleting the old data array
            data = new_data;  // fixing the data pointer to point to the new data array

            arr_length *= 2;

            head = 0;
            tail = length;
        }

        data[tail] = n;
        length++;
        tail++;
        if(tail >= arr_length) tail = 0;

    }

    void pop()
    {
        if(length==0) throw length_error("No elements in Queue");

        // how to destroy elements ?!
        // maybe we have to use T **data to point to dynamically newed elements in order to delete them we pop
        // data[head] = 0;

        length--;
        head++;
        if(head >= arr_length) head = 0;
    }

    T& front() const
    {
        if(length==0) throw length_error("No elements in Queue");
        return data[head];
    }

    T& back() const
    {
        if(length==0) throw length_error("No elements in Queue");
        return tail ?: data[tail-1], data[head+length-1];
    }

    int size() const
    {
        return length;
    }

    bool empty() const
    {
        return length == 0;
    }
};


#endif //DATASTRUCTURES_QUEUE_H
