#ifndef ILIST_H
#define ILIST_H
#include <string>
using namespace std;
/*
 * this is the list ADT
 */
template class<T>
class ICompare{
	
}
template<class T> class IList{
public:
	class Iterator;
	DLinkedList(void (*removeData)(DLinkedList<T>*)=0); 
	virtual bool add(T e)=0;
	virtual void add(int index, T e)=0;
	virtual T	 remove(int index)=0;
	virtual bool empty()=0;
	virtual int  size()=0;
	virtual void clear()=0;
	virtual int  indexOf(T item) =0;
	virtual bool contains(T item)=0;
	virtual T	 get(int index)=0;
	virtual string toString()=0;
};
#endif /* ILIST_H*/
