/*
 * File:   DLinkedList.h
 * Author: LTSACH
 * Editor: duytnb
 *
 * Created on 19 August 2020, 21:21
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "IList.h"

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;


template<class T>
class DLinkedList: IList<T> {
public:
    class Node;
    class Iterator;

protected:
    Node *head;
    Node *tail;
    int count;
    bool (*comparator)(T& lhs, T& rhs);
    void (*removeData)(DLinkedList<T>*);
    string (*item2str)(T&);

public:
    DLinkedList(
            void (*removeData)(DLinkedList<T>*)=0, //function removing user data
            bool (*comparator)(T&, T&)=0, //function comparing two elements
            string (*item2str)(T&)=0); //function converting elements to strings
    virtual ~DLinkedList();
    virtual void    add(T e);
    virtual void    add(int index, T e);
    virtual T       removeAt(int index);
    virtual bool    removeItem(T item, void (*removeItemData)(T)=0);
    virtual bool    empty();
    virtual int     size();
    virtual void    clear();
    virtual T       get(int index);
    virtual int     indexOf(T item);
    virtual bool    contains(T item);
    virtual string  toString();
    virtual void    dump();

    DLinkedList(const DLinkedList<T>& list){
        this->count = 0;
        this->head = new Node();
        this->tail = new Node();
        this->head->next = this->tail; this->tail->next = 0;
        this->tail->prev = this->head; this->head->prev = 0;

        //copy
        this->removeData = list.removeData;
        this->comparator = list.comparator;
        this->item2str = list.item2str;

        Node* ptr= list.head->next;
        while(ptr != list.tail){
            this->add(ptr->data);
            ptr = ptr->next;
        }
    }
    void setItem2Str(string (*item2str)(T&)){
        this->item2str = item2str;
    }
    static void free(DLinkedList<T> *list){
        typename DLinkedList<T>::Iterator it = list->begin();
        while(it != list->end()){
            delete *it;
            it++;
        }
    }

    //public methods, simple implementation
    Iterator begin(){
        return Iterator(this, true);
    }
    Iterator end(){
        return Iterator(this, false);
    }

private:
    static bool equals(T& lhs, T& rhs, bool (*comparator)(T&, T& )){
        if(comparator == 0) return lhs == rhs;
        else return comparator(lhs, rhs);
    }

//////////////////////////////////////////////////////////////////////
////////////////////////  INNER CLASSES DEFNITION ////////////////////
//////////////////////////////////////////////////////////////////////
public:

    class Node{
    private:
        T data;
        Node *next;
        Node *prev;
        friend class DLinkedList<T>;
    public:
        Node(){
            next= 0;
            prev= 0;
        }
        Node(Node* next, Node* prev){
            this->next = next;
            this->prev = prev;
        }
        Node(T data, Node* next, Node* prev){
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

//////////////////////////////////////////////////////////////////////
    class Iterator{
    private:
        DLinkedList<T>* pList;
        Node* pNode;

    public:
        Iterator(DLinkedList<T>* pList=0, bool begin=true){
            if(begin){
                if(pList !=0) this->pNode = pList->head->next;
                else pNode = 0;
            }
            else{
                if(pList !=0) this->pNode = pList->tail;
                else pNode = 0;
            }
            this->pList = pList;
        }

        Iterator& operator=(const Iterator& iterator){
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T)=0){
            pNode->prev->next = pNode->next;
            pNode->next->prev = pNode->prev;
            Node* pNext = pNode->prev; //MUST prev, so iterator++ will go to end
            /*YOUR CODE HERE*/
            /* to do:
             * 1/ remove user data
             * 2/ then, remove node
             */
            if(removeItemData != 0) removeItemData(pNode->data);
            delete pNode;

            pNode = pNext;
            pList->count -= 1;
        }

        T& operator*(){
            return pNode->data;
        }
        bool operator!=(const Iterator& iterator){
            return pNode != iterator.pNode;
        }
        // Prefix ++ overload
        Iterator& operator++(){
            pNode = pNode->next;
            return *this;
        }
        // Postfix ++ overload
        Iterator operator++(int){
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
    };


};
//////////////////////////////////////////////////////////////////////
//Define a shorter name for DLinkedList:

template<class T>
using List = DLinkedList<T>;



//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template<class T>
DLinkedList<T>::DLinkedList(
        void (*removeData)(DLinkedList<T>*),
        bool (*comparator)(T&, T&),
        string (*item2str)(T&)) {
    head = new Node();
    tail = new Node();
    head->next = tail; tail->next = 0;
    tail->prev = head; head->prev = 0;
    count = 0;
    this->comparator = comparator;
    this->removeData = removeData;
    this->item2str = item2str;
}

template<class T>
DLinkedList<T>::~DLinkedList() {
    //Remove user's data
    if(removeData != 0) removeData(this);

    //Remove list's data (i.e. Node)
    if((head != 0) & (tail != 0)){
        Node* ptr = head->next;
        while(ptr != tail){
            Node* next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }
    if(head != 0) delete head;
    if(tail != 0) delete tail;
}

template<class T>
void DLinkedList<T>::add(T e) {
    /*YOUR CODE HERE*/
    /* Append e to the end of list
     * Guideline: use this->tail
     */

     Node* temp = new Node(e,this->tail,this->tail->prev);

     this->tail->prev->next = temp;
     this->tail->prev= temp;
     count++;
     //cout<< "Added"<<e<<endl;

}
template<class T>
void DLinkedList<T>::add(int index, T e) {
    if((index < 0) || (index > count))
        throw std::out_of_range("The index is out of range!");
    /*YOUR CODE HERE*/

    /*
     * 1/ Create a new node (called pNewNode) to contain the input data (e)
     * 2/ Search for the node stay at index - 1
     * 3/ Let pPrev: pointer to the node at (index - 1)
     *    Let pCur: pointer to the node at (index)
     * 4/ Insert pNewNode in-between pPrev and pCur
     * 5/ Change this->tail->prev if needed
     * 6/ Increase this->count by 1
     */
    if (index == count)
    {
        this->add(e);
    }
    else
    {
        Node* pre = head;
        for(int i=0;i<index;i++)
        {
                pre= pre->next;
        }
        Node* cur = pre->next;
        Node* temp = new Node(e,cur,pre);
        cur->prev= temp;
        pre->next = temp;
        count++;
    }
    //if(index==count) this->tail->prev = temp;


}
template<class T>
T DLinkedList<T>::removeAt(int index){
    if((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");

    /*YOUR CODE HERE*/

    /* Guidelines:
     * 1/ Search for pPrev: pointer to node at (index-1)
     * 2/ Detach pCur: pointer to node at (index)
     * 3/ Update this->tail->prev if needed
     * 4/ Decrease this->count
     * 5/ Delete node pointed by pCur
     * 6/ return data contained in pCur (via backup)
     */
    Node* pre= head;
    for(int i=0;i<index;i++){
        pre=pre->next;
    }
    Node* cur = pre->next;
    pre->next = cur->next;
    cur->next->prev = pre;
    if(index==count-1) tail->prev=pre;
    T res = cur->data;
    delete cur;
    count--;
    return res;
    //remove the following lines

}


template<class T>
bool DLinkedList<T>::empty(){
    /*YOUR CODE HERE*/
    return (count == 0); //should remove
}

template<class T>
int DLinkedList<T>::size(){
    /*YOUR CODE HERE*/
    return count; //should remove
}

template<class T>
void DLinkedList<T>::clear(){
    /*YOUR CODE HERE*/
    /*
     * clear:
     *  a/ user data contained in nodes
     *  b/ nodes created by this class (DLinkedList)
     *
     * Guidelines:
     * 1/call this->removeData (func pointer) to remove user data
     * 2/delete nodes except head and tail
     * 3/assign head, tail, count to model an empty list
     */
     if(removeData != 0) removeData(this);
     while(this->count>0) {
        this->removeAt(count-1);
    }
    this->head->next = this->tail; this->tail->next = 0;
    this->tail->prev = this->head; this->head->prev = 0;
}

template<class T>
T DLinkedList<T>::get(int index){
    if((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");
    /*YOUR CODE HERE*/

    /* Guideine:
     * 1/ Search for pCur: the pointer to node at index
     * 2/ Return data contained in pCur
     */

    //remove the following lines
    T ret;
    Node* cur= head->next;
    for(int i=0;i<index;i++){
        cur= cur->next;
    }
    ret = cur->data;
    return ret;

}

template<class T>
int DLinkedList<T>::indexOf(T item){
    /*YOUR CODE HERE*/

    /* Guideine:
     * 1/ Search for the node containing item as its data
     *      if found: return index
     *      REMEMBER: index will be initialed with -1/or 0
     *                and increase when visit next node
     * 2/ not found: return -1
     */
    int index =0;
    Node* cur = head->next;
    while(cur!=tail){
        if(equals(cur->data,item,this->comparator))
                return index;
        cur= cur->next;
        index++;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T)){
    /*YOUR CODE HERE*/

    /* Remove the item given in "item"
     * if found: return true
     * otherwise: return false
     *
     * Guideine:
     * 1/ Search for the node containing item as its data
     *      if found:
     *          a/ detach from double linked list
     *          b/ remove its data if removeData is given
     *
     * 2/ not found: return false
     */
    int index = 0;
    Node* cur = head->next;
    while(cur!=tail){
        if(equals(cur->data,item,this->comparator))
        {
            if(removeItemData != 0) removeItemData(cur->data);
            removeAt(index);
            return true;
        }
        cur= cur->next;
        index++;
    }
    return false;
}


template<class T>
bool DLinkedList<T>::contains(T item){
   /*YOUR CODE HERE*/

   /*
    * Check an item if it is existed in the list
    * if found: return true
    * otherwise: return false
   */
    return (indexOf(item)!=-1);
}

template<class T>
string DLinkedList<T>::toString(){
    stringstream ss;
    if(this->size()==0)
    {
        ss<<"[]";
        return ss.str();
    }
    ss << "[";
    Node* ptr = head->next;
    while(ptr != tail->prev){
        if(this->item2str != 0) ss << this->item2str(ptr->data) << ", ";
        else ss << ptr->data << ",";

        ptr = ptr->next;
    }

    if(count > 0){
        if(this->item2str != 0) ss << this->item2str(ptr->data) << "]";
        else ss << ptr->data << "]";
    }
    else
        ss << "]";
    return ss.str();
}


template<class T>
void DLinkedList<T>::dump(){
    string line(50, '=');
    cout << line << endl;
    cout << "DLinkedList's information:" << endl;
    cout << "item's size: " << sizeof(T) << " (bytes)"<< endl;
    cout << "count: " << count << endl;
    cout << toString() << endl;
    cout << line << endl;
}



#endif /* DLINKEDLIST_H */

