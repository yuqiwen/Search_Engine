#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Scorelist.h"

#ifndef LISTNODE_H
#define LISTNODE_H
class listnode
{
    listnode* next;
    int id;     //doc id
    int times;  //how many times to the specific doc
public:
    listnode(int tid):id(tid),times(0){next=NULL;}
    ~listnode();
    void add(int tid);
    int search(int tid);
    int volume();
    void passdocuments(Scorelist* scorelist);
};
#endif