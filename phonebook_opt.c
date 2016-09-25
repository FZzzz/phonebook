#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "phonebook_opt.h"

unsigned int BKDRHash(char* str)
{
    unsigned int seed = 131;
    unsigned int hash = 0;

    while(*str) {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}

cabinet* create_table(void)
{
    cabinet* table = malloc(sizeof(cabinet) * MAX_KEY_VALUES);
    //init values in cabinets
    for(int i = 0 ; i < MAX_KEY_VALUES; ++i) {
        (table+i)->value = NULL;
        (table+i)->next = NULL;
    }

    return table;
}

/*Hash version*/
entry *findName_hash(char lastname[], entry *pHead , cabinet table[])
{
    /*TODO: use key to find*/
    unsigned int hash_value = BKDRHash(lastname);
    unsigned int index = hash_value % MAX_KEY_VALUES;
    if(!table[index].value) {
        return NULL;
    }
    if(strcasecmp(lastname, table[index].value->lastName) == 0) {
        return table[index].value;
    } else {
        cabinet *next_node = table[index].next;
        while(next_node) {
            if(strcasecmp(lastname, next_node->value->lastName) == 0)
                return next_node->value;
            next_node = next_node->next;
        }
        if(!next_node) {
            return NULL;
        }
    }

    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append_hash(char lastName[], entry *e, cabinet table[])
{
    /*origin*/
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    unsigned int hash_value = BKDRHash(lastName);
    unsigned int index = hash_value % MAX_KEY_VALUES;

    if( table[index].value == NULL) {
        table[index].value = e;
    } else {
        cabinet* next_node = table[index].next;
        //assert(next_node && "next_node NULL");
        if(!next_node)
        {
            next_node = malloc(sizeof(cabinet));
            next_node->value = NULL;
            next_node->next = NULL;
        }

        //append next
        while(next_node->value) {
            next_node = next_node->next;
        }
        next_node->next = malloc(sizeof(cabinet));
        next_node->next->value = e;
        next_node->next->next = NULL;
        
    }


    return e;
}

/*Origin version*/
entry *findName(char lastname[], entry *pHead)
{

    while (pHead != NULL) {
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