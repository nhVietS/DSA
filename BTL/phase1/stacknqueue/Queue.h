/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: LTSACH
 *
 * Created on 19 August 2020, 22:33
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "/home/vietskr/Desktop/DSA/BTL/phase1/list/DLinkedList.h" 
//#include "list/DLinkedList.h"
#include "IDeck.h"

template<class T>
class Queue: public IDeck<T>{
public:
    class Iterator; //forward declaration
    
protected:
    // Guidelines: You can use other list if you cannot complete the DLinkedList
    DLinkedList<T> list; 
    void (*removeData)(DLinkedList<T>*);
    bool (*comparator)(T& lhs, T& rhs);
    
public:
    Queue(
            void (*removeData)(DLinkedList<T>*)=0, 
            bool (*comparator)(T&, T&)=0){
        this->comparator = comparator;
        this->removeData = removeData;
    }
    void push(T item){
        /* YOUR CODE HERE */

        /* 
         * Task: Push an item into the rear of the queue
         * Guidelines:
         * Use your own methods implemented in other list
         */
        list.add(item); // queue opposite side is used
    }
    T pop(){
        /* YOUR CODE HERE */

        /* 
         * Task: Pop an item from the queue
         * Guidelines:
         * Use your own methods implemented in other list
         */
        return list.removeAt(0);
    }
    T peek(){
        /* YOUR CODE HERE */

        /* 
         * Task: Get an item at the front of the queue
         * Guidelines:
         * Use your own methods implemented in other list
         */
        return list.get(0);
    }
    bool empty(){
        /* YOUR CODE HERE */

        /* 
         * Task: Check if your queue is empty
         * Guidelines:
         * Use your own methods implemented in other list
         */
        return list.empty();
    }
    int size(){
        /* YOUR CODE HERE */

        /* 
         * Task: Get the size of the queue
         * Guidelines:
         * Use your own methods implemented in other list
         */
        return list.size();
    }
    void clear(){
        /* YOUR CODE HERE */

        /* 
         * Task: Make the queue empty by removing all elements
         * Guidelines:
         * Use your own methods implemented in other list
         */
        return list.clear();
    }
    bool remove(T item){
        /* YOUR CODE HERE */

        /* 
         * Task: Remove an item with value (in parameter) from the queue
         * Guidelines:
         * Use your own methods implemented in other list
         */
        int index = this->list.indexOf(item);
		if(index != -1){
			this->list.removeAt(index);
			return true;
		}
		else return false;
        //return list.removeItem(item);
    }
    bool contains(T item){
        bool found = false;
        
        /* YOUR CODE HERE */

        /* 
         * Task: Check whether the queue contains this specific item
         * Guidelines:
         * Use your own methods implemented in other list
         */
        typename DLinkedList<T>::Iterator it = list.begin();
		while(it != list.end()){
			found = equals(*it, item, this->comparator);
			if(found) break;
			it++;
		}
		
        return found;
        //return list.contains(item);
    }
    
    Iterator front(){
        return Iterator(this, true);
    }
    Iterator rear(){
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
//Iterator: BEGIN
    class Iterator{
    private:
        Queue<T>* queue;
        typename DLinkedList<T>::Iterator listIt;
    public:
        Iterator(Queue<T>* queue=0, bool begin=true){
            this->queue = queue;
            if(begin){
                if(queue != 0) this->listIt = queue->list.begin();
                else this->listIt = 0;
            }
            else{
                if(queue != 0) this->listIt = queue->list.end();
                else this->listIt = 0;
            }
        }
        Iterator& operator=(const Iterator& iterator ){
            this->queue = iterator.queue;
            this->listIt = iterator.listIt;
            return *this;
        }
        
        T& operator*(){
            return *(this->listIt);
        }
        bool operator!=(const Iterator& iterator){
            return this->listIt != iterator.listIt;
        }
        // Prefix ++ overload 
        Iterator& operator++(){
            listIt++;
            return *this; 
        }
        // Postfix ++ overload 
        Iterator operator++(int){
            Iterator iterator = *this; 
            ++*this; 
            return iterator; 
        }
        void remove(void (*removeItem)(T)=0){
            listIt.remove(removeItem); // is it means removeAt here???
        }
    };
    //Iterator: END
};


#endif /* QUEUE_H */

