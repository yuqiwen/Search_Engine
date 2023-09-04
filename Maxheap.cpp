#include "Maxheap.h"
using namespace std;

Maxheap::Maxheap(int k):maxnumofscores(k),curnumofscores(0)
{
    heap=(double*)malloc(maxnumofscores*sizeof(double));
    ids=(int*)malloc(maxnumofscores*sizeof(int));
}

int Maxheap::minidx(int low, int high)
{
    int min=-1;
    double minscore=1000000.0;
    for(int i=low;i<high;i++)
    {
        if(heap[i]<minscore)
        {
            min=i;
            minscore=heap[i];
        }
    }
    return min;
}

void Maxheap::swapscores(int idx1, int idx2)
{
    double temp=0.0;
    temp=heap[idx1];
    int tempid=ids[idx1];
    heap[idx1]=heap[idx2];
    heap[idx2]=temp;
    ids[idx1]=ids[idx2];
    ids[idx2]=tempid;
    return;
}

void Maxheap::insert(double score, int id)
{
    int idx;
    if(curnumofscores!=maxnumofscores)
    {
        idx = curnumofscores;
        curnumofscores++;
    }
    else
    {
        int tidx=minidx(maxnumofscores/2,maxnumofscores);
        if(score>heap[tidx])idx=tidx;
        else return;
    }
    heap[idx]=score;
    ids[idx]=id;
    while(heap[idx]>heap[(idx-1)/2])
    {
        swapscores(idx,(idx-1)/2);
        idx=(idx-1)/2;
    }
}

int Maxheap::MaxChild(int num1, int num2)
{
    if(num1<curnumofscores && num2<curnumofscores)
    {
        if(heap[num1]>heap[num2])return num1;
        else return num2;
    }
    else if(num1<curnumofscores)return num1;
    else if(num2<curnumofscores)return num2;
    return -1;
}

double Maxheap::remove()
{
    int idx=0,Chosenchild;
    double ret;
    if(curnumofscores>0)
    {
        ret=heap[0];
        curnumofscores--;
        heap[0]=heap[curnumofscores];
        ids[0]=ids[curnumofscores];
        while(1)
        {
            Chosenchild=MaxChild(2*idx+1,2*idx+2);
            if(Chosenchild!=-1 && heap[Chosenchild]>heap[idx])
            {
                swapscores(Chosenchild,idx);
                idx=Chosenchild;
            }
            else break;
        }
    }
    return ret;
}