#include "Trienode.h"

Trienode::Trienode():value(-1)
{
    sibling=NULL;
    child=NULL;
    list=NULL;
}

Trienode::~Trienode()
{
    if(list!=NULL)
    {
        delete(list);
    }
    if(child!=NULL)
    {
        delete(child);
    }
    if(sibling!=NULL)
    {
        delete(sibling);
    }
}

void Trienode::insert(char* token, int id)
{
    if(value==-1 || value==token[0])
    {
        value=token[0];
        if(strlen(token)==1)
        {
            if(list==NULL)
            {
                list=new listnode(id);
            }
            list->add(id);
        }
        else
        {
            if(child==NULL)
            {
                child=new Trienode();
            }
            child->insert(token+1,id);
        }
    }
    else
    {
        if(sibling==NULL)
        {
            sibling=new Trienode();
        }
        sibling->insert(token, id);
    }
}

int Trienode::tfsearchword(int id, char* word, int curr)
{
    if(word[curr]==value)
    {
        if(curr==strlen(word)-1)
        {
            if(list!=NULL)return list->search(id);
            else return 0;
        }
        else
        {
            if(child!=NULL)return child->tfsearchword(id,word,curr+1);
            else return 0;
        }
    }
    else
    {
        if(sibling!=NULL)return sibling->tfsearchword(id,word,curr);
        else return 0;
    }
    return 0;
}

int Trienode::dfsearchword(char* word, int curr)
{
    if(word[curr]==value)
    {
        if(curr==strlen(word)-1)
        {
            if(list!=NULL)return list->volume();
            else return 0;
        }
        else
        {
            if(child!=NULL)return child->dfsearchword(word,curr+1);
            else return 0;
        }
    }
    else
    {
        if(sibling!=NULL)return sibling->dfsearchword(word,curr);
        else return 0;
    }
}

void Trienode::dfsearchall(char* buffer, int curr)
{
    buffer[curr]=value;
    if(list!=NULL)cout<<buffer<<" "<<list->volume()<<endl;
    if(child!=NULL)child->dfsearchall(buffer,curr+1);
    if(sibling!=NULL)sibling->dfsearchall(buffer,curr);
    buffer[curr]='\0';

}

void Trienode::search(char* word, int curr, Scorelist* scorelist)
{
    if(word[curr]==value)
    {
        if(curr==strlen(word)-1)
        {
            if(list!=NULL)return list->passdocuments(scorelist);
            else return;
        }
        else
        {
            if(child!=NULL)child->search(word,curr+1,scorelist);
            else return;
        }
    }
    else
    {
        if(sibling!=NULL)sibling->search(word,curr,scorelist);
        else return;
    }
    return;
}