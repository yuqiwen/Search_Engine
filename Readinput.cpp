#include "Readinput.h"
using namespace std;

int read_sizes(int *linecounter, int *maxlength, char *docfile){
    FILE* file=fopen(docfile,"r");
    if(file == NULL){
        cout<<"Error opening file"<<endl;
        return -1;
    } 
    char *line=NULL;
    size_t falsebuffer=0;
    int currlength;
    while(-1!=(currlength=getline(&line,&falsebuffer,file))){
        if(*maxlength<currlength)*maxlength=currlength;
        (*linecounter)++;
        free(line);
        line=NULL;
        falsebuffer=0;
    }
    fclose(file);
    free(line);
    if(*linecounter==0||*maxlength<6){
        cout<<"Document is too empty, does not meet requirements"<<endl;
        return -1;
    }
    return 1;
}
void split(char* temp, int id ,Trienode* trie, Mymap* mymap)
{
    char* token;
    token=strtok(temp," \t");
    int i=0;
    while(token!=NULL){
        i++;
        trie->insert(token,id);
        token=strtok(NULL," \t");
    }
    mymap->setlength(id,i);
    free(token);
    
}
int read_input(Mymap* mymap,Trienode* trie, char* docfile){
    FILE* file =fopen(docfile,"r");
    char* line=NULL;
    size_t falsebuffer=0;
    int currlength;
    char* temp=(char*)malloc(mymap->getbuffersize()*sizeof(char));
    for(int i=0;i<mymap->getsize();i++)
    {
        getline(&line,&falsebuffer,file);
        if(mymap->insert(line,i)==-1)
        {
            cout<<"Doc does not meet the requirement"<<endl;
            fclose(file);
            free(line);
            free(temp);
            return -1;
        }
        strcpy(temp,mymap->getDocument(i));
        split(temp,i,trie,mymap);
        free(line);
        line=NULL;
        falsebuffer=0;
    }
    fclose(file);
    free(temp);
    return 1;
}