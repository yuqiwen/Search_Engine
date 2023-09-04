#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include "Trienode.h"
#include "Map.h"
#include "Scorelist.h"
#include "Maxheap.h"
#include "sys/ioctl.h"
#include "unistd.h"
using namespace std;

void search(char* token,Trienode* trie, Mymap* mymap, int k);
void df(Trienode* trie);
int tf(char* token, Trienode* trie);