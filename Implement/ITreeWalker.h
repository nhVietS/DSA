#ifndef ITREEWALKER_H
#define ITREEWALKER_H
#include "DLinkedList.h"

template<class T>
class ItreeWalker{
public:
	virtual DLinkedList<T> dfs()=0;
	virtual DLinkedList<T> bfs()=0;
	virtual DLinkedList<T> nlr()=0;
	virtual DLinkedList<T> lrn()=0;
	virtual DLinkedList<T> lnr()=0;
};
#endif /* ITREEWALKER_H */
