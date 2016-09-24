#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phonebook_opt.h"

cabinet* create_table(void)
{
    cabinet* table = malloc(sizeof(cabinet) * MAX_KEY_VALUES);
    //init values in cabinets
    for(int i = 0 ; i < MAX_KEY_VALUES; ++i)
    {
        (table+i)->value = NULL;
        (table+i)->next = NULL;
    }
    return table;
}

/*Has version find*/
entry *findName_Hash(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        //compare regarding case
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append_Hash(char lastName[], entry *e)
{
    /*origin*/
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

/*Origin version*/
entry *findName(char lastname[], entry *pHead)
{
    
    while (pHead != NULL) {
        //compare regarding case
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    /*origin*/
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

unsigned int BKDRHash(char* str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while(*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}
