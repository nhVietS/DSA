#include <iostream>
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/XArrayList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "testFuncDemo.h"
#include <vector>

using namespace std;

int main()
{   
    stackInOut();
    queueInOut();
    stackReading();
    checkBalanced();
    toBinary(1000);
    toBinary(8);
    toBinary(1024);
    printReverseStr();
    
    DLinkedList<int> *l = new DLinkedList<int>();
    
    cout << l->toString() << endl;
    //10/15/2/6/4/7/40/8
    l->add(10);
    l->add(15);
    l->add(2);
    l->add(6);  
    l->add(4);
    l->add(7);
    l->add(40);
    l->add(8);
    cout << l->toString() << endl;

    l->clear();
    cout << l->toString() << endl;
    l->add(10);
    l->add(15);
    l->add(2);
    l->add(6);
    l->add(4);
    l->add(7);
    l->add(40);
    l->add(8);
    cout << l->toString() << endl;
    int index[]= {0,1,5,3,2,1,1,0};
    for (int i = 0; i < 8; i++)
    {
        cout << index[i] << endl;
        cout << "Before removal: " << l->toString() << endl;
        l->removeAt(index[i]);
        cout << "After removal: " << l->toString() << endl;
    }
    
    for (int i=0;i<8;i++)
    {
        cout << "Add at index: " << i << endl;
        cout << "Before add: " << l->toString() << endl;
        l->add(i,i*i);
        cout << "After add: " << l->toString() << endl;
    }

    l->add(4,2222);
    l->add(6,33232);
    cout << l->toString() << endl;
    cout << "Get index: " << l->get(4) << endl;
    cout << "Get index: " << l->get(6) << endl;
    cout << "Get index: " << l->get(0) << endl;
    cout << "Get index: " << l->get(l->size()-1) << endl;
    cout << l->toString() << endl;

    cout << "SIZE =: " <<l->size() << endl;
    cout << "INDEX OF: " << l->indexOf(4) << endl;
    cout << "INDEX OF: " << l->indexOf(2222) << endl;
    cout << "INDEX OF: " << l->indexOf(49) << endl;
    cout << "INDEX OF: " << l->indexOf(33232) << endl;
    cout << "INDEX OF: " << l->indexOf(-10) << endl;
    cout << l->toString() << endl;

    cout << "REMOVE ITEM " << l->removeItem(2222) << endl;
    cout << "REMOVE ITEM " << l->removeItem(49) << endl;
    cout << "REMOVE ITEM " << l->removeItem(33232) << endl;
    cout << "REMOVE ITEM " << l->removeItem(-10) << endl;
    cout << "INDEX OF: " << l->indexOf(2222) << endl;
    cout << "INDEX OF: " << l->indexOf(49) << endl;
    cout << "INDEX OF: " << l->indexOf(33232) << endl;
    cout << "INDEX OF: " << l->indexOf(-10) << endl;
    cout << l->toString() << endl;


    l->add(4,2222);
    l->add(6,33232);
    cout << l->toString() << endl;
    cout << "CONTAINS: " << l->contains(2222) << endl;
    cout << "CONTAINS: " << l->contains(49) << endl;
    cout << "CONTAINS: " << l->contains(33232) << endl;
    cout << "CONTAINS: " << l->contains(-10) << endl;
    cout << l->toString() << endl;

    cout << "ADD AFTER REMOVE ITEM " << endl;
    for (int i=8;i<16;i++)
    {
        cout << "Add at index: " << i-8 << endl;
        cout << "Before add: " << l->toString() << endl;
        l->add(i-8,i*i);
        cout << "After add: " << l->toString() << endl;
    }

    l->clear();
    cout << l->toString() << endl;
    l->add(10);
    l->add(15);
    l->add(2);
    l->add(6);
    l->add(4);
    l->add(7);
    l->add(40);
    l->add(8);
    cout << l->toString() << endl;
    cout << l->empty() << endl;
    l->empty() ? cout << "is empty" << endl : cout << "not empty " << endl;
    cout << l->size() << endl;

    DLinkedList<int>::Iterator it = l->begin();
    for (it ; it != l->end(); it++)
    {   
        if(*it > 9) cout << *it << endl;
    }
    l->clear();
    cout << l->toString() << endl;

    l->add(10);
    l->add(15);
    l->add(2);
    l->add(6);
    l->add(4);
    l->add(7);
    l->add(40);
    l->add(8);


    it = l->begin();
    for (it ; it != l->end(); it++)
    {   
        if(*it > 9) cout << *it << endl;
    }
    cout << l->toString() << endl;

    l->dump();
    delete l;
    /*
    while (1)
    {
        srand(time(NULL));
        int n =100;
        int *data= new int[n];
        for (int i = 0; i < n; i++)
        {
            data[i]= rand() %100;
        }
        vector<int>a;
        
        for (int i = 0; i < n; i++)
        {
            a.push_back(data[i]);
        }
        DLinkedList<int>* l = new DLinkedList<int>();
        for (int i = 0; i < n; i++)
        {
            l->add(data[i]);
        }

        //remove before run test
        delete l;delete data;break;

        ////////[ TEST CLEAR ]
        ////////[ WORK ]
        // l->clear();
        // a.clear();
        // l->dump();
        // cout << a.size() << endl;
        // break;

        ////////[ TEST INDEX_OF, CONTAINS ]
        ////////[ WORK ]

        // if(l->indexOf(data[77]) == getIndex(a,data[77])) cout << "success";
        // else cout << "fail";
        // break;

        ////////[ TEST REMOVE_ITEM ]
        ////////[ WORK ]
        
        // for (int i = 0; i < 12; i++)
        // {
        //     a.erase(a.begin()+i);
        //     l->removeItem(data[i]);
        //     cout << "remove: " << data[i] << "[SUCCESS]" <<endl;
        // }
        // if((a.at(0) == l->get(0)) && (a.at(1) == l->get(1)))
        // {
        //     cout << "OK" << endl << endl;
        //     cout << "size of vector: " << a.size() << endl;
        //     for(int i=0; i < a.size(); i++)
        //         cout << a.at(i) << ' ';
        //     cout << endl;
        //     l->dump();
        //     delete[] data;
        //     delete l;
        //     break;
        // }
        // else
        // {
		// 	cout << "Wrong" << endl << a.at(0) << " != " << l->get(0) << endl;
        //     cout << "Wrong2" << endl <<a.at(1) << " != " << l->get(1) << endl;
        //     cout << "size of vector: " << a.size() << endl;
        //     for(int i=0; i < a.size(); i++)
        //         cout << a.at(i) << ' ';
        //     cout << endl;
        //     l->dump();
        //     delete[] data;
        //     delete l;
        //     break;
		// }
        

        ////////[ TEST REMOVE_AT ]
        ////////[ WORK ]
        // //erase the 7th index <a.begin()= index 0>
       
        // a.erase(a.begin()+7);        
        // cout << "remove: " << l->removeAt(7) << endl;

        // if((a.at(7) == l->get(7)) && (a.at(6) == l->get(6)))
        // {
        //     cout << "OK" << endl;
        //     // cout << "size of vector: " << a.size() << endl;
        //     // for(int i=0; i < a.size(); i++)
        //     //     cout << a.at(i) << ' ';
        //     // l->dump();
        //     // delete[] data;
        //     // delete l;
        //     // break;
        // }
        // else
        // {
		// 	cout << "Wrong" << endl << a.at(7) << " != " << l->get(7) << endl;
        //     cout << "Wrong2" << endl << a.at(6) << " != " << l->get(6) << endl;
        //     cout << "Wrong3" << endl << a.at(5) << " != " << l->get(5) << endl;
        //     cout << "size of vector: " << a.size() << endl;
        //     for(int i=0; i < a.size(); i++)
        //         cout << a.at(i) << ' ';
        //     l->dump();
        //     delete[] data;
        //     delete l;
        //     break;
		// }




        ////////[ TEST GET ]
        ////////[ WORK ]
        // if(a.at(50) == l->get(50)){
        //     cout << "OK" << endl << endl;
        //     // delete[] data;
        //     // delete l;
        //     // break;
        // }
        // else{
		// 	cout << "Wrong" << endl << a.at(50) << " != " << l->get(50) << endl;
        //     delete[] data;
        //     delete l;
        //     break;
		// }

        ////////[ TEST APPEND, ADD ]
        ////////[ WORK ]

        // for (int i = 0; i < n; i++)
        // {
        //     a.insert(a.begin(),data[i]);
        // }

        // if(a.size() == (l->size())){
        //     cout << "OK" << endl << a.size() << "==" << l->size() << endl;
        //     delete[] data;
        //     delete l;
        //     break;
        // }
        // else
        // {
        //     cout << "Wrong" << endl << a.size() << " != " << l->size() << endl;
        //     delete[] data;
        //     delete l;
        //     break;
        // }
        
    }    
    */
}