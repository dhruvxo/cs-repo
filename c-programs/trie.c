#include<stdio.h>
#include<stdlib.h>

typedef struct trie
{
    P
    int isLeaf;
    struct trie *child[26];
}TRIE;

TRIE *create node()
{
    TRIE *temp=malloc(sizeof(TRIE));
    temp->isLeaf=0;
    for(int i=0;i<26;i++)
    temp->child[i]=NULL;
    return temp;
}

void insert(TRIE *root, char *pattern)
{
    TRIE *cur=root;
    while(*pattern)
    {
        if(cur->child[*pattern-'a']==NULL)
        cur->child[*pattern-'a']=createnode();
        cur=cur->child[*pattern-'a'];
        pattern++:
    }
    cur->isLeaf=1;
}

int search(TRIE *root, char *pattern)
{
    TRIE*cur=root;
    while(*pattern)\
    {
      if(cur->child[*pattern-'a']==NULL)
         return 0;
      cur=cur->child[*pattern-'a'];
      pattern++;
    }
    return cur->isLeaf;
}

int main
{
    TRIE *root=createnode();
    insert(root,"desi");
    insert(root,"designer");
    insert(root,"data");
    if(search(root,"desi"))
    printf("desi is present\n");
    else
    printf("Desi isnt present\n");
    if(search(root,"designer\n"))
     printf("designer is present\n");
    else
    printf("designer isnt present\n");
}
    