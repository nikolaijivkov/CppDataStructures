//
// Created by Nikolay on 1/20/2016.
//

#ifndef DATASTRUCTURES_LIST_H
#define DATASTRUCTURES_LIST_H

#include <iostream>
#include "node.h"

using namespace std;


template<class T>
class List {
private:
    bool debug = false;
    int length = 0;
    Node<T> *pTail = nullptr;  // points to the last inserted element
    Node<T> *pHead = nullptr;  // point to the first inserted element
public:
    List()
    {
        if(debug) cout << "constructing empty List" << endl;
    }

    ~List()
    {
        if(debug) cout << "destructing List" << endl;

        Node<T> *pNext, *pCurr = pHead;
        while (pCurr) {
            pNext = pCurr->pNext;
            delete pCurr;
            pCurr = pNext;
        }
    }

    void push_back(T n)  // add to pTail
    {
        if(debug) cout << "adding new Node to Tail" << endl;

        Node<T> *pNode = new Node<T>(n);

        if (!pTail) {  // inserting the first element ever
            pTail = pHead = pNode;
        }
        else {
            pTail->pNext = pNode;  // fix pNext of the last element
            pNode->pPrev = pTail;  // fix pPrev of current element
            pTail = pNode;         // move pTail to current element position
        }
        length++;
    }

    void push_front(T n)  // add to pHead
    {
        if(debug) cout << "adding new Node to Head" << endl;

        Node<T> *pNode = new Node<T>(n);

        if (!pTail) {  // inserting the first element ever
            pTail = pHead = pNode;
        }
        else{
            pHead->pPrev = pNode;  // fix pPrev of the first element
            pNode->pNext = pHead;  // fix pNext of current element
            pHead = pNode;         // move pHead to current element position
        }
        length++;
    }

    T& back() const  // peek pTail
    {
        return pTail->data;
    }

    T& front() const  // peek pTail
    {
        return pHead->data;
    }

    void pop_back() // remove pTail
    {
        if(pTail){
            Node<T> *pNodeBeforeTail = pTail->pPrev;  // possibly nullptr

            delete pTail;
            if (pNodeBeforeTail) pNodeBeforeTail->pNext = nullptr;
            pTail = pNodeBeforeTail;

            length--;

            if(!length) pHead = pTail = nullptr;
        }
    }

    void pop_front() // remove pHead
    {
        if(pHead){
            Node<T> * pNodeAfterHead = pHead->pNext;

            delete pHead;
            if (pNodeAfterHead) pNodeAfterHead->pPrev = nullptr;  // if element exist
            pHead = pNodeAfterHead;

            length--;

            if(!length) pHead = pTail = nullptr;
        }
    }

    int size() const
    {
        return length;
    }

    bool empty() const
    {
        return length == 0;
    }

    void print() const
    {
        Node<T> *pCurr = pHead;

        while (pCurr) {
            cout << pCurr->data << " ";
            pCurr = pCurr->pNext;
        }
        cout << endl;
    }
};


#endif //DATASTRUCTURES_LIST_H
