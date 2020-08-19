#ifndef XARRAYLIST_H
#define XARRAYLIST_H
#include "IList.h"

#include <iostream>
#include <sstream>
#include <type_traits>
using namespace std;

template<class T>
class XArrayList: IList<T> {
public:
	XArrayList();
	virtual ~XArrayList();
	virtual bool add(T e);
	virtual void add(int index, T e);
	virtual T 	 remove(int index);
	virtual bool empty();
	virtual int  size();
	virtual void clear();
	virtual T 	 get(int index);
	virtual string toString();
private:
	void checkIndex(int index){
		if(index < 0 || index >= count)
			throw std::out_of_range("index is out of range");
	}
	void ensureCapacity(int index){
		
	}
private:
	T* data;
	int capacity;
	int count;
};
template<class T>
XArrayList<T>::XArrayList() {
	capacity = 10;
	data = new T[capacity];
	count =0;
}
template<class T>
XArrayList<T>::~XArrayList() {
	if (data != 0) delete []data;
}
template<class T>
bool XArrayList<T>::add(T e) {
	if(count >= capacity){
		cout << "reallocate data {future version}" << endl;
	else{
		data[count] = e;
		count +=1;
	}
	return true;
}
template<class T>
void XArrayList<T>::add(int index, T e) {
	if (index < 0 || index >count ) //illegal
		throw std::out_of_range("the input index is out of range!");
	ensureCapacity[index];
	count +=1;
	if(count == 0){
		data[index]=e;
		return;
	}
	for(int idx=count-1; idx >= index; idx--){
		data[idx+1]= data[idx];
	}
	data[index]=e;
}
template<class T>
T XArrayList<T>::remove(int index) {
	checkIndex(index);
	return data[index];
}
template<class T>
bool XArrayList<T>::empty() {
	return count ==0;	
}
template<class T>
int XArrayList<T>::size() {
	return count;	
}
template<class T>
void XArrayList<T>::clear() {
	this->count =0;
	//clients of XArrayList Must be responsible to delete data item if they are pointers
}
template<class T>
T XArrayList<T>::get(int index) {
	checkIndex(index);
	return data[index];
}

template<class T>
string XArrayList<T>::toString(int index) {
	stringstream ss;
	ss << "[";
	for(int idx =0; idx < size()-1; idx++){
		ss << data[idx] << ",";
	}
	ss << data[size() - 1] <<"]";
	return ss.str();
}

#endif /* XARRAYLIST_H*/
