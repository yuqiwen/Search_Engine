#include <iostream>
#include <cstdlib>

#ifndef SCORELIST_H
#define SCORELIST_H
class Scorelist
{
    int id;
    Scorelist* next;
public:
    Scorelist(int tid=-1):id(tid){next=NULL;}
    ~Scorelist();
    void insert(int tid);
    Scorelist* getnext(){return next;};
    int getid(){return id;};
};
#endif