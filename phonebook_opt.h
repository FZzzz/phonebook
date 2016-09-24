#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define MAX_KEY_VALUES 1024
/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1
typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} phonebook_detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    phonebook_detail* detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __CABINET {
    entry* value;
    entry* next;
} cabinet;

cabinet* create_table(void);

entry *findName(char lastname[], entry *pHead);
entry *append(char lastName[], entry *e);
entry *findName_Hash(char lastname[], entry *pHead , cabinet* table);
entry *append_Hash(char lastName[], entry *e , cabinet* table);
unsigned int BKDRHash(char* str);


#endif
