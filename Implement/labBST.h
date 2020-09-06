#ifndef LAB_BST_H
#define LAB_BST_H
#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// key: int, value: string

class BST{
public:
    class Node;
    class Entry;
private:
    int count;
    Node *pRoot;
public:
	BST();
	~BST();
	void add(string data);
	void remove(int key);
private:
    Node* add(Node *pRoot, string data);
	Node* remove(Node *pRoot, int key);
    static void remove(Node *pRoot){
		if(pRoot ==0) return ;
		if(pRoot->pLeft != 0) remove(pRoot->pLeft);
		if(pRoot->pRight != 0) remove(pRoot->pRight);
		delete pRoot;
	}
public:
	class Entry{
	private:
		int key; // primitive type
		string value; //pointer always
		friend class BST;
		
	public:
		Entry(int key, string value=0){ // assign zero to points or primitive type
			this->key=key;
			this->value = value;
		}
    };
    class Node{
	private:
		Entry data;
		Node *pLeft, *pRight;
		friend class BST;
	public:
		Node(Entry newData, Node *pLeft, Node *pRight): data(newData){
			this->pLeft = pLeft;
			this->pRight = pRight;
		}
		~Node(){
			//if(data.value != NULL) delete data.value;
            
		}
    };
public:
    BST()
    {
        this->count =0;
        this->pRoot =0;
    };
    ~BST()
    {
        remove(this->pRoot);
    };
    void add(int key, string value){
        
        pRoot = add(this->pRoot, a);
        count +=1; 
    };
    Node* add(Node * pRoot, Entry data){
	if(pRoot == 0){
        Entry a(key,value);
        return new BST::Node(data,0,0);
    }
	if(data.key < pRoot->data.key)
		pRoot->pLeft = this->add(pRoot->pLeft, data);
	else
		pRoot->pRight = this->add(pRoot->pRight, data);
	return pRoot;
    };
    string remove(int key){
        return this->pRoot = remove(this->pRoot, key);
    };
    bool remove(int key, string& value){
        string backUp = pRoot->data.value;
        if(pRoot == 0) return ;
		if(pRoot->pLeft != 0) remove(pRoot->pLeft);
		if(pRoot->pRight != 0) remove(pRoot->pRight);
        value = backUp;
		delete pRoot;
        
    }
};
/* LAB_BST_H */
#endif 