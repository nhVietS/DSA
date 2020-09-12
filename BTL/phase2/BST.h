/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.h
 * Author: LTSACH
 *
 * Created on 20 August 2020, 15:31
 */

#ifndef BST_H
#define BST_H
#include <string>
#include <sstream>

#include "./../phase2/IBST.h"
#include "./../phase2/Stack.h"
#include "./../phase2/Queue.h"
#include "./../phase2/ITreeWalker.h"

// #include "tree/IBST.h"
// #include "tree/ITreeWalker.h"
// #include "stacknqueue/Stack.h"
// #include "stacknqueue/Queue.h"


template<class K, class V>
class BST /*: public IBST<K,V>, public ITreeWalker<V>*/{
public:
    class Node; //forward declaration  
    class Entry; //forward declaration  
protected:
    int count;
    Node* pRoot;
public:
    BST();
    ~BST();
    virtual void add(K key, V value=0);
    virtual V remove(K key);
    virtual V search(K key, bool& found); //return NULL if not found
    virtual int size();
    virtual int height();
    virtual void clear();
    virtual DLinkedList<V> ascendingList();
    virtual DLinkedList<V> descendingList();
    virtual DLinkedList<V> dfs();
    virtual DLinkedList<V> bfs();
    virtual DLinkedList<V> nlr();
    virtual DLinkedList<V> lrn();
    virtual DLinkedList<V> lnr();

    string toString(){
        if(this->pRoot == 0) return "(NULL)";
        else return this->pRoot->toString();
    }
    
    
private:
    Node* add(Node* pRoot, Entry data);
    Node* remove(Node* pRoot, K key, V& retValue);
    V search(Node* pRoot, K key, bool& found);
    int height(Node* pRoot);
    void ascendingList(Node* pRoot, DLinkedList<V>& list);
    void descendingList(Node* pRoot, DLinkedList<V>& list);
    void nlr(Node* pRoot, DLinkedList<V>& list);
    void lrn(Node* pRoot, DLinkedList<V>& list);
    void lnr(Node* pRoot, DLinkedList<V>& list);
    
    static void remove(Node* pRoot){
        if(pRoot == 0) return;
        if(pRoot->pLeft != 0) remove(pRoot->pLeft);
        if(pRoot->pRight != 0) remove(pRoot->pRight);
        delete pRoot;
    }
    
    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
    
public:
    class Entry{
    private:
        K key; //primitive type
        V value; //pointer always
        friend class BST<K, V>;

    public:
        Entry(K key, V value=0){
            this->key = key;
            this->value = value;
        }
        string toString(){
            stringstream entrystr;
            if(this->value != 0){
                entrystr    << "<"
                            << this->key << ","
                            << *(this->value) //value: always point type => de-reference
                            << ">";
            }
            else{
                entrystr    << this->key;
            }
            return entrystr.str();
        }
        bool operator==(Entry rhs){
            return this->key == rhs.key;
        }
    };

    class Node{
    private:
        Entry data;
        Node *pLeft, *pRight;
        friend class BST<K, V>;
    public:
        Node(Entry newdata, Node* pLeft, Node* pRight): data(newdata){
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
        ~Node(){
            if(data.value != 0) delete data.value;
        }
        string toString(){
            stringstream nodestr;
            if((pLeft == 0) && (pRight == 0))
                nodestr << "[" << data.toString() << "]";
            if((pLeft == 0) && (pRight != 0))
                nodestr << " (" 
                        << data.toString() << "[.]" 
                        << pRight->toString()
                        << ")";
            if((pLeft != 0) && (pRight == 0))
                nodestr << " (" 
                        << data.toString() 
                        << pLeft->toString()
                        << "[.]"
                        << ")";
            if((pLeft != 0) && (pRight != 0))
                nodestr << " (" 
                        << data.toString() 
                        << pLeft->toString()
                        << pRight->toString()
                        << ") ";
            return nodestr.str();
        }
    };
};

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template<class K, class V>
BST<K, V>::BST() {
    count = 0;
    pRoot = 0;
}


template<class K, class V>
BST<K, V>::~BST() {
    remove(this->pRoot);
}


template<class K, class V>
void BST<K, V>::add(K key, V value) {
    // YOUR CODE HERE
    Entry data(key, value);
    this->pRoot = add(this->pRoot, data);
	this->count+=1;
    // END: YOUR CODE HERE
}

template<class K, class V>
typename BST<K, V>::Node* BST<K, V>::
add(Node* pRoot, Entry data){
    // YOUR CODE HERE 
    if(pRoot == 0) return new BST<K, V>::Node(data,0,0);
	if(data.key < pRoot->data.key)
		pRoot->pLeft = this->add(pRoot->pLeft, data);
	else
		pRoot->pRight = this->add(pRoot->pRight, data);
	return pRoot;
    // END: YOUR CODE HERE
}

template<class K, class V>
int BST<K, V>::size(){
    // YOUR CODE HERE 
    return count;
    // END: YOUR CODE HERE
}


template<class K, class V>
V BST<K, V>::remove(K key){
    // YOUR CODE HERE 
    V retValue;
    this->pRoot = remove(this->pRoot, key, retValue);
    return retValue;
    // END: YOUR CODE HERE
}


template<class K, class V>
typename BST<K, V>::Node*  BST<K, V>::
remove(Node* pRoot, K key, V& retValue){
    // YOUR CODE HERE 
    return this->pRoot;
    // END: YOUR CODE HERE
}

template<class K, class V>
V BST<K, V>::search(K key, bool& found){
    // YOUR CODE HERE 
    found=false;
	return search(this->pRoot, key, found);
    // END: YOUR CODE HERE
}

template<class K, class V>
V BST<K, V>::search(Node* pRoot, K key, bool& found){
    // YOUR CODE HERE
    
    if (pRoot == NULL){        
        return 0; //???? => return;
    }       
    if (pRoot->data.key == key){
        found = true;
        return pRoot->data.value; //???? => return;
    }
    // Key is greater than root's key 
    if (pRoot->data.key < key) 
       return search(pRoot->pRight, key, found); 
  
    // Key is smaller than root's key 
    return search(pRoot->pLeft, key, found);

    //return NULL if not found

    // END: YOUR CODE HERE
}

template<class K, class V>
int BST<K, V>::height(){
    // YOUR CODE HERE 
    return height(this->pRoot);
    // END: YOUR CODE HERE
}

template<class K, class V>
int BST<K, V>::height(Node* pRoot){
    // YOUR CODE HERE 
    if (pRoot == 0)  
        return 0;
    else
    {  
        /* compute the depth of each subtree */
        int lDepth = height(pRoot->pLeft);  
        int rDepth = height(pRoot->pRight);  
      
        /* use the larger one */
        if (lDepth > rDepth)
            return(lDepth + 1);  
        else
            return(rDepth + 1);  
    }
    // END: YOUR CODE HERE
}
template<class K, class V>
void BST<K, V>::clear(){
    // YOUR CODE HERE 

    // END: YOUR CODE HERE
}

template<class K, class V>
DLinkedList<V> BST<K, V>::ascendingList(){
    // YOUR CODE HERE 
    DLinkedList<V> list;
    return list;
    // END: YOUR CODE HERE
}

template<class K, class V>
void BST<K, V>::ascendingList(Node* pRoot, DLinkedList<V>& list){
    // YOUR CODE HERE 

    // END: YOUR CODE HERE
}

template<class K, class V>
DLinkedList<V> BST<K, V>::descendingList(){
    // YOUR CODE HERE 
    DLinkedList<V> list;
    return list;
    // END: YOUR CODE HERE
}

template<class K, class V>
void BST<K, V>::descendingList(Node* pRoot, DLinkedList<V>& list){
    // YOUR CODE HERE 

    // END: YOUR CODE HERE
}

template<class K, class V>
DLinkedList<V> BST<K, V>::dfs(){
    DLinkedList<V> list;
    Stack<Node*> stack;
    stack.push(pRoot);
    while(!stack.empty()){
        Node* pNode = stack.pop();
        list.add(pNode->data.value);
        if(pNode->pRight != 0) stack.push(pNode->pRight);
        if(pNode->pLeft != 0) stack.push(pNode->pLeft);
    }
    return list;
}

template<class K, class V>
DLinkedList<V> BST<K, V>::bfs(){
    DLinkedList<V> list;
    Queue<Node*> queue;
    queue.push(pRoot);
    while(!queue.empty()){
        Node* pNode = queue.pop();
        list.add(pNode->data.value);
        if(pNode->pLeft != 0) queue.push(pNode->pLeft);
        if(pNode->pRight != 0) queue.push(pNode->pRight);
    }
    return list;
}

template<class K, class V>
DLinkedList<V> BST<K, V>::nlr(){
    DLinkedList<V> list;
    nlr(pRoot, list);
    return list;
}
template<class K, class V>
void BST<K, V>::nlr(Node* pRoot, DLinkedList<V>& list){
    if(pRoot == 0) return;
    list.add(pRoot->data.value);
    nlr(pRoot->pLeft, list);
    nlr(pRoot->pRight, list);
}

template<class K, class V>
DLinkedList<V> BST<K, V>::lrn(){
    DLinkedList<V> list;
    lrn(pRoot, list);
    return list;
}
template<class K, class V>
void BST<K, V>::lrn(Node* pRoot, DLinkedList<V>& list){
    if(pRoot == 0) return;
    lrn(pRoot->pLeft, list);
    lrn(pRoot->pRight, list);
    list.add(pRoot->data.value);
}

template<class K, class V>
DLinkedList<V> BST<K, V>::lnr(){
    DLinkedList<V> list;
    lnr(pRoot, list);
    return list;
}
template<class K, class V>
void BST<K, V>::lnr(Node* pRoot, DLinkedList<V>& list){
    if(pRoot == 0) return;
    lnr(pRoot->pLeft, list);
    list.add(pRoot->data.value);
    lnr(pRoot->pRight, list);
}
#endif /* BST_H */

