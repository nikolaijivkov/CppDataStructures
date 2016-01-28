#include <iostream>
#include <memory>
#include <algorithm>
//#include <list>
//#include <stack>
//#include <queue>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"


using namespace std;

int main()
{
    // Linked List example
    /*
    {
        List<int> my_list;
        my_list.push_back(3);   // 3
        my_list.push_back(5);   // 3,5
        my_list.push_back(7);   // 3,5,7
        my_list.push_front(1);  // 1,3,5,7

        my_list.push_front(-6); // -6,1,3,5,7
        my_list.push_back(36);  // -6,1,3,5,7,36

        my_list.pop_front();    // 1,3,5,7,36
        my_list.print();

        my_list.pop_back();     // 1,3,5,7
        my_list.print();

        cout << "size: " << my_list.size() << endl;
    }
    */

    // Stack(LinkedList container) example
    /*
    {
        Stack<int> my_stack;
        my_stack.push(1);
        my_stack.push(3);
        my_stack.push(5);

        while(!my_stack.empty()){
            cout << my_stack.top() << endl;
            my_stack.pop();
        }
        cout << endl;
    }
    */

    // Stack(expandable C array container) example
    /*
    {
        StackStatic<int> my_static_stack;  // data array initial size: 4
        my_static_stack.push(1);
        my_static_stack.push(3);
        my_static_stack.push(5);
        my_static_stack.push(7);
        my_static_stack.push(9);  // <- data array doubles in size: 8
        my_static_stack.push(11);
        my_static_stack.push(13);
        my_static_stack.push(15);
        my_static_stack.push(17);  // <- data array doubles in size: 16
        my_static_stack.push(19);

        while(!my_static_stack.empty()){
            cout << my_static_stack.top() << endl;
            my_static_stack.pop();
        }
        cout << endl;
    }
    */

    // Queue(LinkedList container) example
    /*
    {
        Queue<int> my_queue;

        my_queue.push(1);
        my_queue.push(3);
        my_queue.push(2);
        my_queue.push(5);
        my_queue.push(4);

        my_queue.pop();
        cout << my_queue.front() << endl;
        cout << my_queue.back() << endl;
    }
    */

    // Queue(expandable C array container) example
    /*
    {
        QueueStatic<int> my_static_queue;

        my_static_queue.push(1);
        my_static_queue.push(2);
        my_static_queue.push(3);
        my_static_queue.push(4);

        my_static_queue.pop();  // pop-ing 1

        my_static_queue.push(5);
        my_static_queue.push(6);
        my_static_queue.push(7);
        my_static_queue.push(8);
        my_static_queue.push(9);
        my_static_queue.push(10);

        my_static_queue.pop(); // pop-ing 2

        my_static_queue.push(11);
        my_static_queue.push(12);
        my_static_queue.push(13);
        my_static_queue.push(14);
        my_static_queue.push(15);
        my_static_queue.push(16);

        while(!my_static_queue.empty()){
            cout << my_static_queue.front() << endl;
            my_static_queue.pop();
        }
    }
    */

    // Tree example
    ///*
    {
        Tree<char> my_tree;
        my_tree.addNode('F');
        my_tree.addNode('B');
        my_tree.addNode('G');
        my_tree.addNode('A');
        my_tree.addNode('D');
        my_tree.addNode('C');
        my_tree.addNode('E');
        my_tree.addNode('I');
        my_tree.addNode('H');

        cout << "prefix: "; my_tree.prefixPrintTree(); cout << endl << endl;
        cout << "infix: "; my_tree.infixPrintTree(); cout << endl << endl;
        cout << "postfix: "; my_tree.postfixPrintTree(); cout << endl << endl;

    }
    //*/
//cin.get();
return 0;
}