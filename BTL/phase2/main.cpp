#include <iostream>
#include "IBST.h"
#include "ITreeWalker.h"
#include "BST.h"
#include "DLinkedList.h"
#include "Queue.h"
#include "Stack.h"

#include <vector>

using namespace std;

int main()
{
    //typedef BST<int, int*>::Entry Entry;

    BST<int,int*> tree;
    // int values[] = {50,20,80,15,60,90,7,12,18,85};
    // output: (50 (20 (15 (7[.][12])[18]) [.]) (80[60] (90[85][.])) ) 
    // int size = 10;
    // for (int i = 0; i < size; i++)
    // {
    //     tree.add(values[i]);
    // }

    // // for (int i = 0; i < size; i++)
    // // {
    // //     tree.add(Entry(values[i]), new int(values[i]);
    // // }
    
    // cout << tree.size() << endl;
    // cout << tree.toString() << endl;
    // //cout << tree.height() << endl; //h=5 is right
    
    // if(tree.height() == 5) cout << "Height of tree: " << tree.height() << endl;


    // bool found=1;
    // int key = 85; int k =99999;

    // tree.search(key,found) ;
    // if (found) cout << "found item: " << key << endl;
    // else cout << "not found item: " << key << endl;
    // tree.search(k, found);
    // if (found)
    //     cout << "found item: " << k << endl;
    // else
    //     cout << "not found item: " << k << endl;
    // tree.add(k);
    // cout << tree.size() << endl;
    // cout << tree.height() << endl;
    // tree.search(k, found);
    // if (found)
    //     cout << "found item: " << k << endl;
    // else
    //     cout << "not found item: " << k << endl;
    // cout << tree.toString() << endl;

    // tree.add(6);
    // cout << tree.toString() << endl;
    // tree.remove(6);
    // cout << "remove item: " << 6 << endl;
    // cout << tree.size() << endl;
    // cout << tree.toString() << endl;
    // tree.remove(99999);
    // cout << "remove item: " << 99999 << endl;
    // cout << tree.size() << endl;
    // cout << tree.toString() << endl;
    // tree.clear();
    // cout << "after clear tree : " << endl;
    // cout << tree.size() << endl;
    // cout << tree.height() << endl;
    // cout << tree.toString() << endl;
    
    int values[] = {50,20,80,15,60,90,7,12,18,85};
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    for (int i = 0; i < size; i++)
    {
        tree.add(values[i], &v[i]);
    }
    // cout << tree.toString() << endl;
    // DLinkedList<int *> list = tree.ascendingList();
    // DLinkedList<int *>::Iterator it;
    // int index = 0;
    // for (it = list.begin(); it != list.end(); it++)
    // {
    //     cout << **it << endl;;
    //     index += 1;
    // }
    // cout << list.toString()<< endl;

    // DLinkedList<int *> l = tree.descendingList();
    // DLinkedList<int *>::Iterator ite;
    // int index = 0;
    // stringstream ss;
    // for (ite = l.begin(); ite != l.end(); ite++)
    // {
    //     ss << **ite << ", ";
    //     index += 1;
    // }
    // cout << ss.str() << endl;
    // cout << l.toString() << endl;
    cout << tree.toString() << endl;
    DLinkedList<int *> l = tree.ascendingList();
    DLinkedList<int *>::Iterator ite;
    int index = 0;
    stringstream ss;
    for (ite = l.begin(); ite != l.end(); ite++)
    {
        ss << **ite << ", ";
        index += 1;
    }
    cout << ss.str() << endl;
    cout << l.toString() << endl;

    //FROM HERE: TEST ASCENDING LIST
    /*DLinkedList<int*> list = tree.ascendingList();
    DLinkedList<int*>::Iterator it;
    int index = 0;
    for ( it = list.begin(); it != list.end(); it++)
    {
        values[index] = **it;
        index +=1;
    }*/
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
    int values[] = {50,20,80,15,60,90,7,12,18,85};
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    */
}