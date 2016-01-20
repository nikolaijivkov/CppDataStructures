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
class Queue{  // Queue with Linked List, base for Deque class
protected:
    bool debug = true;
    List<T> *data = nullptr;
public:
};


template <class T>
class QueueStatic{  // Queue with Expandable C Array

};

#endif //DATASTRUCTURES_QUEUE_H
