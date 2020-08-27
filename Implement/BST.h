#ifndef BST_H
#define BST_H
#include "IBST.h"
#include "ITreeWalker.h"
#include <string>
#include <sstream>
#include "stack.h"
#include "queue.h"

template<class KeyType, class ValueType>
class BST/*: public IBST<ValueType, KeyType>, public ITreeWalker<ValueType> */{
public:
	class Node; // forward declaration
	class Entry; // forward declaration
private:
	int count;
	Node* pRoot;
public:
	BST();
	~BST();
	void add(Entry data);
	void remove(KeyType key);
	ValueType search(KeyType key);
	int size();
	int height();
	void clear();
	DLinkedList<ValueType> ascendingList();
	DLinkedList<ValueType> descendingList();
	
	DLinkedList<ValueType> dfs();
	DLinkedList<ValueType> bfs();
	DLinkedList<ValueType> nlr();
	DLinkedList<ValueType> lrn();
	DLinkedList<ValueType> lnr();
	
	string toString(){
		if(this->pRoot == 0) return "(NUL)";
		else return this->pRoot->toString();
	}
private:
	Node* add(Node *pRoot, Entry data);
	Node* remove(Node *pRoot, KeyType key);
	ValueType search (Node *pRoot, KeyType key);
	int height(Node *pRoot);
	void ascendingList(Node *pRoot, DLinkedList<ValueType>& list);
	void descendingList(Node *pRoot, DLinkedList<ValueType>& list);
	void nlr(Node *pRoot, DLinkedList<ValueType>& list);
	void lrn(Node *pRoot, DLinkedList<ValueType>& list);
	void lnr(Node *pRoot, DLinkedList<ValueType>& list);
	
	static void remove(Node *pRoot){
		if(pRoot ==0) return ;
		if(pRoot->pLeft != 0) remove(pRoot->pLeft);
		if(pRoot->pRight != 0) remove(pRoot->pRight);
		delete pRoot;
	}
public:
	class Entry{
	private:
		KeyType key; // primitive type
		ValueType value; //pointer always
		friend class BST<KeyType, ValueType>;
		
	public:
		Entry(KeyType key, ValueType value=0){ // assign zero to points or primitive type
			this->key=key;
			this->value = value;
		}
		string toString(){
			stringstream entrystr;
			if(this->value !=0){
				entrystr << "<"
						 << this->key << ","
						 << *(this->value)
						 << ">";
			}
			else{
				entrystr << this->key;
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
		friend class BST<KeyType, ValueType>;
	public:
		Node(Entry newData, Node *pLeft, Node *pRight): data(newData){
			this->pLeft = pLeft;
			this->pRight = pRight;
		}
		~Node(){
			if(data.value !=0) delete data.value;
		}
		string toString(){ // [] leaf node, ()
			stringstream nodestr;
			if(pLeft ==0 && pRight ==0)
				nodestr << "[" << data.toString() << "]";
			if(pLeft ==0 && pRight !=0)
				nodestr << "(" << data.toString() << "[.]" 
				<< pRight->toString() << ")";
			if(pLeft !=0 && pRight ==0)
				nodestr << "(" << data.toString()<< pLeft->toString() 
				<< "[.]" << ")";
			if(pLeft !=0 && pRight !=0)
			nodestr << "(" << data.toString() << pLeft->toString() << pRight->toString() << ") ";
			return nodestr.str();
		}
};

template<class KeyType, class ValueType>
BST<KeyType, ValueType>::BST(){
	count =0;
	pRoot =0;
}

template<class KeyType, class ValueType>
BST<KeyType, ValueType>::~BST(){
	remove(this->pRoot);
}

template<class KeyType, class ValueType>
void BST<KeyType, ValueType>::add(Entry data){
	this->pRoot = add(this->pRoot, data);
	this->count+=1;
}

template<class KeyType, class ValueType>
typename BST<KeyType, ValueType>::Node* BST<KeyType, ValueType>::
add(Node * pRoot, Entry data){
	if(pRoot == 0) return new BST<KeyType, ValueType>::Node(data,0,0);
	if(data.key < pRoot->data.key)
		pRoot->pLeft = this->add(pRoot->pLeft, data);
	else
		pRoot->pRight = this->add(pRoot->pRight, data);
	return pRoot;
}
template<class KeyType, class ValueType>
int BST<KeyType, ValueType>::Size(){
	return count;
}
template<class KeyType, class ValueType>
void BST<KeyType, ValueType>::remove(KeyType key){
	this->pRoot = remove(this->pRoot, key);
}
// to use 
/*typedef BST<int, int*>::Entry Entry;
 * BST<int, int*> tree;
 */
