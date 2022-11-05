#ifndef MyStack_H__
#define MyStack_H__

#include "MyVecNewIterator.h"

template<class T>
class MyStack {
public:
	void push(const T&el) {
		if(this->empty()) min = el ;
		else{
			if(el<min) min = el ;
		}
		vec.push_back(el);}
	const T & top() const { return vec[ vec.size()-1]; }
	void pop() { vec.pop_back(); }
	bool empty() const { return vec.empty(); }
	int size() const { return vec.size(); }
	T getMin() const {
		return min;
	}
private:
	MyVec<T> vec;
	T min;
};


#endif