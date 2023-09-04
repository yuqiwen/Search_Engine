#include <iostream>
#include "Map.h"
#include "Trienode.h"

int read_sizes(int *linecounter, int *maxlength, char *docfile);
int read_input(Mymap *mymap, Trienode *trie, char *docfile);