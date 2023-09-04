#include "Scorelist.h"
using namespace std;

Scorelist::~Scorelist()
{
    if(next!=NULL)delete(next);
}

void Scorelist::insert(int tid)
{
    if(id==tid)return;
    if(id==-1)id=tid;
    else 
    {
        if(next==NULL)next=new Scorelist(tid);
        else next->insert(tid);
    }
}
