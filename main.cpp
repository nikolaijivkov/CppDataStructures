#include <iostream>
#include <memory>
#include <algorithm>
#include "list.h"
#include "stack.h"

using namespace std;

int main()
{
//    {   // Linked List exercise
//        List<int> my_list;
//        my_list.push_back(3);   // 3
//        my_list.push_back(5);   // 3,5
//        my_list.push_back(7);   // 3,5,7
//        my_list.push_front(1);  // 1,3,5,7
//
//        my_list.push_front(-6); // -6,1,3,5,7
//        my_list.push_back(36);  // -6,1,3,5,7,36
//
//        my_list.pop_front();    // 1,3,5,7,36
//        my_list.print();
//
//        my_list.pop_back();     // 1,3,5,7
//        my_list.print();
//
//        cout << "size: " << my_list.size() << endl;
//    }

//    {
//        Stack<int> my_stack;
//        my_stack.push(1);
//        my_stack.push(3);
//        my_stack.push(5);
//
//        while(!my_stack.empty()){
//            cout << my_stack.top() << endl;
//            my_stack.pop();
//        }
//        cout << endl;
//    }

    {
        StackStatic<int> my_static_stack;  // data array size: 4
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

    //cin.get();
    return 0;
}