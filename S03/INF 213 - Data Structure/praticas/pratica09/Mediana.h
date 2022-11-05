#ifndef MEDIANA_R_H
#define MEDIANA_R_H

#include <iostream>
#include "MyPriorityQueue.h"
using namespace std;


class Mediana {
public:
	void insere(int el);
	int getMediana();

private:
    void checkSize();
	MyPriorityQueue<int> menores;
    MyPriorityQueue<int> maiores;
};

#endif