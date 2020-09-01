#include <iostream>
#include "/home/vietskr/Desktop/DSA/BTL/phase1/list/SLinkedList.h"
#include "/home/vietskr/Desktop/DSA/BTL/phase1/list/DLinkedList.h"
#include "/home/vietskr/Desktop/DSA/BTL/phase1/list/XArrayList.h"
#include "/home/vietskr/Desktop/DSA/BTL/phase1/stacknqueue/Stack.h"
#include "/home/vietskr/Desktop/DSA/BTL/phase1/stacknqueue/Queue.h"

using namespace std;

int main() {
    /* YOUR CODE TO CHECK
     * Note: you should not submit this file. 
     * It should be only used to verify your implementation.
     */

    // For example:

    DLinkedList<int>* list = new DLinkedList<int>();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    cout << list->indexOf(-1) << endl;
    cout << list->toString() << endl;
    list->removeItem(2);
    cout << list->toString() << endl;
    list->dump();
}
