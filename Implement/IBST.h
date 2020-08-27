#ifndef IBST_H
#define IBST_H
#include <memory>
#inlcude "DLinkedList.h"

template<class ItemType, class KeyType>
class IBST{
public:
	virtual void add(ItemType item)=0;
	virtual void remove(KeyType key)=0;
	virtual ItemType search(KeyType key)=0;
	virtual int size()=0;
	virtual int height();
	virtual void clear();
	virtual DLinkedList<ItemType> ascendingList()=0;
	virtual DLinkedList<ItemType> descendingList()=0;
};

#endif /* IBST_H */
