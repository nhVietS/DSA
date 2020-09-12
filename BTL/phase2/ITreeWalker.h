#ifndef ITREEWALKER_H
#define ITREEWALKER_H
#include "./../phase2/DLinkedList.h"

template<class V>
class ItreeWalker{
public:
	virtual DLinkedList<V> dfs()=0;
	virtual DLinkedList<V> bfs()=0;
	virtual DLinkedList<V> nlr()=0;
	virtual DLinkedList<V> lrn()=0;
	virtual DLinkedList<V> lnr()=0;
};
#endif /* ITREEWALKER_H */
