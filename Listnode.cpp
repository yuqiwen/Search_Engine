#include "Listnode.h"

listnode::~listnode()
{
    if(next!=NULL)
    {
        delete(next);
    }
}

void listnode::add(int tid)
{
    if(tid==id)times++;
    else
    {
        if(next==NULL)
        {
            next=new listnode(tid);
        }
        next->add(tid);
    }
}

int listnode::search(int tid)
{
    if(tid==id)return times;
    else 
    {
        if(next==NULL)return 0;
        else return next->search(tid);
    }
}

int listnode::volume()
{
    if(next!=NULL)return 1+next->volume();
    else return 1;
}

void listnode::passdocuments(Scorelist* scorelist)
{
    scorelist->insert(id);
    if(next!=NULL)next->passdocuments(scorelist);
}