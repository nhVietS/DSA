#ifndef IBST_H
#define IBST_H
#include <memory>
#include "DLinkedList.h"

template<class ItemType, class KeyType> //item  = value
class IBST{
public:
	virtual void add(KeyType key,ItemType item=0)=0;
	virtual void remove(KeyType key)=0;
	virtual ItemType search(KeyType key, bool &found)=0;
	virtual int size()=0;
	virtual int height();
	virtual void clear();
	virtual DLinkedList<ItemType> ascendingList()=0;
	virtual DLinkedList<ItemType> descendingList()=0;
};

#endif /* IBST_H */
