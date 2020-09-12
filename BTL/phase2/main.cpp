#include <iostream>
#include "IBST.h"
#include "BST.h"
#include "DLinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <vector>

using namespace std;

int main()
{
    typedef BST<int, int*>::Entry Entry;
    BST<int,int*> tree;
    int values[] = {50,20,80,15,60,90,7,12,18,85};
    // output: (50 (20 (15 (7[.][12])[18]) [.]) (80[60] (90[85][.])) ) 
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        tree.add(values[i]);
    }
    // for (int i = 0; i < size; i++)
    // {
    //     tree.add(Entry(values[i]), new int(values[i]);
    // }
    cout << tree.size() << endl;
    cout << tree.toString() << endl;
    cout << tree.height() << endl; //h=5
    if(tree.height() == 5) cout << "smt" << endl;

    //FROM HERE: TEST ASCENDING
    DLinkedList<int*> list = tree.ascendingList();
    DLinkedList<int*>::Iterator it;
    int index = 0;
    for ( it = list.begin(); it != list.end(); it++)
    {
        values[index] == **it;
        index +=1;
    }
    //END
    
    /*
                    50  
                20      80
               /       /  \
              15      60   90
             /  \            \
            7    18           85
            \
             12
    */
   
}