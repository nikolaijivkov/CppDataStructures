//
// Created by Nikolay on 1/20/2016.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <iostream>
#include <algorithm>
#include "list.h"

using namespace std;


template <class T>
class Stack{  // Stack with Linked List
private:
    bool debug = false;
    List<T> *data = nullptr;
public:
    Stack()
    {
        if(debug) cout << "constructing empty Stack (Linked List implementation)" << endl;
        data = new List<T>;
    };

    ~Stack()
    {
        if(debug) cout << "destructing Stack (Linked List implementation)" << endl;
        delete data;
    };

    void push(T n)
    {
        data->push_back(n);
    }

    void pop()
    {
        data->pop_back();
    }

    T& top() const
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
class StackStatic{  // Stack with Expandable C Array
private:
    bool debug = false;
    int length = 0;
    int arr_length = 4;
    T *data = nullptr;
public:
    StackStatic()
    {
        if(debug) cout << "constructing empty Stack (Expandable C Array implementation)" << endl;
        data = new T[arr_length];
    };

    ~StackStatic()
    {
        if(debug) cout << "destructing Stack (Expandable C Array implementation)" << endl;
        delete[] data;
    };

    void push(T n)
    {
        length++;
        if(length>arr_length){
            if(debug) cout << "data_array expanding at element " << n << endl;
            T *new_data = new T[arr_length*2];  // make new data array, twice as big as the old one
            copy(data, data+arr_length, new_data);

            delete[] data;  // deleting the old data array
            data = new_data;  // fixing the data pointer to point to the new data array

            arr_length *= 2;
        }
        data[length-1] = n;  // element 5 is actually data[4] and that's just how it works
    }

    void pop()
    {
        if(length==0) throw length_error("No elements in Stack");

        // how to destroy elements ?!
        // maybe we have to use T **data to point to dynamically newed elements in order to delete them we pop
        length--;
    }

    T& top() const
    {
        if(length==0) throw length_error("No elements in Stack");
        return data[length-1];
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


#endif //DATASTRUCTURES_STACK_H
