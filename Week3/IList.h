#ifndef ILIST_H
#define ILIST_H
#include <string>
using namespace std;

template<class T> class IList{
public:
	virtual bool add(T e)=0;
	virtual void add(int index, T e)=0;
	virtual T	 remove(int index)=0;
	virtual bool empty()=0;
	virtual int  size()=0;
	virtual void clear()=0;
	virtual T	 get(int index)=0;
	virtual string toString()=0;
};
#endif /* ILIST_H*/
