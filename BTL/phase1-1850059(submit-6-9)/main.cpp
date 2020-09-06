//#include <iostream>
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/XArrayList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "testFuncDemo.h"
using namespace std;

int main() {
    /* YOUR CODE TO CHECK
     * Note: you should not submit this file. 
     * It should be only used to verify your implementation.
     */

    // For example:
    
    DLinkedList<int>* list = new DLinkedList<int>();
    DLinkedList<int>* list1= new DLinkedList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    cout << list->indexOf(5) << endl;
    cout << list->toString() << endl;
    list->removeItem(2);
    cout << list->toString() << endl;
    cout << list->get(0) << endl;
    list->dump();
    //
    list1->add(1);
    list1->add(2);
    list1->add(3);
    list1->add(4);
    list1->add(5);

    cout << list1->toString() << endl;
    delete list; delete list1;
     // Stack<int>* stack = new Stack<int>();
     // Queue<int>* queue = new Queue<int>();
     // stack->push(1);
     // stack->push(2);
     // stack->push(3);
     // stack->push(4);    
     // stack->push(5);
     // stack->push(6);
     // stack->pop();
     // stack->pop();
     // stack->pop();
     
     // delete stack; delete queue;
    
    listDemo();
    stackInOut();
    queueInOut();
    stackReading();
    checkBalanced();
    toBinary(8);
    toBinary(15);
    toBinary(128);
    toBinary(12);
    printReverseStr();
    cout << endl;
    
    DLinkedList<int>* l = new DLinkedList<int>();
    int item[]={19, 34, 22, 4, 8, 32, 78, 89};
    for(int i=0; i < sizeof(item)/sizeof(int);i++){
        l->add(item[i]);
    }
    for (int i = 0; i < l->size(); i++)
    {
        cout << l->get(i) << ", ";
    }
    bool isEmpty = l->empty();
    cout << endl;

    

    cout << isEmpty << endl;
    cout << l->size() << endl;
    l->clear();
    isEmpty = l->empty();
    cout << isEmpty << endl;
    cout << endl;
    cout << l->size() << endl;
    delete l;
}
