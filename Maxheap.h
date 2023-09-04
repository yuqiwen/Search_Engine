#include <iostream>
#include <cstdlib>
#include <cstring>

#ifndef MAXHEAP_H
#define MAXHEAP_H
class Maxheap
{
    double* heap;
    int* ids;
    int curnumofscores;
    int maxnumofscores;
    void swapscores(int idx1, int idx2);
    int minidx(int low, int high);
public:
    Maxheap(int k);
    ~Maxheap(){free(heap);free(ids);};
    void insert(double score, int id);
    int MaxChild(int numer1, int number2);
    double remove();
    int getid(){return ids[0];};

};
#endif