//
// Created by Nikolay on 1/25/2016.
//

#ifndef DATASTRUCTURES_TREE_H
#define DATASTRUCTURES_TREE_H

#include <iostream>
#include "node.h"

using namespace std;

template <class T>
class Tree{
private:
    bool debug = false;
    TreeNode<T> *pRoot = nullptr;

    void _deleteNodes(TreeNode<T> *currentNode=nullptr)
    {   // left child, right child, current node
        if(!currentNode) currentNode = pRoot;  // set currentNode if it's missing

        if( currentNode->pLeft) _deleteNodes(currentNode->pLeft);
        if( currentNode->pRight) _deleteNodes(currentNode->pRight);
        delete currentNode;
    }

    TreeNode<T>* _searchNode(T n, TreeNode<T> *currentNode=nullptr)
    {
        if( n == currentNode->data )  // node found
            return currentNode;
        else if( n > currentNode->data ) {  // go right
            if( currentNode->pRight )
                return _searchNode(n, currentNode->pRight);
        }
        else if( n < currentNode->data ) {  // go left
            if( currentNode->pLeft )
                return _searchNode(n, currentNode->pLeft);
        }
        return nullptr;
    }

    void _addNode(T n, TreeNode<T> *currentNode=nullptr)
    {
        if(pRoot) {
            if( n > currentNode->data ) {  // go right
                if( currentNode->pRight )
                    return _addNode(n, currentNode->pRight);
                else
                    currentNode->pRight =  new TreeNode<T>(n);
            }
            else if(  n < currentNode->data ){  // go left
                if( currentNode->pLeft )
                    return _addNode(n, currentNode->pLeft);
                else
                    currentNode->pLeft =  new TreeNode<T>(n);
            }
            else cout << "Tree elements should be unique!!!" << endl;
        }
        else
            pRoot = new TreeNode<T>(n);
    }

//    void _deleteNode(T n, TreeNode<T> **currentNode)
//    {
//        static TreeNode<T> ** lastParent = nullptr;
//        if(!currentNode){
//            cout << "Node not found" << endl;
//            return;
//        }
//
//        if(n > (*currentNode)->data){  // go right
//            lastParent = currentNode;
//            return _deleteNode(n, &(*currentNode)->pRight);
//        }
//        else if (n < (*currentNode)->data){  // go left
//            lastParent = currentNode;
//            return _deleteNode(n, &(*currentNode)->pLeft);
//        }
//        else {  // node found
//            if((*currentNode)->pLeft && (*currentNode)->pRight) {
//                TreeNode<T> *replace = findMin((*currentNode)->pRight);
//                (*currentNode)->data = replace->data;
//                lastParent = currentNode;
//                return _deleteNode(replace->data, &(*currentNode)->pRight);
//            }
//            else{
////                TreeNode<T> **link = nullptr;
////                if( (*lastParent)->pLeft == *currentNode ) {
////                    link = &(*lastParent)->pLeft;
////                    cout << "current node is left child of its parent" << endl;
////                }
////                else if( (*lastParent)->pRight == *currentNode) {
////                    link = &(*lastParent)->pRight;
////                    cout << "current node is right child of its parent" << endl;
////                }
////                else{
////                    cout << "WTF?!?!?" << endl;
////                }
//
//                if((*currentNode)->pLeft) {
//                    if( (*lastParent)->pLeft == *currentNode )
//                        (*lastParent)->pLeft = (*currentNode)->pLeft;
//                    else if( (*lastParent)->pRight == *currentNode)
//                        (*lastParent)->pRight = (*currentNode)->pLeft;
//                }
//
//
//                else if((*currentNode)->pRight) {
//                    if( (*lastParent)->pLeft == *currentNode )
//                        (*lastParent)->pLeft = (*currentNode)->pRight;
//                    else if( (*lastParent)->pRight == *currentNode)
//                        (*lastParent)->pRight = (*currentNode)->pRight;
//                }
////                delete *currentNode;
//            }
//        }
//    }


public:
    Tree()
    {
        if(debug) cout << "constructing empty Tree" << endl;
    }

    ~Tree()
    {
        if(debug) cout << "destructing Tree" << endl;
        if(pRoot) _deleteNodes();
    };

    TreeNode<T>* findMin(TreeNode<T> *currentNode=nullptr)
    {
        if(!currentNode) currentNode = pRoot;

        if(currentNode->pLeft)
            return findMin(currentNode->pLeft);
        else{
            //cout << currentNode->data << endl;
            return currentNode;
        }
    }

    void addNode(T n)
    {
        return _addNode(n, pRoot);
    }

    TreeNode<T>* searchNode(T n)
    {
        if(pRoot) return _searchNode(n, pRoot);
        else{
            cout << "tree is empty" << endl;
            return nullptr;
        }
    }

//    void deleteNode(T n)
//    {
//        if(pRoot) return _deleteNode(n, &pRoot);
//        else cout << "tree is empty" << endl;
//    }

    //https://en.wikipedia.org/wiki/Tree_traversal
    void prefixPrintTree(TreeNode<T> *currentNode=nullptr)
    {   // current node, left child, right child
        if(!currentNode) currentNode = pRoot;  // set currentNode if it's missing

        cout << currentNode->data << " ";
        if( currentNode->pLeft) prefixPrintTree(currentNode->pLeft);
        if( currentNode->pRight) prefixPrintTree(currentNode->pRight);
    }

    void infixPrintTree(TreeNode<T> *currentNode=nullptr)
    {   // left child, current node, right child
        if(!currentNode) currentNode = pRoot;  // set currentNode if it's missing

        if( currentNode->pLeft) infixPrintTree(currentNode->pLeft);
        cout << currentNode->data << " ";
        if( currentNode->pRight) infixPrintTree(currentNode->pRight);
    }

    void postfixPrintTree(TreeNode<T> *currentNode=nullptr)
    {   // left child, right child, current node
        if(!currentNode) currentNode = pRoot;  // set currentNode if it's missing

        if( currentNode->pLeft) postfixPrintTree(currentNode->pLeft);
        if( currentNode->pRight) postfixPrintTree(currentNode->pRight);
        cout << currentNode->data << " ";
    }
};


#endif //DATASTRUCTURES_TREE_H
